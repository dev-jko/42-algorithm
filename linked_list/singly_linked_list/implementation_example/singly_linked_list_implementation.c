
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

t_node *create_elem(int data)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == 0)
		return (0);
	node->data = data;
	node->next = 0;
	return (node);
}

int list_add1(t_node **begin_list, int data)
{
	t_node *node;
	t_node *curr;
	int	i;

	if (begin_list == 0 || (node = create_elem(data)) == 0)
		return (-1);
	if (*begin_list == 0)
	{
		*begin_list = node;
		return (0);
	}
	i = 1;
	curr = *begin_list;
	while (curr->next)
	{
		curr = curr->next;
		i++;
	}
	curr->next = node;
	return (i);
}

int list_size(t_node *begin_list)
{
	t_node	*curr;
	int	size;

	curr = begin_list;
	size = 0;
	while (curr)
	{
		curr = curr->next;
		size++;
	}
	return (size);
}

t_node *list_get(t_node *begin_list, int n)
{
	t_node	*curr;
	int	i;

	curr = begin_list;
	i = 0;
	while (curr && i < n)
	{
		curr = curr->next;
		i++;
	}
	if (i != n)
		return (0);
	return (curr);
}

int list_find(t_node *begin_list, int data)
{
	t_node	*curr;
	int	i;

	if (begin_list == 0)
		return (-1);
	i = 0;
	curr = begin_list;
	while (curr)
	{
		if (curr->data == data)
			return (i);
		curr = curr->next;
		i++;
	}
	return (-1);
}

int list_remove(t_node **begin_list, int n)
{
	t_node	*prev;
	t_node	*curr;
	int	i;

	if (begin_list == 0 || *begin_list == 0 || n < 0)
		return (0);
	if (n == 0)
	{
		curr = *begin_list;
		*begin_list = curr->next;
		free(curr);
		return (1);
	}
	prev = *begin_list;
	curr = (*begin_list)->next;
	i = 1;
	while (curr && i < n)
	{
		prev = curr;
		curr = curr->next;
		i++;
	}
	if (i != n || curr == 0)
		return (0);
	prev->next = curr->next;
	free(curr);
	return (1);
}

int list_add(t_node **begin_list, int data, int n)
{
	t_node	*curr;
	t_node	*new_node;
	int	i;

	if (begin_list == 0 || (new_node = create_elem(data)) == 0)
		return (-1);
	if (*begin_list == 0 || n <= 0)
	{
		new_node->next = *begin_list;
		*begin_list = new_node;
		return (0);
	}
	i = 0;
	curr = *begin_list;
	while (curr->next && i < n - 1)
	{
		curr = curr->next;
		i++;
	}
	new_node->next = curr->next;
	curr->next = new_node;
	return (++i);
}

int main(void)
{

	t_node *begin_list = 0;
	printf("size = %d\n", list_size(begin_list));
	list_add1(&begin_list, 0);
	printf("size = %d\n", list_size(begin_list));
	list_add1(&begin_list, 1);
	printf("size = %d\n", list_size(begin_list));
	list_add1(&begin_list, 2);
	printf("size = %d\n", list_size(begin_list));
	list_add1(&begin_list, 3);
	printf("size = %d\n", list_size(begin_list));
	t_node *curr = begin_list;
	for (; curr; curr = curr->next)
	{
		printf("%d\n", curr->data);
	}

	for (int i = -2; i < 5; i++)
	{
		printf("%p\n", list_get(begin_list, i));
	}

	for (int i = -2; i < 6; i++)
	{
		printf("find = %d\n", list_find(begin_list, i));
	}

	printf("remove = %d\n", list_remove(&begin_list, 3));
	curr = begin_list;
	for (; curr; curr = curr->next)
	{
		printf("%d\n", curr->data);
	}

	printf("add -> %d\n", list_add(&begin_list, 10, 5));
	curr = begin_list;
	for (; curr; curr = curr->next)
	{
		printf("%d\n", curr->data);
	}

	return (0);
}
