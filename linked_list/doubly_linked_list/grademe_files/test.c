#include "list.h"
#include <stdio.h>
#include <stdlib.h>


t_linked_list *list_init(void);
t_node *create_elem(int data);
int list_size(t_linked_list *list);
t_node *list_get(t_linked_list *list, int n);
int list_add(t_linked_list *list, int data, int n);
int list_remove(t_linked_list *list, int n);
void list_clear(t_linked_list *list);
void free_list(t_linked_list *list);


void print_list(t_linked_list *list);
void print_list_rev(t_linked_list *list);


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

	list = 0;
	system("leaks a.out > leaks_result");
	return (0);
}


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
