/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 22:05:26 by jko               #+#    #+#             */
/*   Updated: 2020/04/23 13:39:13 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "union_find.h"

t_node	*create_elem(void *data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->data = data;
	node->parent = 0;
	return (node);
}

t_node	*find(t_node *node)
{
	if (!node)
		return (0);
	if (!node->parent)
		return (node);
	return (node->parent = find(node->parent));
}

bool	is_disjoint(t_node *node1, t_node *node2)
{
	if (!node1 || !node2)
		return (true);
	return (!(find(node1) == find(node2)));
}

t_node	*union_func(t_node *node1, t_node *node2)
{
	if (!node1 || !node2)
		return (0);
	if (!is_disjoint(node1, node2))
		return (find(node1));
	return (find(node2)->parent = find(node1));
}
