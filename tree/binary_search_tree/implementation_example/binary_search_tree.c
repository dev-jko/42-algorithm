/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 21:13:23 by jko               #+#    #+#             */
/*   Updated: 2020/04/06 22:58:22 by jko              ###   ########.fr       */
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
	tree->size++;
	return (1);
}

static t_node	*change_node(t_node *curr, t_node *prev, t_tree *tree)
{
	t_node	*temp;
	t_node	*prev2;

	temp = curr;
	if (!curr->left && !curr->right)
		curr = 0;
	else if (curr->left && curr->right)
	{
		prev2 = curr;
		curr = curr->right;
		while (curr->left)
		{
			prev2 = curr;
			curr = curr->left;
		}
		curr = change_node(curr, prev2, tree);
		curr->left = temp->left;
		curr->right = temp->right;
	}
	else
		curr = curr->left ? curr->left : curr->right;
	if (!prev)
		tree->root = curr;
	else if (tree->cmp(prev->data, temp->data) > 0)
		prev->left = curr;
	else
		prev->right = curr;
	return (temp);
}

int	tree_delete(t_tree *tree, void *data_ref, void (*free_data)(void *))
{
	t_node	*prev;
	t_node	*curr;
	int	cmp_result;

	if (!tree || !free_data || tree_size(tree) == 0)
		return (0);
	curr = tree->root;
	prev = 0;
	while (curr)
	{
		if (!(cmp_result = tree->cmp(data_ref, curr->data)))
			break ;
		prev = curr;
		if (cmp_result < 0)
			curr = curr->left;
		else
			curr = curr->right;
	}
	if (!curr)
		return (0);
	curr = change_node(curr, prev, tree);
	free_data(curr->data);
	free(curr);
	tree->size--;
	return (1);
}

static void	free_tree_node(t_node *node, void (*free_data)(void *))
{
	if (!node || !free_data)
		return ;
	free_data(node->data);
	free_tree_node(node->left, free_data);
	free_tree_node(node->right, free_data);
	free(node);
}

void	free_tree(t_tree *tree, void (*free_data)(void *))
{
	if (!tree || !free_data)
		return ;
	free_tree_node(tree->root, free_data);
	free(tree);
}
