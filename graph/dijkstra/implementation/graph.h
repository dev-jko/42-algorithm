/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 20:52:43 by jko               #+#    #+#             */
/*   Updated: 2020/04/25 13:31:13 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H

# include <stdlib.h>
# include <stdbool.h>

typedef unsigned int	uint;

typedef struct	s_node
{
	unsigned int	vertex;
	int				cost;
	struct s_node	*next;
}				t_node;

typedef struct	s_graph
{
	unsigned int	size;
	void			**data;
	t_node			**list;
}				t_graph;

t_graph					*graph_init(uint size);
bool					graph_set_data(
							t_graph *graph, uint vertex, void *data);
bool					graph_set_edge(t_graph *graph,
							uint vertex1, uint vertex2, bool state, int cost);
void					*graph_get_data(t_graph *graph, uint vertex);
bool					graph_get_edge(t_graph *graph,
							uint vertex1, uint vertex2, int *cost);
void					free_graph(t_graph *graph, void (*free_data)(void *));

#endif
