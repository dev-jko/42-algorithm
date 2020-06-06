/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 18:23:45 by jko               #+#    #+#             */
/*   Updated: 2020/06/06 13:03:17 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIJKSTRA_H
# define DIJKSTRA_H

#include "graph.h"
#include "heap.h"
#include <limits.h>

typedef struct	s_path
{
	uint		vertex;
	uint		cost;
}				t_path;

uint			*find_shortest_path(const t_graph *src, uint start);

#endif
