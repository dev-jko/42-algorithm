/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 21:49:03 by jko               #+#    #+#             */
/*   Updated: 2020/04/19 22:16:00 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"
#include <stdio.h>

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

	t_hash_set *set = set_init(cmp);
	printf("size = %d\n", set->size);


	printf("\n--- insert ---------------------------------\n");

	printf("insert %d = %d\n", nums[50], set_insert(set, &nums[50], sizeof(int)));
	printf("size = %d\n", set->size);
	printf("exists = %d\n\n", set_exists(set, &nums[50], sizeof(int)));

	printf("insert %d = %d\n", nums[1], set_insert(set, &nums[1], sizeof(int)));
	printf("size = %d\n", set->size);
	printf("exists = %d\n\n", set_exists(set, &nums[1], sizeof(int)));

	printf("insert %d = %d\n", nums[32], set_insert(set, &nums[32], sizeof(int)));
	printf("size = %d\n", set->size);
	printf("exists = %d\n\n", set_exists(set, &nums[32], sizeof(int)));

	printf("insert %d = %d\n", nums[63], set_insert(set, &nums[63], sizeof(int)));
	printf("size = %d\n", set->size);
	printf("exists = %d\n\n", set_exists(set, &nums[63], sizeof(int)));

	printf("insert %d = %d\n", nums[51], set_insert(set, &nums[51], sizeof(int)));
	printf("size = %d\n", set->size);
	printf("exists = %d\n\n", set_exists(set, &nums[51], sizeof(int)));

	printf("insert %d = %d\n", nums[14], set_insert(set, &nums[14], sizeof(int)));
	printf("size = %d\n", set->size);
	printf("exists = %d\n\n", set_exists(set, &nums[14], sizeof(int)));

	printf("insert %d = %d\n", nums[92], set_insert(set, &nums[92], sizeof(int)));
	printf("size = %d\n", set->size);
	printf("exists = %d\n\n", set_exists(set, &nums[92], sizeof(int)));

	printf("insert %d = %d\n", nums[3], set_insert(set, &nums[3], sizeof(int)));
	printf("size = %d\n", set->size);
	printf("exists = %d\n\n", set_exists(set, &nums[3], sizeof(int)));


	printf("\n--- delete ---------------------------------\n");

	int *t;

	t = &nums[3];
	printf("%d -> exists = %d, delete = %d\n", *t, set_exists(set, t, sizeof(int)), set_delete(set, t, sizeof(int), free_data));
	printf("size = %d\n", set->size);

	t = &nums[1];
	printf("%d -> exists = %d, delete = %d\n", *t, set_exists(set, t, sizeof(int)), set_delete(set, t, sizeof(int), free_data));
	printf("size = %d\n", set->size);

	t = &nums[51];
	printf("%d -> exists = %d, delete = %d\n", *t, set_exists(set, t, sizeof(int)), set_delete(set, t, sizeof(int), free_data));
	printf("size = %d\n", set->size);

	t = &nums[92];
	printf("%d -> exists = %d, delete = %d\n", *t, set_exists(set, t, sizeof(int)), set_delete(set, t, sizeof(int), free_data));
	printf("size = %d\n", set->size);

	t = &nums[50];
	printf("%d -> exists = %d, delete = %d\n", *t, set_exists(set, t, sizeof(int)), set_delete(set, t, sizeof(int), free_data));
	printf("size = %d\n", set->size);

	free_set(set, free_data);



	printf("\n--- test ---------------------------------\n");
	set = set_init(cmp);
	for (int i = 0; i < 60; ++i) {
			printf("insert %d = %d\n", nums[i], set_insert(set, &nums[i], sizeof(int)));
			printf("insert %d = %d\n", nums[i], set_insert(set, &nums[i], sizeof(int)));
			printf("size = %u\n", set->size);
	}
	printf("\n");
	for (int i = 0; i < 101; ++i) {
		printf("exists %d = %d\n", nums[i], set_exists(set, &nums[i], sizeof(int)));
	}
	printf("\n");
	for (int i = 0; i < 101; ++i) {
		t = &nums[i];
		printf("%d -> exists = %d, delete = %d\n", *t, set_exists(set, t, sizeof(int)), set_delete(set, t, sizeof(int), free_data));
		printf("size = %d\n", set->size);
	}

	free_set(set, free_data);
	


	set = 0;
	system("leaks a.out > leaks_result && cat leaks_result | grep leaked");

	return (0);
}
