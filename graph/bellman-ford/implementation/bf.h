/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 16:12:27 by jko               #+#    #+#             */
/*   Updated: 2020/06/08 21:57:04 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BF_H
# define BF_H

# define FAILURE 0
# define SUCCESS 1
# define NEGATIVE_CYCLE 2

#include "graph.h"
#include <limits.h>

int find_shortest_path(const t_graph *src, uint start, int **result);

#endif
