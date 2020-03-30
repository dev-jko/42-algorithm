/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 18:12:09 by jko               #+#    #+#             */
/*   Updated: 2020/03/30 18:16:43 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H

# include <stdlib.h>

typedef struct	s_node
{
	void		*data;
	struct s_node	*prev;
	struct s_node	*next;
}		t_node;

typedef struct	s_deque
{
	unsigned int	size;
	t_node		*front;
	t_node		*back;
}		t_deque;

t_deque	*deque_init(void);
t_node	*create_elem(void *data);
int	deque_push_front(t_deque *deque, void *data);
int	deque_push_back(t_deque *deque, void *data);
int	deque_size(t_deque *deque);
t_node	*deque_front(t_deque *deque);
t_node	*deque_back(t_deque *deque);
t_node	*deque_pop_front(t_deque *deque);
t_node	*deque_pop_back(t_deque *deque);
void	deque_clear(t_deque *deque, void (*free_data)(void *));
void	free_deque(t_deque *deque, void (*free_data)(void *));

#endif
