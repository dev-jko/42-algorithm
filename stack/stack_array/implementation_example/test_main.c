/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 00:50:22 by jko               #+#    #+#             */
/*   Updated: 2020/04/09 17:34:18 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	char *temp;
	t_stack *stack = stack_init(5);
	printf("size = %d\n", stack_size(stack));
	printf("peak->data = %s\n", stack_peak(stack));
	
	stack_push(stack, strdup("aa"));
	printf("size = %d\n", stack_size(stack));
	printf("peak->data = %s\n", stack_peak(stack));

	stack_push(stack, strdup("b"));
	printf("size = %d\n", stack_size(stack));
	printf("peak->data = %s\n", stack_peak(stack));

	stack_push(stack, strdup("ccc"));
	printf("size = %d\n", stack_size(stack));
	printf("peak->data = %s\n", stack_peak(stack));

	stack_push(stack, strdup("ddddd"));
	printf("size = %d\n", stack_size(stack));
	printf("peak->data = %s\n", stack_peak(stack));

	stack_push(stack, strdup("ee"));
	printf("size = %d\n", stack_size(stack));
	printf("peak->data = %s\n", stack_peak(stack));

	temp = strdup("f");
	stack_push(stack, temp);
	printf("size = %d\n", stack_size(stack));
	printf("peak->data = %s\n", stack_peak(stack));
	free(temp);

	printf("=============== pop ===============\n");
	for (int i = 0; i < 9; i++)
	{
		temp = stack_pop(stack);
		printf("pop = %s\n", temp);
		free(temp);
		printf("size = %d\n", stack_size(stack));
		printf("peak->data = %s\n", stack_peak(stack));
	}

	stack_clear(stack, free);

	stack_push(stack, strdup("e22"));
	printf("size = %d\n", stack_size(stack));
	printf("peak->data = %s\n", stack_peak(stack));

	stack_push(stack, strdup("f22"));
	printf("size = %d\n", stack_size(stack));
	printf("peak->data = %s\n", stack_peak(stack));
	
	free_stack(stack, free);

	stack = 0;
	system("leaks a.out > leaks_result; cat leaks_result | grep leaked");
	return (0);
}
