/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 17:55:48 by jko               #+#    #+#             */
/*   Updated: 2020/04/16 01:23:51 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quick.h"

static void	swap(void **items, int i, int j)
{
	void	*temp;

	temp = items[i];
	items[i] = items[j];
	items[j] = temp;
}

static void	quick(void **items, int start, int end, int (*cmp)(void *, void *))
{
	int		i;
	int		j;

	if (start >= end)
		return ;
	swap(items, start, (start + end) / 2);
	i = start;
	j = end;
	while (i < j)
	{
		while (cmp(items[start], items[j]) < 0)
			j--;
		while (i < j && cmp(items[start], items[i]) >= 0)
			i++;
		swap(items, i, j);
	}
	swap(items, start, i);
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
