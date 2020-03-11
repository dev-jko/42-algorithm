/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_linked_list_implementation.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 01:05:04 by jko               #+#    #+#             */
/*   Updated: 2020/03/12 01:28:02 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"


t_stack	*stack_init(void)
{
	t_stack *stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == 0)
		return (0);
	stack->size = 0;
	stack->top = 0;
	return (stack);
}

t_node	*create_elem(void *data)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == 0)
		return (0);
	node->data = data;
	node->next = 0;
	return (node);
}

int	stack_push(t_stack *stack, void *data)
{
	t_node *new_node;

	if (stack == 0 || (new_node = create_elem(data)) == 0)
		return (0);
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
	return (1);
}

int	stack_size(t_stack *stack)
{
	if (stack == 0)
		return (0);
	return (stack->size);
}

t_node	*stack_peek(t_stack *stack)
{
	if (stack == 0)
		return (0);
	return (stack->top);
}

t_node	*stack_pop(t_stack *stack)
{
	t_node *node;

	if (stack == 0)
		return (0);
	node = stack->top;

	return (node);
}

void	stack_clear(t_stack *stack, void (*free_data)(void *))
{
}

void	free_stack(t_stack *stack, void (*free_data)(void *))
{
}
