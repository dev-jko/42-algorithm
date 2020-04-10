/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_array_implementation.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 00:50:01 by jko               #+#    #+#             */
/*   Updated: 2020/04/10 23:45:33 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack *stack_init(unsigned int max_size)
{
	t_stack *stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == 0)
		return (0);
	stack->max_size = max_size;
	stack->top_index = -1;
	stack->data = (void **)malloc(sizeof(void *) * max_size);
	if (stack->data == 0)
	{
		free(stack);
		return (0);
	}
	return (stack);
}

int	stack_push(t_stack *stack, void *data)
{
	if (stack == 0 || stack->data == 0
			|| (unsigned int)stack->top_index + 1 >= stack->max_size)
		return (0);
	stack->top_index++;
	stack->data[stack->top_index] = data;
	return (1);
}

int	stack_size(t_stack *stack)
{
	if (stack == 0)
		return (0);
	return (stack->top_index + 1);
}

void	*stack_peek(t_stack *stack)
{
	if (stack == 0 || stack->top_index < 0)
		return (0);
	return (stack->data[stack->top_index]);
}

void	*stack_pop(t_stack *stack)
{
	void *result;

	if (stack == 0 || stack->data == 0 || stack->top_index < 0)
		return (0);
	result = stack->data[stack->top_index];
	stack->data[stack->top_index] = 0;
	stack->top_index--;
	return (result);
}

void	stack_clear(t_stack *stack, void (*free_data)(void *))
{
	int i;

	if (stack == 0 || free_data == 0)
		return ;
	i = 0;
	while (i <= stack->top_index)
	{
		free_data(stack->data[i]);
		i++;
	}
	stack->top_index = -1;
}

void	free_stack(t_stack *stack, void (*free_data)(void *))
{
	if (stack == 0 || free_data == 0)
		return ;
	stack_clear(stack, free_data);
	free(stack->data);
}
