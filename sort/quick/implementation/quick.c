/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 17:55:48 by jko               #+#    #+#             */
/*   Updated: 2020/04/16 01:07:04 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quick.h"

static void	quick(void **items, int start, int end, int (*cmp)(void *, void *))
{
	int		i;
	int		j;
	int		pivot;
	void	*temp;

	if (start >= end)
		return ;
	pivot = start;
	i = start;
	j = end;
	while (i < j)
	{
		while (cmp(items[pivot], items[j]) < 0)
			j--;
		while (i < j && cmp(items[pivot], items[i]) >= 0)
			i++;
		temp = items[i];
		items[i] = items[j];
		items[j] = temp;
	}
	temp = items[pivot];
	items[pivot] = items[i];
	items[i] = temp;
	quick(items, start, i - 1, cmp);
	quick(items, i + 1, end, cmp);
}

int	quick_sort(void **items, int size, int (*cmp)(void *, void *))
{
	if (!items || size < 0 || !cmp)
		return (0);
	quick(items, 0, size - 1, cmp);
	return (1);
}
