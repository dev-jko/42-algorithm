/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 17:19:10 by jko               #+#    #+#             */
/*   Updated: 2020/04/10 23:39:55 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"
#include <stdio.h>

void print_heap(t_heap *heap)
{
		for (unsigned int i = 1; i <= heap->size; ++i) {
				printf("%u -> %d\n", i, *(int *)heap->data[i]);
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

	t_heap *heap = heap_init(10, cmp);
	printf("size = %d\n", heap->size);
	printf("peek = %d\n", heap_peek(heap) ? *(int *)heap_peek(heap) : -1);
	print_heap(heap);


	printf("\n--- push ---------------------------------\n");

	heap_push(heap, &nums[50]);
	printf("size = %d\n", heap->size);
	printf("peek = %d\n", heap_peek(heap) ? *(int *)heap_peek(heap) : -1);
	print_heap(heap);

	heap_push(heap, &nums[1]);
	printf("size = %d\n", heap->size);
	printf("peek = %d\n", heap_peek(heap) ? *(int *)heap_peek(heap) : -1);
	print_heap(heap);

	heap_push(heap, &nums[32]);
	printf("size = %d\n", heap->size);
	printf("peek = %d\n", heap_peek(heap) ? *(int *)heap_peek(heap) : -1);
	print_heap(heap);

	heap_push(heap, &nums[63]);
	printf("size = %d\n", heap->size);
	printf("peek = %d\n", heap_peek(heap) ? *(int *)heap_peek(heap) : -1);
	print_heap(heap);

	heap_push(heap, &nums[51]);
	printf("size = %d\n", heap->size);
	printf("peek = %d\n", heap_peek(heap) ? *(int *)heap_peek(heap) : -1);
	print_heap(heap);

	heap_push(heap, &nums[14]);
	printf("size = %d\n", heap->size);
	printf("peek = %d\n", heap_peek(heap) ? *(int *)heap_peek(heap) : -1);
	print_heap(heap);

	heap_push(heap, &nums[92]);
	printf("size = %d\n", heap->size);
	printf("peek = %d\n", heap_peek(heap) ? *(int *)heap_peek(heap) : -1);
	print_heap(heap);

	heap_push(heap, &nums[3]);
	printf("size = %d\n", heap->size);
	printf("peek = %d\n", heap_peek(heap) ? *(int *)heap_peek(heap) : -1);
	print_heap(heap);


	printf("\n--- pop ---------------------------------\n");

	printf("pop = %d\n", heap_peek(heap) ? *(int *)heap_pop(heap) : -1);
	printf("size = %d\n", heap->size);
	printf("peek = %d\n", heap_peek(heap) ? *(int *)heap_peek(heap) : -1);
	print_heap(heap);

	printf("pop = %d\n", heap_peek(heap) ? *(int *)heap_pop(heap) : -1);
	printf("size = %d\n", heap->size);
	printf("peek = %d\n", heap_peek(heap) ? *(int *)heap_peek(heap) : -1);
	print_heap(heap);

	printf("pop = %d\n", heap_peek(heap) ? *(int *)heap_pop(heap) : -1);
	printf("size = %d\n", heap->size);
	printf("peek = %d\n", heap_peek(heap) ? *(int *)heap_peek(heap) : -1);
	print_heap(heap);

	printf("pop = %d\n", heap_peek(heap) ? *(int *)heap_pop(heap) : -1);
	printf("size = %d\n", heap->size);
	printf("peek = %d\n", heap_peek(heap) ? *(int *)heap_peek(heap) : -1);
	print_heap(heap);

	printf("pop = %d\n", heap_peek(heap) ? *(int *)heap_pop(heap) : -1);
	printf("size = %d\n", heap->size);
	printf("peek = %d\n", heap_peek(heap) ? *(int *)heap_peek(heap) : -1);
	print_heap(heap);

	free_heap(heap, free_data);






	heap = heap_init(50, cmp);
	for (int i = 0; i < 60; ++i) {
			heap_push(heap, &nums[i]);
			printf("size = %u\n", heap->size);
	}
	print_heap(heap);

	for (int i = 0; i < 60; ++i) {
			printf("pop = %d\n", heap_peek(heap) ? *(int *)heap_pop(heap) : -1);
	}
	print_heap(heap);

	free_heap(heap, free_data);
	

	heap = 0;
	system("leaks a.out > leaks_result && cat leaks_result | grep leaked");

	return (0);
}
