/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 17:59:53 by jko               #+#    #+#             */
/*   Updated: 2020/04/05 19:16:05 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void print_list(t_linked_list *list)
{
	t_node	*curr;
	int	i;

	if (list == 0 || list->size == 0)
		return ;
	curr = list->head;
	i = 0;
	while (i < (int)list->size)
	{
		printf("index %d->data = %s\n", i, curr->data);
		curr = curr->next;
		i++;
	}
}

int	cmp(void *addr1, void *addr2)
{
	return (strcmp((const char *)addr1, (const char *)addr2));
}

void	f(void *addr)
{
	char *str = (char *)addr;
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
}

int main(void)
{
	t_linked_list	*list;
	t_node		*temp;
	int		test_data_size = 200;
	char		*test_data[test_data_size];
	int		test_index[test_data_size];
	int		index;

	index = 0;

	for (int i = 0; i < test_data_size; ++i) {
		test_data[i] = malloc(20);
		sprintf(test_data[i], "str%d", i);
		test_index[i] = -1 * test_data_size / 2 + i;
	}


	if (!(list = list_init()))
	{
		printf("list_init error\n");
		return (-1);
	}
	printf("init list size = %d\n", list_size(list));

	if (!(temp = create_elem(strdup(test_data[0]))))
	{
		printf("create_elem error\n");
		return (-1);
	}
	printf("create_elem->data = %s\n", temp->data);
	printf("temp->prev = %p\n", temp->prev);
	printf("->next = %p\n", temp->next);
	free(temp->data);
	free(temp);

	for (int i = 0; i < 5; ++i) {
		printf("list_add return value = %d, list_size = %d\n", list_add(list, strdup(test_data[index++]), 0), list_size(list));
		print_list(list);
	}

	printf("list_add return value = %d, list_size = %d\n", list_add(list, strdup(test_data[index++]), 5), list_size(list));
	print_list(list);
	printf("list_add return value = %d, list_size = %d\n", list_add(list, strdup(test_data[index++]), 7), list_size(list));
	print_list(list);

	for (int i = 0; i < test_data_size; ++i) {
		printf("list_get index[%d]->data = %s, list_size = %d\n", test_index[i], ((temp = list_get(list, test_index[i])) ? temp->data : "null"), list_size(list));
	}
	print_list(list);
	printf("list_get index[%d]->data = %s, list_size = %d\n", -1, ((temp = list_get(list, -1)) ? temp->data : "null"), list_size(list));
	printf("list_get index[%d]->data = %s, list_size = %d\n", -2, ((temp = list_get(list, -2)) ? temp->data : "null"), list_size(list));
	printf("list_get index[%d]->data = %s, list_size = %d\n", -3, ((temp = list_get(list, -3)) ? temp->data : "null"), list_size(list));
	printf("list_get index[%d]->data = %s, list_size = %d\n", -4, ((temp = list_get(list, -4)) ? temp->data : "null"), list_size(list));
	printf("list_get index[%d]->data = %s, list_size = %d\n", -5, ((temp = list_get(list, -5)) ? temp->data : "null"), list_size(list));
	printf("list_get index[%d]->data = %s, list_size = %d\n", -6, ((temp = list_get(list, -6)) ? temp->data : "null"), list_size(list));
	printf("list_get index[%d]->data = %s, list_size = %d\n", -7, ((temp = list_get(list, -7)) ? temp->data : "null"), list_size(list));

	for (int i = 0; i < 5; ++i) {
		list_move_head_to_prev(list);
		printf("list_move_head_to_prev, list_size = %d\n", list_size(list));
		print_list(list);
	}

	for (int i = 0; i < 5; ++i) {
		list_move_head_to_next(list);
		printf("list_move_head_to_next, list_size = %d\n", list_size(list));
		print_list(list);
	}
	
	for (int i = 0; i < 10; ++i) {
		printf("list_add return value = %d\n", list_add(list, strdup(test_data[index++]), -1));
		print_list(list);
	}

	int find_index;
	for (int i = 0; i < index; ++i) {
		find_index = list_find(list, test_data[i], &cmp);
		if (find_index < 0)
		{
			printf("not found\n");
			continue;
		}
		printf("list_find %s -> index = %d, data = %s\n", test_data[i], find_index, list_get(list, find_index)->data);
	}

	find_index = list_find(list, "abc", &cmp);
	if (find_index < 0)
		printf("not found\n");
	else
		printf("list_find %s -> index = %d, data = %s\n", "abc", find_index, list_get(list, find_index)->data);

	printf("list size = %d\n", list_size(list));
	list_remove(list, test_index[index++], free);
	printf("list_remove, list_size = %d\n", list_size(list));
	print_list(list);
	list_remove(list, test_index[index++], free);
	printf("list_remove, list_size = %d\n", list_size(list));
	print_list(list);

	list_clear(list, free);
	print_list(list);


	for (int i = test_data_size / 7 * 3; i < test_data_size / 7 * 4; ++i) {
		printf("index = %d, list_add return value = %d, list_size = %d\n", test_index[i], list_add(list, strdup(test_data[i]), test_index[i]), list_size(list));
		print_list(list);
	}
	list_clear(list, free);

	for (int i = test_data_size / 7 * 4; i < test_data_size / 7 * 6; ++i) {
		printf("index = %d, list_add return value = %d, list_size = %d\n", test_index[i], list_add(list, strdup(test_data[i]), test_index[i]), list_size(list));
		print_list(list);
	}
	free_list(list, free);


	if (!(list = list_init()))
	{
		printf("list_init error\n");
		return (-1);
	}
	printf("init list size = %d\n", list_size(list));

	for (int i = 0; i < 30; ++i) {
		printf("list_add return value = %d, list_size = %d\n", list_add(list, strdup(test_data[index]), test_index[index]), list_size(list));
		print_list(list);
		index++;
	}

	list_foreach(list, f);	
	print_list(list);
	free_list(list, free);


	for (int i = 0; i < test_data_size; ++i) {
		free(test_data[i]);
	}

	list = 0;
	system("leaks a.out > leaks_result");

	return 0;
}

