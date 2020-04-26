/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 16:57:05 by jko               #+#    #+#             */
/*   Updated: 2020/04/26 19:36:21 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prim.h"

static int cmp(void *edge1, void *edge2)
{
	int result;

	if ((result = ((t_edge *)edge1)->cost - ((t_edge *)edge2)->cost))
		return (result);
	if ((result = ((t_edge *)edge1)->start - ((t_edge *)edge2)->start))
		return (result);
	return (((t_edge *)edge1)->end - ((t_edge *)edge2)->end);
}

static t_edge	*create_edge(uint start, t_node *node)
{
	t_edge	*edge;

	if (!node || !(edge = malloc(sizeof(t_edge))))
		return (0);
	edge->start = start;
	edge->end = node->vertex;
	edge->cost = node->cost;
	return (edge);
}

static bool		push_edges(t_heap *heap, t_node *curr, uint start)
{
	t_edge	*edge;

	if (!heap)
		return (false);
	while (curr)
	{
		if (!(edge = create_edge(start, curr)))
			return (false);
		if (!heap_push(heap, edge))
		{
			free(edge);
			return (false);
		}
		curr = curr->next;
	}
	return (true);
}

static t_heap	*init(const t_graph *graph)
{
	t_heap	*heap;

	if (!graph || !(heap = heap_init(graph->size * (graph->size - 1), cmp)))
		return (0);
	if (!push_edges(heap, graph->list[0], 0))
	{
		free_heap(heap, free);
		return (0);
	}
	return (heap);
}

static bool	*init_visited(uint size)
{
	bool	*visited;
	uint	i;

	if (size < 1 || !(visited = malloc(sizeof(bool) * size)))
		return (0);
	visited[0] = true;
	i = 1;
	while (i < size)
	{
		visited[i] = false;
		i++;
	}
	return (visited);
}

static t_graph	*find_mst(const t_graph *src, t_heap *heap, bool *visited)
{
	t_graph	*mst;
	t_edge	*edge;
	uint	i;

	if (!src || !heap || !visited || !(mst = graph_init(src->size)))
		return (0);
	i = 0;
	while (i < src->size && (edge = heap_pop(heap)))
	{
		if (visited[edge->end])
		{
			free(edge);
			continue ;
		}
		if (!graph_set_edge(mst, edge->start, edge->end, true, edge->cost)
				|| !push_edges(heap, src->list[edge->end], edge->end))
		{
			free(edge);
			break ;
		}
		visited[edge->end] = true;
		i++;
		free(edge);
	}
	if (i == src->size - 1)
		return (mst);
	free_graph(mst, free);
	return (0);
}

t_graph	*make_mst(const t_graph *src)
{
	t_graph	*mst;
	t_heap	*heap;
	bool	*visited;

	if (!src || !(heap = init(src)))
		return (0);
	if (!(visited = init_visited(src->size)))
	{
		free_heap(heap, free);
		return (0);
	}
	mst = find_mst(src, heap, visited);
	free_heap(heap, free);
	free(visited);
	return (mst);
}
