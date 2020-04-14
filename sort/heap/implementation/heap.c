/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 17:07:18 by jko               #+#    #+#             */
/*   Updated: 2020/04/14 17:40:47 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

static 	int	heap_init(t_heap *heap, int max_size, int (*cmp)(void *, void *))
{
		if (!(heap->data = malloc(sizeof(void *) * (max_size + 1))))
				return (0);
		heap->max_size = (unsigned int)max_size;
		heap->cmp = cmp;
		heap->size = 0;
		return (1);
}

static int	heap_push(t_heap *heap, void *data)
{
		unsigned int	i;
		void			*temp;

		if (!heap || heap->size >= heap->max_size)
				return (0);
		heap->size++;
		i = heap->size;
		heap->data[i] = data;
		while (i / 2 > 0 && heap->cmp(heap->data[i / 2], heap->data[i]) > 0)
		{
				temp = heap->data[i / 2];
				heap->data[i / 2] = heap->data[i];
				heap->data[i] = temp;
				i /= 2;
		}
		return (1);
}

static void	fill_node(t_heap *heap)
{
		unsigned int	i;
		unsigned int	j;
		unsigned int	k;
		void			*temp;

		j = 1;
		while ((i = j))
		{
				j = i * 2 <= heap->size &&
						heap->cmp(heap->data[i], heap->data[i * 2]) > 0;
				k = i * 2 + 1 <= heap->size
						&& heap->cmp(heap->data[i], heap->data[i * 2 + 1]) > 0;
				if (j && k)
						j = heap->cmp(heap->data[i * 2], heap->data[i * 2 + 1])
								< 0 ? i * 2 : i * 2 + 1;
				else if (j)
						j = i * 2;
				else if (k)
						j = i * 2 + 1;
				else
						break;
				temp = heap->data[i];
				heap->data[i] = heap->data[j];
				heap->data[j] = temp;
		}
}

static void	*heap_pop(t_heap *heap)
{
		void	*result;

		if (!heap || heap->size < 1)
				return (0);
		result = heap->data[1];
		heap->data[1] = heap->data[heap->size--];
		fill_node(heap);
		return (result);
}

static int	free_heap(t_heap *heap, int return_value)
{
	free(heap->data);
	return (return_value);
}

int			heap_sort(void **items, int size, int (*cmp)(void *, void *))
{
	t_heap	heap;
	int		i;

	if (!items || size < 2 || !cmp || !heap_init(&heap, size, cmp))
		return (0);
	i = 0;
	while (i < size)
	{
		if (!heap_push(&heap, items[i]))
			return (free_heap(&heap, 0));
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (!(items[i] = heap_pop(&heap)))
			return (free_heap(&heap, 0));
		i++;
	}
	return (free_heap(&heap, 1));
}
