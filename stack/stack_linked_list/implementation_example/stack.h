/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 01:05:16 by jko               #+#    #+#             */
/*   Updated: 2020/04/10 23:46:58 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef struct	s_node
{
	void			*data;
	struct s_node	*next;
}				t_node;

typedef struct	s_stack
{
	unsigned int	size;
	t_node			*top;
}				t_stack;

t_stack	*stack_init(void);
t_node	*create_elem(void *data);
int		stack_push(t_stack *stack, void *data);
int		stack_size(t_stack *stack);
t_node	*stack_peek(t_stack *stack);
t_node	*stack_pop(t_stack *stack);
void	stack_clear(t_stack *stack, void (*free_data)(void *));
void	free_stack(t_stack *stack, void (*free_data)(void *));

#endif
