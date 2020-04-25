/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kruskal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 22:36:41 by jko               #+#    #+#             */
/*   Updated: 2020/04/25 14:47:11 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KRUSKAL_H
# define KRUSKAL_H

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
