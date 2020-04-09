/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 17:19:10 by jko               #+#    #+#             */
/*   Updated: 2020/04/09 17:29:42 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>

void print_heap(t_heap *heap)
{
		for (int i = 1; i <= heap->size; ++i) {
				printf("%d -> %d\n", i, *(int *)heap->data[i]);
		}
		printf("\n");
}

int cmp(void *a, void *b)
{
		return (*(int *)a - *(int *)b);
}

int main(void)
{
	int nums[101];
	for (int i = 0; i < 101; ++i) {
		nums[i] = i;
	}


	printf("\n--- init ---------------------------------\n");

	t_heap *heap = heap_init(10, cmp);
	printf("size = %d\n", heap->size);
	printf("");
	
	print_heap(heap);


	printf("\n--- insert ---------------------------------\n");

	heap_insert(heap, &nums[50]);
	printf("size = %d\n", heap->size);
	print_heap(heap);

	heap_insert(heap, &nums[1]);
	printf("size = %d\n", heap->size);
	print_heap(heap);

	heap_insert(heap, &nums[32]);
	printf("size = %d\n", heap->size);
	print_heap(heap);

	heap_insert(heap, &nums[63]);
	printf("size = %d\n", heap->size);
	print_heap(heap);

	heap_insert(heap, &nums[51]);
	printf("size = %d\n", heap->size);
	print_heap(heap);

	heap_insert(heap, &nums[14]);
	printf("size = %d\n", heap->size);
	print_heap(heap);

	heap_insert(heap, &nums[92]);
	printf("size = %d\n", heap->size);
	print_heap(heap);

	heap_insert(heap, &nums[3]);
	printf("size = %d\n", heap->size);
	print_heap(heap);


	printf("\n--- delete ---------------------------------\n");

	heap_delete(heap, &nums[63], free_data);
	printf("size = %d\n", heap->size);
	print_heap(heap);

	heap_delete(heap, &nums[50], free_data);
	printf("size = %d\n", heap->size);
	print_heap(heap);

	heap_delete(heap, &nums[92], free_data);
	printf("size = %d\n", heap->size);
	print_heap(heap);

	heap_delete(heap, &nums[51], free_data);
	printf("size = %d\n", heap->size);
	print_heap(heap);

	heap_delete(heap, &nums[14], free_data);
	printf("size = %d\n", heap->size);
	print_heap(heap);



	free_heap(heap, free_data);

	heap = 0;
	system("leaks a.out > leaks_result && cat leaks_result | grep leaked");

	return (0);
}
