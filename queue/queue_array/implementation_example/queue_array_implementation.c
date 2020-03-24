/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_array_implementation.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 16:09:35 by jko               #+#    #+#             */
/*   Updated: 2020/03/24 16:48:13 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "queue.h"

t_queue	*queue_init(unsigned int max_size)
{
	t_queue	*queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	if (!queue)
		return (0);
	queue->data = (void **)malloc(sizeof(void *) * max_size);
	if (!(queue->data))
	{
		free(queue);
		return (0);
	}
	queue->max_size = max_size;
	queue->last_index = -1;
	return (queue);
}

int	queue_size(t_queue *queue)
{
	if (!queue || queue->last_index < 0)
		return (0);
	return (queue->last_index + 1);
}

int	queue_push(t_queue *queue, void *data)
{
	if (!queue || (unsigned int)queue_size(queue) >= queue->max_size)
		return (0);
	queue->last_index++;
	queue->data[queue->last_index] = data;
	return (1);
}

void	*queue_front(t_queue *queue)
{
	if (!queue || queue_size(queue) < 1)
		return (0);
	return (queue->data[0]);
}

void	*queue_pop(t_queue *queue)
{
	void	*result;
	int	i;

	if (!queue || queue_size(queue) < 1)
		return (0);
	result = queue->data[0];
	i = 0;
	while (i < queue->last_index)
	{
		queue->data[i] = queue->data[i + 1];
		i++;
	}
	queue->last_index--;
	return (result);
}

void	queue_clear(t_queue *queue, void (*free_data)(void *))
{
	if (!queue || !free_data)
		return ;
	while (queue->last_index >= 0)
	{
		free_data(queue->data[queue->last_index]);
		queue->last_index--;
	}
}

void	free_queue(t_queue *queue, void (*free_data)(void *))
{
	if (!queue || !free_data)
		return ;
	queue_clear(queue, free_data);
	free(queue->data);
	free(queue);
}
