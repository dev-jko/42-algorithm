/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 15:49:29 by jko               #+#    #+#             */
/*   Updated: 2020/04/10 23:26:13 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

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
		heap->size = 0;
		return (heap);
}

int		heap_push(t_heap *heap, void *data)
{
		unsigned int	i;
		void			*temp;

		if (!heap || heap->size >= heap->max_size)
				return (0);
		heap->size++;
		i = heap->size;
		heap->data[i] = data;
		while (i / 2 > 0 && heap->data[i / 2] > heap->data[i])
		{
				temp = heap->data[i / 2];
				heap->data[i / 2] = heap->data[i];
				heap->data[i] = temp;
				i /= 2;
		}
		return (1);
}

void	*heap_peek(t_heap *heap)
{
		if (!heap || heap->size < 1)
				return (0);
		return (heap->data[1]);
}

void	*heap_pop(t_heap *heap)
{
		void			*result;
		void			*temp;
		unsigned int	i;
		unsigned int	j;
		unsigned int	k;

		if (!heap || heap->size < 1)
				return (0);
		result = heap->data[1];
		heap->data[1] = heap->data[heap->size--];
		j = 1;
		while ((i = j))
		{
				j = i * 2 <= heap->size && heap->data[i] > heap->data[i * 2];
				k = i * 2 + 1 <= heap->size
						&& heap->data[i] > heap->data[i * 2 + 1];
				if (j && k)
						j = heap->data[i * 2] < heap->data[i * 2 + 1]
								? i * 2 : i * 2 + 1;
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
		return (result);
}

void	free_heap(t_heap *heap, void (*free_data)(void *))
{
		if (!heap || !free_data)
				return ;
		while (heap->size > 0)
		{
				free_data(heap->data[heap->size]);
				heap->size--;
		}
		free(heap->data);
		free(heap);
}
