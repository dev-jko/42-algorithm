/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 16:21:01 by jko               #+#    #+#             */
/*   Updated: 2020/04/12 20:44:42 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trie.h"
#include <stdio.h>

static void	print_str(t_node *node, char buf[4096], int index)
{
	if (!node)
		return ;
	if (node->finish)
	{
		buf[index] = 0;
		printf("%s\n", buf);
	}
	for (int i = 0; i < 26; ++i) {
		buf[index] = i + 'a';
		print_str(node->next[i], buf, index + 1);
	}
}

void print_trie(t_trie *trie)
{
	char	buf[4096];

	for (int i = 0; i < 4096; ++i) {
		buf[i] = 0;
	}

	if (!trie)
	{
		printf("error\n");
		return ;
	}
	for (int i = 0; i < 26; ++i) {
		buf[0] = i + 'a';
		print_str((*trie)[i], buf, 1);
	}
}

int main(void)
{
	char *strs[100] = {
		"abc",
		"z",
		"abz",
		"bb",
		"f",
		"qwertyuiopasdfghjklzxcvbnm"
		"zzzz",
		"wnoane",
		"",
		"acccc",
		0
	};

	t_trie *trie = trie_init();
	print_trie(trie);

	for (int i = 0; strs[i]; ++i) {
		printf("insert result = %d\n", trie_insert(trie, strs[i]));
		print_trie(trie);
		printf("\n");
	}

	for (int i = 0; strs[i]; ++i) {
		printf("%s find result = %d\n", strs[i], trie_find(trie, strs[i]));
		printf("\n");
	}


	free_trie(trie);

	trie = 0;
	system("leaks a.out > leaks_result && cat leaks_result | grep leaked");

	return (0);
}
