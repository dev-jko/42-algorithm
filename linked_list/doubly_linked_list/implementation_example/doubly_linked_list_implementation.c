#include "list.h"
#include <stdlib.h>

t_linked_list	*list_init(void)
{
	t_linked_list *list;

	list = (t_linked_list *)malloc(sizeof(t_linked_list));
	if (list == 0)
		return (0);
	list->head = 0;
	list->tail = 0;
	list->size = 0;
	return (list);
}

t_node		*create_elem(int data)
{
	t_node *new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == 0)
		return (0);
	new_node->data = data;
	new_node->prev = 0;
	new_node->next = 0;
	return (new_node);
}

int		list_size(t_linked_list *list)
{
	if (list == 0)
		return (0);
	return (list->size);
}

t_node		*list_get(t_linked_list *list, int n)
{
	t_node	*curr;
	int	i;

	if (list == 0 || n < 0 || n >= (int)list->size)
		return (0);
	i = 0;
	curr = list->head;
	while (curr)
	{
		if (i == n)
			return (curr);
		i++;
		curr = curr->next;
	}
	return (0);
}

int		list_add_last(t_linked_list *list, int data)
{
	t_node *new;
	t_node *curr;

	if ((new = create_elem(data)) == 0)
		return (-1);
	curr = list->tail;
	if (curr == 0)
		list->head = new;
	else
	{
		new->prev = curr;
		curr->next = new;
	}
	list->tail = new;
	list->size++;
	return (list->size - 1);
}

int		list_add(t_linked_list *list, int data, int n)
{
	t_node	*curr;
	t_node	*new;

	if (list == 0 || n < 0)
		return (-1);
	if (n >= (int)list->size)
		return (list_add_last(list, data));
	if ((curr = list_get(list, n)) == 0 || (new = create_elem(data)) == 0)
		return (-1);
	new->next = curr;
	new->prev = curr->prev;
	if (curr->prev == 0)
		list->head = new;
	else
		curr->prev->next = new;
	curr->prev = new;
	list->size++;
	return (n);
}

int		list_remove(t_linked_list *list, int n)
{
	t_node *curr;

	if (list == 0 || n < 0 || n >= (int)list->size)
		return (0);
	if ((curr = list_get(list, n)) == 0)
		return (0);
	list->size--;
	if (curr->prev == 0)
		list->head = curr->next;
	else
		curr->prev->next = curr->next;
	if (curr->next == 0)
		list->tail = curr->prev;
	else
		curr->next->prev = curr->prev;
	free(curr);
	return (1);
}

void		list_clear(t_linked_list *list)
{
	t_node *curr;
	t_node *temp;

	curr = list->head;
	list->head = 0;
	list->tail = 0;
	list->size = 0;
	while (curr)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
	}
}

void		free_list(t_linked_list *list)
{
	list_clear(list);
	free(list);
}


//////////////////////////////////////////////////////////////////////////////////


/*
#include <stdio.h>

void print_list(t_linked_list *list)
{
	t_node *curr = list->head;
	int i = 0;
	while (curr)
	{
		printf("index %d -> %d\n", i, curr->data);
		i++;
		curr = curr->next;
	}
	printf("\n");
}

void print_list_rev(t_linked_list *list)
{
	t_node *curr = list->tail;
	int i = list->size - 1;
	while (curr)
	{
		printf("rev index %d -> %d\n", i, curr->data);
		i--;
		curr = curr->prev;
	}
	printf("\n");
}

int main(void)
{
	t_linked_list *list = list_init();

	int i = 0;
	list_add(list, i++, 0);
	print_list(list);
	list_add(list, i++, 0);
	print_list(list);
	list_add(list, i++, 12421321);
	print_list(list);
	list_add(list, i++, 3);
	print_list(list);


	list_add(list, i++, 1);
	print_list(list);
	list_add(list, i++, 1);
	print_list(list);

	printf("%d\n", list_get(list, 0)->data);
	printf("%d\n", list_get(list, 1)->data);
	printf("%d\n", list_get(list, 2)->data);
	printf("%d\n", list_get(list, 3)->data);

	list_add(list, i++, 1121242121);
	print_list(list);

	list_add(list, i++, list->size);
	print_list(list);

	list_add(list, i++, 1);
	print_list(list);

	list_add(list, i++, 1);
	print_list(list);

	printf("%d\n", list_remove(list, 0));
	print_list(list);
	print_list_rev(list);
	printf("%d\n", list_remove(list, list->size - 1));
	print_list(list);
	print_list_rev(list);
	printf("%d\n", list_remove(list, 1));
	print_list(list);
	print_list_rev(list);
	printf("%d\n", list_remove(list, 2));
	print_list(list);
	print_list_rev(list);

	list_clear(list);
	list_add(list, 123, 5);
	print_list(list);

	free_list(list);


	system("leaks a.out > leaks_result");
	return (0);
}
*/
