/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_linked_list_implementation.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 16:09:35 by jko               #+#    #+#             */
/*   Updated: 2020/03/24 17:46:26 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "queue.h"

t_queue	*queue_init(void)
{
	t_queue	*queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	if (!queue)
		return (0);
	queue->size = 0;
	queue->head = 0;
	queue->tail = 0;
	return (queue);
}

t_node	*create_elem(void *data)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->data = data;
	new->next = 0;
	return (new);
}

int	queue_push(t_queue *queue, void *data)
{
	t_node	*new;

	if (!queue || !(new = create_elem(data)))
		return (0);
	if (queue->size == 0)
		queue->head = new;
	else
		queue->tail->next = new;
	queue->tail = new;
	queue->size++;
	return (1);
}

int	queue_size(t_queue *queue)
{
	if (!queue)
		return (0);
	return (queue->size);
}

t_node	*queue_front(t_queue *queue)
{
	if (!queue)
		return (0);
	return (queue->head);
}

t_node	*queue_pop(t_queue *queue)
{
	t_node	*result;

	if (!queue || queue_size(queue) < 1)
		return (0);
	result = queue->head;
	queue->head = result->next;
	if (queue_size(queue) == 1)
		queue->tail = 0;
	queue->size--;
	return (result);
}

void	queue_clear(t_queue *queue, void (*free_data)(void *))
{
	t_node	*curr;
	t_node	*temp;

	if (!queue || !free_data)
		return ;
	curr = queue->head;
	while (curr)
	{
		temp = curr;
		curr = curr->next;
		free_data(temp->data);
		free(temp);
	}
	queue->size = 0;
	queue->head = 0;
	queue->tail = 0;
}

void	free_queue(t_queue *queue, void (*free_data)(void *))
{
	if (!queue || !free_data)
		return ;
	queue_clear(queue, free_data);
	free(queue);
}
