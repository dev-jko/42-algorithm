/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 17:05:32 by jko               #+#    #+#             */
/*   Updated: 2020/04/14 17:20:27 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAP_H
# define HEAP_H

# include <stdlib.h>

typedef struct		s_heap
{
	unsigned int	max_size;
	unsigned int	size;
	int				(*cmp)(void *, void *);
	void			**data;
}					t_heap;

int					heap_sort(
		void **items,
		int size,
		int (*cmp)(void *, void *));

#endif
