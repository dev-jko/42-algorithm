/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union_find.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 22:00:14 by jko               #+#    #+#             */
/*   Updated: 2020/04/13 17:15:59 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNION_FIND_H
# define UNION_FIND_H

# include <stdbool.h>
# include <stdlib.h>

typedef struct	s_node
{
	struct	s_node	*parent;
	void			*data;
}				t_node;

t_node	*create_elem(void *data);
t_node	*find(t_node *node);
bool	is_disjoint(t_node *node1, t_node *node2);
t_node	*union_func(t_node *node1, t_node *node2);

#endif
