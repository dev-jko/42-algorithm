/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 00:50:22 by jko               #+#    #+#             */
/*   Updated: 2020/04/05 19:17:53 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	t_node	*temp;
	t_stack *stack = stack_init();
	printf("size = %d\n", stack_size(stack));
	printf("peek->data = %s\n", stack_peek(stack) ? stack_peek(stack)->data : 0);
	
	stack_push(stack, strdup("aa"));
	printf("size = %d\n", stack_size(stack));
	printf("peek->data = %s\n", stack_peek(stack) ? stack_peek(stack)->data : 0);

	stack_push(stack, strdup("b"));
	printf("size = %d\n", stack_size(stack));
	printf("peek->data = %s\n", stack_peek(stack) ? stack_peek(stack)->data : 0);

	stack_push(stack, strdup("ccc"));
	printf("size = %d\n", stack_size(stack));
	printf("peek->data = %s\n", stack_peek(stack) ? stack_peek(stack)->data : 0);

	stack_push(stack, strdup("ddddd"));
	printf("size = %d\n", stack_size(stack));
	printf("peek->data = %s\n", stack_peek(stack) ? stack_peek(stack)->data : 0);

	stack_push(stack, strdup("ee"));
	printf("size = %d\n", stack_size(stack));
	printf("peek->data = %s\n", stack_peek(stack) ? stack_peek(stack)->data : 0);

	stack_push(stack, strdup("f"));
	printf("size = %d\n", stack_size(stack));
	printf("peek->data = %s\n", stack_peek(stack) ? stack_peek(stack)->data : 0);

	printf("=============== pop ===============\n");
	for (int i = 0; i < 9; i++)
	{
		temp = stack_pop(stack);
		printf("pop = %s\n", temp ? temp->data : 0);
		free(temp ? temp->data : 0);
		free(temp);
		printf("size = %d\n", stack_size(stack));
		printf("peek->data = %s\n", stack_peek(stack) ? stack_peek(stack)->data : 0);
	}

	stack_clear(stack, free);

	stack_push(stack, strdup("e22"));
	printf("size = %d\n", stack_size(stack));
	printf("peek->data = %s\n", stack_peek(stack) ? stack_peek(stack)->data : 0);

	stack_push(stack, strdup("f22"));
	printf("size = %d\n", stack_size(stack));
	printf("peek->data = %s\n", stack_peek(stack) ? stack_peek(stack)->data : 0);
	
	free_stack(stack, free);

	stack = 0;
	system("leaks a.out > leaks_result; cat leaks_result | grep leaked");
	return (0);
}
