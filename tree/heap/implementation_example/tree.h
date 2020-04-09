/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 15:38:49 by jko               #+#    #+#             */
/*   Updated: 2020/04/09 16:05:52 by jko              ###   ########.fr       */
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
int		heap_insert(t_heap *heap, void *data);
void	*heap_peek(t_heap *heap);
void	*heap_pop(t_heap *heap);
void	free_heap(t_heap *heap, void (*free_data)(void *));

#endif
