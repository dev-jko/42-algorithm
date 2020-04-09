/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 15:49:29 by jko               #+#    #+#             */
/*   Updated: 2020/04/09 16:04:42 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

t_heap	*heap_init(unsigned int max_size, int (*cmp)(void *, void *))
{
		t_heap	*heap;

		if (max_size < 1 || !cmp)
				return (0);
		if (!(heap = malloc(sizeof(t_heap))))
				return (0);
		if (!(heap->data = malloc(sizeof(void *) * (max_size + 1))))
		{
				free(heap);
				return (0);
		}
		heap->max_size = max_size;
		heap->cmp = cmp;
}

int		heap_insert(t_heap *heap, void *data)
{
}

void	*heap_peek(t_heap *heap)
{
}

void	*heap_pop(t_heap *heap)
{
}

void	free_heap(t_heap *heap, void (*free_data)(void *))
{
}
