/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prim.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 16:56:40 by jko               #+#    #+#             */
/*   Updated: 2020/04/26 16:56:54 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIM_H
# define PRIM_H

#include "graph.h"
#include "heap.h"

typedef struct	s_edge
{
	uint		start;
	uint		end;
	int			cost;
}				t_edge;

t_graph *make_mst(const t_graph *src);

#endif
