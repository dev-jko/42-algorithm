/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 17:55:48 by jko               #+#    #+#             */
/*   Updated: 2020/04/15 23:21:16 by jko              ###   ########.fr       */
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
	i = start + 1;
	j = end;
	while (i < j)
	{
		while ((i < end) && (cmp(items[pivot], items[i]) > 0))
			i++;
		while ((j > start + 1) && (cmp(items[pivot], items[j]) < 0))
			j--;
		if (i < j)
			break ;
		temp = items[i];
		items[i] = items[j];
		items[j] = temp;
		i++;
		j--;
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
