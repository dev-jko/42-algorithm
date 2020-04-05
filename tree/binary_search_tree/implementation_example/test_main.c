/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 17:50:41 by jko               #+#    #+#             */
/*   Updated: 2020/04/05 19:12:55 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>

int cmp(void *a, void *b)
{
	return (*(int *)a - *(int *)b);
}

void print_tree(int index, t_node *node)
{
	if (!node)
		return ;
	printf("#%d node : %d\n", index, *(int *)node->data);
	print_tree(index * 2, node->left);
	print_tree(index * 2 + 1, node->right);
}

void free_data(void *a)
{
	printf("free data %d\n", *(int *)a);
}

int main(void)
{
	t_node *temp;
	int nums[101];
	for (int i = 0; i < 101; ++i) {
		nums[i] = i;
	}

	t_tree *tree = tree_init(cmp);
	printf("size = %d\n", tree_size(tree));
	print_tree(1, tree->root);

	tree_insert(tree, &nums[50]);
	printf("size = %d\n", tree_size(tree));
	print_tree(1, tree->root);

	tree_insert(tree, &nums[1]);
	printf("size = %d\n", tree_size(tree));
	print_tree(1, tree->root);

	tree_insert(tree, &nums[32]);
	printf("size = %d\n", tree_size(tree));
	print_tree(1, tree->root);

	tree_insert(tree, &nums[63]);
	printf("size = %d\n", tree_size(tree));
	print_tree(1, tree->root);

	tree_insert(tree, &nums[50]);
	printf("size = %d\n", tree_size(tree));
	print_tree(1, tree->root);

	tree_insert(tree, &nums[1]);
	printf("size = %d\n", tree_size(tree));
	print_tree(1, tree->root);

	tree_insert(tree, &nums[32]);
	printf("size = %d\n", tree_size(tree));
	print_tree(1, tree->root);

	tree_insert(tree, &nums[63]);
	printf("size = %d\n", tree_size(tree));
	print_tree(1, tree->root);


	if ((temp = tree_find(tree, &nums[63])))
		printf("find %d\n", *(int *)temp->data);
	else
		printf("not found\n");

	tree_delete(tree, &nums[63], free_data);
	printf("size = %d\n", tree_size(tree));
	print_tree(1, tree->root);

	tree = 0;
	system("leaks a.out > leaks_result && cat leaks_result | grep leaked");

	return (0);
}
