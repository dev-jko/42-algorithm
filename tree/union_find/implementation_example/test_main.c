/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 16:21:01 by jko               #+#    #+#             */
/*   Updated: 2020/04/13 17:55:07 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "union_find.h"
#include <stdio.h>

void print_nodes(t_node *nodes[20])
{
	for (int i = 0; i < 20; ++i) {
		printf("index[%02d] parent = %2d\n", i, *(int *)find(nodes[i])->data);
	}
	printf("\n");
}

int main(void)
{
	int		data[20];
	t_node	*nodes[20];

	for (int i = 0; i < 20; ++i) {
		data[i] = i;
		nodes[i] = create_elem(&data[i]);
	}

	print_nodes(nodes);

	printf("1, 2 is disjoint = %d\n", is_disjoint(nodes[1], nodes[2]));
	printf("union result root = %d\n", *(int *)union_func(nodes[1], nodes[2])->data);
	printf("1, 2 is disjoint = %d\n", is_disjoint(nodes[1], nodes[2]));
	print_nodes(nodes);

	printf("3, 4 is disjoint = %d\n", is_disjoint(nodes[3], nodes[4]));
	printf("union result root = %d\n", *(int *)union_func(nodes[3], nodes[4])->data);
	printf("3, 4 is disjoint = %d\n", is_disjoint(nodes[3], nodes[4]));
	print_nodes(nodes);
	
	printf("4, 1 is disjoint = %d\n", is_disjoint(nodes[4], nodes[1]));
	printf("union result root = %d\n", *(int *)union_func(nodes[4], nodes[1])->data);
	printf("4, 1 is disjoint = %d\n", is_disjoint(nodes[4], nodes[1]));
	print_nodes(nodes);

	printf("5, 15 is disjoint = %d\n", is_disjoint(nodes[5], nodes[15]));
	printf("union result root = %d\n", *(int *)union_func(nodes[5], nodes[15])->data);
	printf("5, 15 is disjoint = %d\n", is_disjoint(nodes[5], nodes[15]));
	print_nodes(nodes);

	printf("8, 4 is disjoint = %d\n", is_disjoint(nodes[8], nodes[4]));
	printf("union result root = %d\n", *(int *)union_func(nodes[8], nodes[4])->data);
	printf("8, 4 is disjoint = %d\n", is_disjoint(nodes[8], nodes[4]));
	print_nodes(nodes);
	
	printf("8, 15 is disjoint = %d\n", is_disjoint(nodes[8], nodes[15]));
	printf("union result root = %d\n", *(int *)union_func(nodes[8], nodes[15])->data);
	printf("8, 15 is disjoint = %d\n", is_disjoint(nodes[8], nodes[15]));
	print_nodes(nodes);
	
	printf("18, 11 is disjoint = %d\n", is_disjoint(nodes[18], nodes[11]));
	printf("union result root = %d\n", *(int *)union_func(nodes[18], nodes[11])->data);
	printf("18, 11 is disjoint = %d\n", is_disjoint(nodes[18], nodes[11]));
	print_nodes(nodes);


	for (int i = 0; i < 20; ++i) {
		free(nodes[i]);
	}

	system("leaks a.out > leaks_result && cat leaks_result | grep leaked");

	return (0);
}
