/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 21:13:23 by jko               #+#    #+#             */
/*   Updated: 2020/04/04 21:51:32 by jko              ###   ########.fr       */
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
	tree->size = 0;
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

int	tree_size(t_tree *tree)
{
	if (!tree)
		return (0);
	return (tree->size);
}

t_node	*tree_find(t_tree *tree, void *data_ref)
{
	t_node	*curr;
	int	cmp_result;

	if (!tree)
		return (0);
	curr = tree->root;
	while (curr)
	{
		if (!(cmp_result = tree->cmp(data_ref, curr->data)))
			return (curr);
		if (cmp_result < 0)
			curr = curr->left;
		else
			curr = curr->right;
	}
	return (0);
}

int	tree_insert(t_tree *tree, void *data)
{
	t_node	*new;
	t_node	*curr;
	t_node	*prev;
	int	cmp_result;

	if (!tree)
		return (0);
	curr = tree->root;
	prev = 0;
	while (curr)
	{
		if (!(cmp_result = tree->cmp(data, curr->data)))
			return (0);
		prev = curr;
		if (cmp_result < 0)
			curr = curr->left;
		else
			curr = curr->right;
	}
	if (!(new = create_elem(data)))
		return (0);
	if (!prev)
		tree->root = new;
	else if (cmp_result < 0)
		prev->left = new;
	else
		prev->right = new;
	return (1);
}

int	tree_delete(t_tree *tree, void *data_ref, void (*free_data)(void *))
{
	t_node	*curr;
	int	cmp_result;

	if (!tree || !free_data)
		return (0);
	curr = tree->root;
	if (tree->cmp(data_ref, tree->root))
	while (curr)
	{
		if (!(cmp_result = tree->cmp(data_ref, curr->data)))
		{
			free_data(curr->data);
			free(curr);

			return (1);
		}
	}

}

void	free_tree(t_tree *tree, void (*free_data)(void *))
{

}
