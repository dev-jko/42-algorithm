/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 16:10:19 by jko               #+#    #+#             */
/*   Updated: 2020/03/24 16:19:00 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include <stdlib.h>

typedef struct	s_queue
{
	unsigned int	max_size;
	int		last_index;
	void		**data;
}		t_queue;

t_queue	*queue_init(unsigned int max_size);
int	queue_push(t_queue *queue, void *data);
int	queue_size(t_queue *queue);
void	*queue_front(t_queue *queue);
void	*queue_pop(t_queue *queue);
void	queue_clear(t_queue *queue, void (*free_data)(void *));
void	free_queue(t_queue *queue, void (*free_data)(void *));

#endif
