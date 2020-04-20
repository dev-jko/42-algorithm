/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 21:49:03 by jko               #+#    #+#             */
/*   Updated: 2020/04/20 17:23:54 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <stdio.h>
#include <string.h>

void free_data(void *a)
{
		printf("free %d\n", *(int *)a);
}

int main(void)
{
	int t;
	int	*ptr;
	int	*ptr2;
	int nums[101];
	char *key[101];
	char buf[100];
	for (int i = 0; i < 101; ++i) {
		nums[i] = i;
		sprintf(buf, "%d", i);
		key[i] = strdup(buf);
	}


	printf("\n--- init ---------------------------------\n");

	t_hash_map *map = map_init();
	printf("size = %d\n", map->size);


	printf("\n--- insert ---------------------------------\n");

	t = 50;
	printf("insert (%s, %d) = %d\n", key[t], nums[t], map_insert(map, key[t], &nums[t]));
	printf("size = %d\n", map->size);
	printf("get (%s) = %d\n\n", key[t], *(int *)map_get(map, key[t]));

	t = 1;
	printf("insert (%s, %d) = %d\n", key[t], nums[t], map_insert(map, key[t], &nums[t]));
	printf("size = %d\n", map->size);
	printf("get (%s) = %d\n\n", key[t], *(int *)map_get(map, key[t]));

	t = 43;
	printf("insert (%s, %d) = %d\n", key[t], nums[t], map_insert(map, key[t], &nums[t]));
	printf("size = %d\n", map->size);
	printf("get (%s) = %d\n\n", key[t], *(int *)map_get(map, key[t]));

	t = 14;
	printf("insert (%s, %d) = %d\n", key[t], nums[t], map_insert(map, key[t], &nums[t]));
	printf("size = %d\n", map->size);
	printf("get (%s) = %d\n\n", key[t], *(int *)map_get(map, key[t]));

	t = 98;
	printf("insert (%s, %d) = %d\n", key[t], nums[t], map_insert(map, key[t], &nums[t]));
	printf("size = %d\n", map->size);
	printf("get (%s) = %d\n\n", key[t], *(int *)map_get(map, key[t]));




	printf("\n--- delete ---------------------------------\n");


	t = 1;
	ptr = map_get(map, key[t]);
	ptr2 = map_delete(map, key[t]);
	printf("(%s) get = %d, delete = %d\n", key[t], ptr ? *ptr : -1, ptr2 ? *ptr2 : -1);
	printf("size = %d\n", map->size);

	t = 98;
	ptr = map_get(map, key[t]);
	ptr2 = map_delete(map, key[t]);
	printf("(%s) get = %d, delete = %d\n", key[t], ptr ? *ptr : -1, ptr2 ? *ptr2 : -1);
	printf("size = %d\n", map->size);

	t = 14;
	ptr = map_get(map, key[t]);
	ptr2 = map_delete(map, key[t]);
	printf("(%s) get = %d, delete = %d\n", key[t], ptr ? *ptr : -1, ptr2 ? *ptr2 : -1);
	printf("size = %d\n", map->size);

	t = 11;
	ptr = map_get(map, key[t]);
	ptr2 = map_delete(map, key[t]);
	printf("(%s) get = %d, delete = %d\n", key[t], ptr ? *ptr : -1, ptr2 ? *ptr2 : -1);
	printf("size = %d\n", map->size);

	free_map(map, free_data);



	printf("\n--- test ---------------------------------\n");
	map = map_init();
	for (int i = 0; i < 60; ++i) {
		t = i;
		printf("insert (%s, %d) = %d\n", key[t], nums[t], map_insert(map, key[t], &nums[t]));
		printf("insert (%s, %d) = %d\n", key[t], nums[t + 1], map_insert(map, key[t], &nums[t + 1]));
		printf("size = %d\n", map->size);
	}
	printf("\n");
	for (int i = 0; i < 101; ++i) {
		t = i;
		ptr = map_get(map, key[t]);
		printf("get (%s) = %d\n\n", key[t], ptr ? *ptr : -1);
	}
	printf("\n");
	for (int i = 0; i < 101; ++i) {
		t = i;
		ptr = map_get(map, key[t]);
		ptr2 = map_delete(map, key[t]);
		printf("(%s) get = %d, delete = %d\n", key[t], ptr ? *ptr : -1, ptr2 ? *ptr2 : -1);
		printf("size = %d\n", map->size);
	}

	free_map(map, free_data);
	


	map = 0;
	for (int i = 0; i < 101; ++i) {
		free(key[i]);
	}
	system("leaks a.out > leaks_result && cat leaks_result | grep leaked");

	return (0);
}
