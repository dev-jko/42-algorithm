/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kruskal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 22:42:02 by jko               #+#    #+#             */
/*   Updated: 2020/04/26 18:40:13 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kruskal.h"

static int cmp(void *edge1, void *edge2)
{
	return (((t_edge *)edge1)->cost - ((t_edge *)edge2)->cost);
}

static bool	push_edge(t_heap *heap, t_node *node, uint start)
{
	t_edge	*new;

	if (!heap || !node || !(new = malloc(sizeof(t_edge))))
		return (false);
	new->start = start;
	new->end = node->vertex;
	new->cost = node->cost;
	if (heap_push(heap, new))
		return (true);
	free(new);
	return (false);
}

static t_heap	*push_edges(const t_graph *src)
{
	t_heap	*heap;
	t_node	*curr;
	uint	i;

	if (!(heap = heap_init(src->size * (src->size - 1), cmp)))
		return (0);
	i = 0;
	while (i < src->size)
	{
		curr = src->list[i];
		while (curr)
		{
			if (!push_edge(heap, curr, i))
			{
				free_heap(heap, free);
				return (0);
			}
			curr = curr->next;
		}
		i++;
	}
	return (heap);
}

static uint	find_parent(uint *uf, uint index)
{
	if (uf[index] == index)
		return (index);
	return (uf[index] = find_parent(uf, uf[index]));
}

/*
 * find_mst에서 나눠진 함수입니다.
 * 함수 당 30줄 제한을 지키기 위해 억지로 만들었고 일반적인 상황이라면
 * find_mst의 edge를 (t_edge *)타입으로 선언해서 사용한 후 free해주면 됩니다.
 */
static bool	pop(t_heap *heap, t_edge *edge)
{
	t_edge	*temp;

	if (!(temp = heap_pop(heap)))
		return (false);
	edge->start = temp->start;
	edge->end = temp->end;
	edge->cost = temp->cost;
	free(temp);
	return (true);
}

static bool find_mst(t_graph *graph, t_heap *heap)
{
	t_edge	edge;
	uint	*uf;
	uint	i;

	if (!(uf = malloc(sizeof(uint) * graph->size)))
		return (false);
	i = 0;
	while (i < graph->size)
	{
		uf[i] = i;
		i++;
	}
	i = 0;
	while (i < graph->size && pop(heap, &edge))
	{
		if (find_parent(uf, edge.start) == find_parent(uf, edge.end))
			continue ;
		if (!graph_set_edge(graph, edge.start, edge.end, true, edge.cost))
			break ;
		uf[find_parent(uf, edge.start)] = uf[edge.end];
		i++;
	}
	free(uf);
	if (i == graph->size - 1)
		return (true);
	return (false);
}

t_graph *make_mst(const t_graph *src)
{
	t_graph	*mst;
	t_heap	*heap;
	bool	check;

	if (!src || !(mst = graph_init(src->size)))
		return (0);
	if (!(heap = push_edges(src)))
	{
		free_graph(mst, free);
		return (0);
	}
	check = find_mst(mst, heap);
	free_heap(heap, free);
	if (check)
		return (mst);
	free_graph(mst, free);
	return (0);
}
