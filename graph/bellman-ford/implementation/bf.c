/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 16:13:32 by jko               #+#    #+#             */
/*   Updated: 2020/06/09 11:34:29 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bf.h"

static int	*init_result(const t_graph *src, uint start)
{
	int		*result;
	t_node	*node;
	uint	i;

	if (!(result = malloc(sizeof(int) * src->size)))
		return (0);
	i = 0;
	while (i < src->size)
	{
		result[i] = INT_MAX;
		i++;
	}
	node = src->list[start];
	while (node)
	{
		result[node->vertex] = node->cost;
		node = node->next;
	}
	result[start] = 0;
	return (result);
}

static void	relax_edge(const t_graph *src, int **result)
{
	uint	i;
	uint	j;
	int		temp;
	t_node	*node;

	i = 0;
	while (i < src->size - 1)
	{
		j = 0;
		while (j < src->size)
		{
			node = src->list[j];
			while (node)
			{
				temp = (*result)[j] + node->cost;
				if ((*result)[j] >= 0 && node->cost >= 0 && temp < 0)
					temp = INT_MAX;
				else if ((*result)[j] < 0 && node->cost < 0 && temp >= 0)
					temp = INT_MIN;
				if ((*result)[node->vertex] > temp)
					(*result)[node->vertex] = temp;
				node = node->next;
			}
			j++;
		}
		i++;
	}
}

static int	check_negative_cycle(const t_graph *src, int **result)
{
	t_node	*node;
	uint	i;
	int		temp;

	i = 0;
	while (i < src->size)
	{
		node = src->list[i];
		while (node)
		{
			temp = (*result)[i] + node->cost;
			if ((*result)[i] >= 0 && node->cost >= 0 && temp < 0)
				temp = INT_MAX;
			else if ((*result)[i] < 0 && node->cost < 0 && temp >= 0)
				temp = INT_MIN;
			if ((*result)[node->vertex] > temp)
			{
				free(*result);
				*result = 0;
				return (NEGATIVE_CYCLE);
			}
			node = node->next;
		}
		i++;
	}
	return (SUCCESS);
}

int			find_shortest_path(const t_graph *src, uint start, int **result)
{
	if (!src || src->size <= start || !(*result = init_result(src, start)))
	{
		*result = 0;
		return (FAILURE);
	}
	relax_edge(src, result);
	return (check_negative_cycle(src, result));
}
