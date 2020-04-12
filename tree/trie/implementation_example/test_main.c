/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 16:21:01 by jko               #+#    #+#             */
/*   Updated: 2020/04/12 16:21:04 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trie.h"
#include <stdio.h>

void print_trie(t_trie *trie)
{
		for (unsigned int i = 1; i <= trie->size; ++i) {
				printf("%u -> %d\n", i, *(int *)trie->data[i]);
		}
		printf("\n");
}

int cmp(void *a, void *b)
{
		return (*(int *)a - *(int *)b);
}

void free_data(void *a)
{
		printf("free %d\n", *(int *)a);
}

int main(void)
{
	int nums[101];
	for (int i = 0; i < 101; ++i) {
		nums[i] = i;
	}


	printf("\n--- init ---------------------------------\n");

	t_trie *trie = trie_init(10, cmp);
	printf("size = %d\n", trie->size);
	printf("peek = %d\n", trie_peek(trie) ? *(int *)trie_peek(trie) : -1);
	print_trie(trie);


	printf("\n--- push ---------------------------------\n");

	trie_push(trie, &nums[50]);
	printf("size = %d\n", trie->size);
	printf("peek = %d\n", trie_peek(trie) ? *(int *)trie_peek(trie) : -1);
	print_trie(trie);

	trie_push(trie, &nums[1]);
	printf("size = %d\n", trie->size);
	printf("peek = %d\n", trie_peek(trie) ? *(int *)trie_peek(trie) : -1);
	print_trie(trie);

	trie_push(trie, &nums[32]);
	printf("size = %d\n", trie->size);
	printf("peek = %d\n", trie_peek(trie) ? *(int *)trie_peek(trie) : -1);
	print_trie(trie);

	trie_push(trie, &nums[63]);
	printf("size = %d\n", trie->size);
	printf("peek = %d\n", trie_peek(trie) ? *(int *)trie_peek(trie) : -1);
	print_trie(trie);

	trie_push(trie, &nums[51]);
	printf("size = %d\n", trie->size);
	printf("peek = %d\n", trie_peek(trie) ? *(int *)trie_peek(trie) : -1);
	print_trie(trie);

	trie_push(trie, &nums[14]);
	printf("size = %d\n", trie->size);
	printf("peek = %d\n", trie_peek(trie) ? *(int *)trie_peek(trie) : -1);
	print_trie(trie);

	trie_push(trie, &nums[92]);
	printf("size = %d\n", trie->size);
	printf("peek = %d\n", trie_peek(trie) ? *(int *)trie_peek(trie) : -1);
	print_trie(trie);

	trie_push(trie, &nums[3]);
	printf("size = %d\n", trie->size);
	printf("peek = %d\n", trie_peek(trie) ? *(int *)trie_peek(trie) : -1);
	print_trie(trie);


	printf("\n--- pop ---------------------------------\n");

	printf("pop = %d\n", trie_peek(trie) ? *(int *)trie_pop(trie) : -1);
	printf("size = %d\n", trie->size);
	printf("peek = %d\n", trie_peek(trie) ? *(int *)trie_peek(trie) : -1);
	print_trie(trie);

	printf("pop = %d\n", trie_peek(trie) ? *(int *)trie_pop(trie) : -1);
	printf("size = %d\n", trie->size);
	printf("peek = %d\n", trie_peek(trie) ? *(int *)trie_peek(trie) : -1);
	print_trie(trie);

	printf("pop = %d\n", trie_peek(trie) ? *(int *)trie_pop(trie) : -1);
	printf("size = %d\n", trie->size);
	printf("peek = %d\n", trie_peek(trie) ? *(int *)trie_peek(trie) : -1);
	print_trie(trie);

	printf("pop = %d\n", trie_peek(trie) ? *(int *)trie_pop(trie) : -1);
	printf("size = %d\n", trie->size);
	printf("peek = %d\n", trie_peek(trie) ? *(int *)trie_peek(trie) : -1);
	print_trie(trie);

	printf("pop = %d\n", trie_peek(trie) ? *(int *)trie_pop(trie) : -1);
	printf("size = %d\n", trie->size);
	printf("peek = %d\n", trie_peek(trie) ? *(int *)trie_peek(trie) : -1);
	print_trie(trie);

	free_trie(trie, free_data);






	trie = trie_init(50, cmp);
	for (int i = 0; i < 60; ++i) {
			trie_push(trie, &nums[i]);
			printf("size = %u\n", trie->size);
	}
	print_trie(trie);

	for (int i = 0; i < 60; ++i) {
			printf("pop = %d\n", trie_peek(trie) ? *(int *)trie_pop(trie) : -1);
	}
	print_trie(trie);

	free_trie(trie, free_data);
	

	trie = 0;
	system("leaks a.out > leaks_result && cat leaks_result | grep leaked");

	return (0);
}
