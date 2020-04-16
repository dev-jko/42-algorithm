/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 14:19:25 by jko               #+#    #+#             */
/*   Updated: 2020/04/16 15:16:00 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "merge.h"

static void	**temps;

static void	merge(void **items, int start, int end, int (*cmp)(void *, void *))
{
	int	i;
	int	j;
	int	k;
	int	mid;

	if (start >= end)
		return ;
	mid = (start + end) / 2;
	merge(items, start, mid, cmp);
	merge(items, mid + 1, end, cmp);
	i = start;
	j = mid + 1;
	k = start;
	while (i <= mid && j <= end)
	{
		if (cmp(items[i], items[j]) <= 0)
			temps[k++] = items[i++];
		else
			temps[k++] = items[j++];
	}
	while (i <= mid)
		temps[k++] = items[i++];
	while (j <= end)
		temps[k++] = items[j++];
	while (start <= end)
	{
		items[start] = temps[start];
		start++;
	}
}

int			merge_sort(void **items, int size, int (*cmp)(void *, void *))
{
	if (!items || size < 0 || !cmp || !(temps = malloc(sizeof(void *) * size)))
		return (0);
	merge(items, 0, size - 1, cmp);
	free(temps);
	temps = 0;
	return (1);
}
