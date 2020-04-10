/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 00:48:13 by jko               #+#    #+#             */
/*   Updated: 2020/04/10 23:44:11 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef struct s_stack
{
	unsigned int	max_size;
	int		top_index;
	void		**data;
}		t_stack;

t_stack	*stack_init(unsigned int max_size);
int		stack_push(t_stack *stack, void *data);
void	*stack_pop(t_stack *stack);
int		stack_size(t_stack *stack);
void	*stack_peek(t_stack *stack);
void	stack_clear(t_stack *stack, void (*free_data)(void *));
void	free_stack(t_stack *stack, void (*free_data)(void *));

#endif
