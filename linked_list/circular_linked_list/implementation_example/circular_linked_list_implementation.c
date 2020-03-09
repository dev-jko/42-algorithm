/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_linked_list_implementation.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 20:52:54 by jko               #+#    #+#             */
/*   Updated: 2020/03/09 20:12:13 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

t_linked_list	*list_init(void)
{
	t_linked_list *list;

	list = (t_linked_list *)malloc(sizeof(t_linked_list));
	if (list == 0)
		return (0);
	list->size = 0;
	list->head = 0;
	return (list);
}

t_node		*create_elem(void *data)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == 0)
		return (0);
	node->data = data;
	node->prev = 0;
	node->next = 0;
	return (node);
}

int		list_size(t_linked_list *list)
{
	if (list == 0)
		return (0);
	return (list->size);
}

void		list_move_head_to_next(t_linked_list *list)
{
	if (list == 0 || list->head == 0)
		return ;
	list->head = list->head->next;
}

void		list_move_head_to_prev(t_linked_list *list)
{
	if (list == 0 || list->head == 0)
		return ;
	list->head = list->head->prev;
}

static int	calculate_index(unsigned int size, int n)
{
	int temp; 

	if (size == 0)
		return (0);
	if (n >= 0)
		return (n % size);
	temp = (size - n) % size * -1;
	return (temp == 0 ? -size : temp);
}

static t_node	*move_node(t_node *curr, int direction)
{
	if (curr == 0 || direction == 0)
		return (curr);
	if (direction > 0)
		return (curr->next);
	return (curr->prev);
}

t_node		*list_get(t_linked_list *list, int n)
{
	t_node	*curr;
	int	direction;

	if (list == 0)
		return (0);
	direction = 1;
	if ((n = calculate_index(list->size, n)) < 0)
		direction = -1;
	curr = list->head;
	while (n)
	{
		curr = move_node(curr, n);
		n -= direction;
	}
	return (curr);
}

static int	insert_prev(t_linked_list *list, t_node *curr, void *data, int index)
{
	t_node	*new;

	if (list == 0 || (new = create_elem(data)) == 0)
		return (-1);
	list->size++;
	new->prev = curr->prev;
	curr->prev->next = new;
	new->next = curr;
	curr->prev = new;
	return (index != 0 ? index : list->size - 1);
}

static int	insert_next(t_linked_list *list, t_node *curr, void *data, int index)
{
	t_node	*new;

	if (list == 0 || (new = create_elem(data)) == 0)
		return (-1);
	list->size++;
	new->next = curr->next;
	curr->next->prev = new;
	new->prev = curr;
	curr->next = new;
	return (index != 0 ? index : list->size - 1);
}

int		list_add_last(t_linked_list *list, void *data)
{
	t_node *new;

	if (list == 0)
		return (-1);
	if (list->size > 0)
		return (insert_prev(list, list->head, data, list->size));
	if ((new = create_elem(data)) == 0)
		return (-1);
	list->size++;
	list->head = new;
	new->prev = new;
	new->next = new;
	return (0);
}

int		list_add(t_linked_list *list, void *data, int n)
{
	t_node	*curr;

	if (list == 0)
		return (-1);
	if ((curr = list_get(list, n)) == 0)
		return (list_add_last(list, data));
	if ((n = calculate_index(list->size, n)) < 0)
	{
		return (insert_next(list, curr, data, list->size + n + 1));
	}
	return (insert_prev(list, curr, data, n));
}

int		list_find(t_linked_list *list, void* data, int (*cmp)(void *data1, void *data2))
{
	t_node		*curr;
	unsigned int	i;

	if (list == 0 || cmp == 0 || (curr = list->head) == 0)
		return (-1);
	i = 0;
	while (i < list->size)
	{
		if (cmp(curr->data, data) == 0)
			return (i);
		i++;
		curr = curr->next;
	}
	return (-1);
}

void		list_remove(t_linked_list *list, int n, void (*free_data)(void *))
{
	t_node	*curr;

	if (list == 0 || free_data == 0 || (curr = list_get(list, n)) == 0)
		return ;
	if (curr == list->head)
		list->head = curr->next;
	curr->prev->next = curr->next;
	curr->next->prev = curr->prev;
	list->size--;
	free_data(curr->data);
	free(curr);
}

void		list_clear(t_linked_list *list, void (*free_data)(void *))
{
	t_node	*curr;
	t_node	*temp;
	int	i;

	if (list == 0 || free_data == 0 || list->size == 0)
		return ;
	curr = list->head;
	i = 0;
	while (i < (int)list->size)
	{
		temp = curr;
		curr = curr->next;
		free_data(temp->data);
		free(temp);
		i++;
	}
	list->head = 0;
	list->size = 0;
}

void		free_list(t_linked_list *list, void (*free_data)(void *))
{
	if (list == 0 || free_data == 0)
		return ;
	list_clear(list, free_data);
	free(list);
}

void		list_foreach(t_linked_list *list, void (*f)(void *))
{
	t_node	*curr;
	int	i;


	if (list == 0 || f == 0 || (curr = list->head) == 0)
		return ;
	i = 0;
	while (i < (int)list->size)
	{
		f(curr->data);
		curr = curr->next;
		i++;
	}
}
