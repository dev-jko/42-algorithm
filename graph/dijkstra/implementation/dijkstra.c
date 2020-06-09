/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 18:24:45 by jko               #+#    #+#             */
/*   Updated: 2020/06/09 10:57:54 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dijkstra.h"

static int	cmp(void *path1, void *path2)
{
	int result;

	if ((result = ((t_path *)path1)->cost - ((t_path *)path2)->cost))
		return (result);
	return (((t_path *)path1)->vertex - ((t_path *)path2)->vertex);
}

static uint	*init_result(uint size, uint start)
{
	uint	*result;
	uint	i;

	if (!(result = malloc(sizeof(uint) * size)))
		return (0);
	i = 0;
	while (i < size)
	{
		result[i] = INT_MAX;
		i++;
	}
	result[start] = 0;
	return (result);
}

static t_path	*create_path(uint vertex, uint cost)
{
	t_path	*path;

	if (!(path = malloc(sizeof(t_path))))
		return (0);
	path->vertex = vertex;
	path->cost = cost;
	return path;
}

static bool		push_path(t_heap *heap, uint vertex, uint cost)
{
	t_path	*path;

	if (!(path = create_path(vertex, cost)))
		return (false);
	if (heap_push(heap, path))
		return (true);
	free(path);
	return (false);
}

static bool	dijkstra(const t_graph *src, t_heap *heap, uint *result)
{
	t_path	*path;
	t_node	*node;
	uint	temp;

	while ((path = heap_pop(heap)))
	{
		if (result[path->vertex] < path->cost)
		{
			free(path);
			continue;
		}
		result[path->vertex] = path->cost;
		node = src->list[path->vertex];
		while (node)
		{
			temp = node->cost + path->cost;
			if (temp < (uint)node->cost || temp < path->cost)
				temp = UINT_MAX;
			if (result[node->vertex] > temp)
				if (!push_path(heap, node->vertex, temp))
				{
					free(path);
					return (false);
				}
			node = node->next;
		}
		free(path);
	}
	return (true);
}

static uint	*shortest_path(const t_graph *src, uint start, t_heap *heap)
{
	uint	*result;
	uint	i;

	if (!(result = init_result(src->size, start)))
		return (0);
	i = 0;
	while (i < src->size)
	{
		if (!push_path(heap, i, result[i]))
		{
			free(result);
			return (0);
		}
		i++;
	}
	if (dijkstra(src, heap, result))
		return (result);
	free(result);
	return (0);
}

uint		*find_shortest_path(const t_graph *src, uint start)
{
	uint	*result;
	t_heap	*heap;
	uint	max_edge;

	if (!src || start >= src->size)
		return (0);
	max_edge = src->size * (src->size - 1);
	if (!(heap = heap_init(max_edge, cmp)))
		return (0);
	result = shortest_path(src, start, heap);
	free_heap(heap, free);
	return (result);
}
