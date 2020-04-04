/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 21:13:23 by jko               #+#    #+#             */
/*   Updated: 2020/04/04 21:21:42 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

t_tree	*tree_init(int (*cmp)(void *, void *))
{
	t_tree	*tree;

	if (!cmp || !(tree = malloc(sizeof(t_tree))))
		return (0);
	tree->root = 0;
	tree->cmp = cmp;
	return (tree);
}

t_node	*create_elem(void *data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->data = data;
	node->left = 0;
	node->right = 0;
	return (node);
}

int	tree_insert(t_tree *tree, void *data)
{
	t_node	*new;

	if (!tree || !(new = create_elem(data)))
		return (0);

}

t_node	*tree_find(t_tree *tree, void *data_ref)
{

}

int	tree_delete(t_tree *tree, void *data_ref, void (*free_data)(void *))
{

}

void	free_tree(t_tree *tree, void (*free_data)(void *))
{

}
