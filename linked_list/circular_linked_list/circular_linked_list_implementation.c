/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_linked_list_implementation.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 20:52:54 by jko               #+#    #+#             */
/*   Updated: 2020/03/07 22:18:35 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

t_linked_list *list_init(void);
t_node *create_elem(void *data);
int list_add(t_linked_list *list, void *data, int n);
int list_size(t_linked_list *list);
t_node *list_get(t_linked_list *list, int n);
int list_find(t_linked_list *list, void* data, int (*cmp)(void *data1, void *data2));
void list_remove(t_linked_list *list, int n, void (*free_data)(void *));
void list_clear(t_linked_list *list, void (*free_data)(void *));
void free_list(t_linked_list *list, void (*free_data)(void *));
void list_foreach(t_linked_list *list, void (*f)(void *));

int main(int argc, char *argv[])
{
	
	return 0;
}


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

static int	calculate_index(unsigned int size, int n)
{

}

t_node		*list_get(t_linked_list *list, int n)
{
	
}

int		list_add(t_linked_list *list, void *data, int n)
{

}

int		list_find(t_linked_list *list, void* data, int (*cmp)(void *data1, void *data2))
void		list_remove(t_linked_list *list, int n, void (*free_data)(void *))
void		list_clear(t_linked_list *list, void (*free_data)(void *))
void		free_list(t_linked_list *list, void (*free_data)(void *))
void		list_foreach(t_linked_list *list, void (*f)(void *))


