/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 15:38:49 by jko               #+#    #+#             */
/*   Updated: 2020/04/09 17:46:37 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

# include <stdlib.h>

typedef struct	s_heap
{
	unsigned int	max_size;
	unsigned int	size;
	int				(*cmp)(void *, void *);
	void			**data;
}				t_heap;

t_heap	*heap_init(unsigned int max_size, int (*cmp)(void *, void *));
int		heap_push(t_heap *heap, void *data);
void	*heap_peak(t_heap *heap);
void	*heap_pop(t_heap *heap);
void	free_heap(t_heap *heap, void (*free_data)(void *));

#endif
