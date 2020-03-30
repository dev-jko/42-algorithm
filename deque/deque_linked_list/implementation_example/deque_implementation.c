/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_implementation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 18:17:08 by jko               #+#    #+#             */
/*   Updated: 2020/03/30 18:54:52 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

t_deque	*deque_init(void)
{
	t_deque	*deque;

	deque = malloc(sizeof(t_deque));
	if (!deque)
		return (0);
	deque->size = 0;
	deque->front = 0;
	deque->back = 0;
	return (deque);
}

t_node	*create_elem(void *data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->data = data;
	node->next = 0;
	node->prev = 0;
	return (node);
}

int	deque_push_front(t_deque *deque, void *data)
{
	t_node	*new;

	if (!deque || !(new = create_elem(data)))
		return (0);
	new->next = deque->front;
	if (deque_size(deque) == 0)
		deque->back = new;
	else
		deque->front->prev = new;
	deque->front = new;
	deque->size++;
	return (1);
}

int	deque_push_back(t_deque *deque, void *data)
{
	t_node	*new;

	if (!deque || !(new = create_elem(data)))
		return (0);
	new->prev = deque->back;
	if (deque_size(deque) == 0)
		deque->front = new;
	else
		deque->back->next = new;
	deque->back = new;
	deque->size++;
	return (1);
}

int	deque_size(t_deque *deque)
{
	if (!deque)
		return (0);
	return (deque->size);
}

t_node	*deque_front(t_deque *deque)
{
	if (!deque)
		return (0);
	return (deque->front);
}

t_node	*deque_back(t_deque *deque)
{
	if (!deque)
		return (0);
	return (deque->back);
}

t_node	*deque_pop_front(t_deque *deque)
{
	t_node	*node;

	if (!deque || deque_size(deque) == 0)
		return (0);
	node = deque->front;
	deque->front = node->next;
	deque->size--;
	if (deque_size(deque) == 0)
		deque->back = 0;
	else
		deque->front->prev = 0;
	return (node);
}

t_node	*deque_pop_back(t_deque *deque)
{
	t_node	*node;

	if (!deque || deque_size(deque) == 0)
		return (0);
	node = deque->back;
	deque->back = node->prev;
	deque->size--;
	if (deque_size(deque) == 0)
		deque->front = 0;
	else
		deque->back->next = 0;
	return (node);
}

void	deque_clear(t_deque *deque, void (*free_data)(void *))
{
	t_node	*curr;
	t_node	*temp;

	if (!deque || !free_data)
		return ;
	curr = deque->front;
	while (curr)
	{
		temp = curr;
		curr = curr->next;
		free_data(temp->data);
		free(temp);
	}
	deque->size = 0;
	deque->front = 0;
	deque->back = 0;
}

void	free_deque(t_deque *deque, void (*free_data)(void *))
{
	if (!deque || !free_data)
		return ;
	deque_clear(deque, free_data);
	free(deque);
}
