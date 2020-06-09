/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fw.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 12:12:38 by jko               #+#    #+#             */
/*   Updated: 2020/06/09 13:39:35 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fw.h"

static int	**free_result(int **result, uint size)
{
	uint	i;

	i = 0;
	while (i < size)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}

static void	fill_initial_cost(const t_graph *src, int **result)
{
	t_node	*node;
	uint	i;

	i = 0;
	while (i < src->size)
	{
		node = src->list[i];
		while (node)
		{
			result[i][node->vertex] = node->cost;
			node = node->next;
		}
		if (result[i][i] > 0)
			result[i][i] = 0;
		i++;
	}
}

static int	**init_result(const t_graph *src)
{
	int 	**result;
	uint	i;
	uint	j;

	if (!(result = malloc(sizeof(int *) * src->size)))
		return (0);
	i = 0;
	while (i < src->size)
	{
		if (!(result[i] = malloc(sizeof(int) * src->size)))
			return (free_result(result, i));
		i++;
	}
	i = 0;
	while (i < src->size)
	{
		j = 0;
		while (j < src->size)
		{
			result[i][j] = INT_MAX;
			j++;
		}
		i++;
	}
	fill_initial_cost(src, result);
	return (result);
}

static int	check_int_range(int a, int b)
{
	int		temp;

	temp = a + b;
	if (temp < 0 && a >= 0 && b >= 0)
		temp = INT_MAX;
	else if (temp >= 0 && a < 0 && b < 0)
		temp = INT_MIN;
	return (temp);
}

int			**find_shortest_path(const t_graph *src)
{
	int		**result;
	uint	i;
	uint	j;
	uint	k;
	int		temp;

	if (!src || !(result = init_result(src)))
		return (0);
	k = 0;
	while (k < src->size)
	{
		i = 0;
		while (i < src->size)
		{
			j = 0;
			while (j < src->size)
			{
				temp = check_int_range(result[i][k], result[k][j]);
				if (temp < result[i][j])
					result[i][j] = temp;
				j++;
			}
			i++;
		}
		k++;
	}
	return (result);
}
