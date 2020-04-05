/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 18:55:18 by jko               #+#    #+#             */
/*   Updated: 2020/04/05 19:13:49 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	print_deque(t_deque *deque)
{
	if (!deque)
		return ;
	if (deque_size(deque) == 0)
	{
		printf("size = 0, end\n");
		return ;
	}
	int i = 0;
	for (t_node *node = deque_front(deque); node; node = node->next) {
		printf("%d, data = %s\n", i, node->data);
		i++;
	}
}

int main(void)
{
	t_node	*temp;
	t_deque *deque = deque_init();
	printf("size = %d\n", deque_size(deque));
	print_deque(deque);
	
	deque_push_back(deque, strdup("b0"));
	printf("size = %d\n", deque_size(deque));
	print_deque(deque);

	deque_push_back(deque, strdup("b1"));
	printf("size = %d\n", deque_size(deque));
	print_deque(deque);

	deque_push_back(deque, strdup("b2"));
	printf("size = %d\n", deque_size(deque));
	print_deque(deque);

	deque_push_back(deque, strdup("b3"));
	printf("size = %d\n", deque_size(deque));
	print_deque(deque);

	deque_push_back(deque, strdup("b4"));
	printf("size = %d\n", deque_size(deque));
	print_deque(deque);

	deque_push_back(deque, strdup("b5"));
	printf("size = %d\n", deque_size(deque));
	print_deque(deque);

	
	deque_push_front(deque, strdup("f0"));
	printf("size = %d\n", deque_size(deque));
	print_deque(deque);

	deque_push_front(deque, strdup("f1"));
	printf("size = %d\n", deque_size(deque));
	print_deque(deque);

	deque_push_front(deque, strdup("f2"));
	printf("size = %d\n", deque_size(deque));
	print_deque(deque);

	deque_push_front(deque, strdup("f3"));
	printf("size = %d\n", deque_size(deque));
	print_deque(deque);

	deque_push_front(deque, strdup("f4"));
	printf("size = %d\n", deque_size(deque));
	print_deque(deque);

	deque_push_front(deque, strdup("f5"));
	printf("size = %d\n", deque_size(deque));
	print_deque(deque);

	printf("=============== pop ===============\n");
	for (int i = 0; i < 15; i++)
	{
		if (!(i%2))
			temp = deque_pop_front(deque);
		else
			temp = deque_pop_back(deque);
		if (!(i%2))
			printf("pop_front = %s\n", temp ? temp->data : 0);
		else
			printf("pop_back = %s\n", temp ? temp->data : 0);
		free(temp ? temp->data : 0);
		free(temp);
		printf("size = %d\n", deque_size(deque));
	}

	print_deque(deque);
	deque_clear(deque, free);
	print_deque(deque);

	deque_push_front(deque, strdup("f0"));
	printf("size = %d\n", deque_size(deque));
	print_deque(deque);

	deque_push_front(deque, strdup("f1"));
	printf("size = %d\n", deque_size(deque));
	print_deque(deque);
	
	deque_push_back(deque, strdup("b0"));
	printf("size = %d\n", deque_size(deque));
	print_deque(deque);

	deque_push_back(deque, strdup("b1"));
	printf("size = %d\n", deque_size(deque));
	print_deque(deque);
	
	print_deque(deque);
	free_deque(deque, free);
	print_deque(deque);

	deque = 0;
	system("leaks a.out > leaks_result && cat leaks_result | grep leaked");
	return (0);
}
