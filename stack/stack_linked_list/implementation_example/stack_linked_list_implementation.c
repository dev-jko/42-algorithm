/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_linked_list_implementation.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 01:05:04 by jko               #+#    #+#             */
/*   Updated: 2020/04/10 23:47:18 by jko              ###   ########.fr       */
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

	if (stack == 0 || stack->size <= 0)
		return (0);
	stack->size--;
	node = stack->top;
	stack->top = node->next;
	node->next = 0;
	return (node);
}

void	stack_clear(t_stack *stack, void (*free_data)(void *))
{
	t_node *curr;
	t_node *temp;

	if (stack == 0 || free_data == 0)
		return ;
	curr = stack->top;
	stack->top = 0;
	stack->size = 0;
	while (curr)
	{
		temp = curr;
		curr = curr->next;
		free_data(temp->data);
		free(temp);
	}
}

void	free_stack(t_stack *stack, void (*free_data)(void *))
{
	if (stack == 0 || free_data == 0)
		return ;
	stack_clear(stack, free_data);
	free(stack);
}
