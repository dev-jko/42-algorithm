/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 16:31:43 by jko               #+#    #+#             */
/*   Updated: 2020/04/22 15:02:38 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

static t_graph	*initialize(t_graph *graph, uint size)
{
	uint	i;
	uint	j;

	i = 0;
	while (i < size)
	{
		graph->data[i] = 0;
		j = 0;
		while (j < size)
		{
			graph->matrix[i][j] = false;
			j++;
		}
		i++;
	}
	graph->size = size;
	return (graph);
}

static bool	graph_malloc(t_graph *graph, uint size)
{
	uint	i;
	uint	j;

	if (!(graph->data = malloc(sizeof(void *) * size)))
		return (false);
	if (!(graph->matrix = malloc(sizeof(bool *) * size)))
	{
		free(graph->data);
		return (false);
	}
	i = 0;
	while (i < size)
	{
		if (!(graph->matrix[i] = malloc(sizeof(bool) * size)))
		{
			j = 0;
			while (j < i)
			{
				free(graph->matrix[j]);
				j++;
			}
			free(graph->matrix);
			free(graph->data);
			return (false);
		}
		i++;
	}
	return (true);
}

t_graph	*graph_init(uint size)
{
	t_graph	*graph;

	if (size < 1 || !(graph = malloc(sizeof(t_graph))))
		return (0);
	if (graph_malloc(graph, size))
		return (initialize(graph, size));
	free(graph);
	return (0);
}

bool	graph_set_data(t_graph *graph, uint vertex, void *data)
{
	if (!graph || vertex >= graph->size)
		return (false);
	graph->data[vertex] = data;
	return (true);
}

void	*graph_get_data(t_graph *graph, uint vertex)
{
	if (!graph || vertex >= graph->size)
		return (0);
	return (graph->data[vertex]);
}

bool	graph_set_edge(t_graph *graph, uint vertex1, uint vertex2, bool state)
{
	if (!graph || vertex1 >= graph->size || vertex2 >= graph->size)
		return (false);
	graph->matrix[vertex1][vertex2] = state;
	graph->matrix[vertex2][vertex1] = state;
	return (true);
}

bool	graph_get_edge(t_graph *graph, uint vertex1, uint vertex2)
{
	if (!graph || vertex1 >= graph->size || vertex2 >= graph->size)
		return (false);
	return (graph->matrix[vertex1][vertex2]);
}

void	free_graph(t_graph *graph, void (*free_data)(void *))
{
	uint	i;

	if (!graph || !free_data)
		return ;
	i = 0;
	while (i < graph->size)
	{
		free_data(graph->data[i]);
		free(graph->matrix[i]);
		i++;
	}
	free(graph->data);
	free(graph->matrix);
	free(graph);
}

static void	traverse(
		t_graph *graph,
		uint curr,
		bool *visited,
		void (*print_data)(void *))
{
	uint	i;

	if (!graph || curr >= graph->size
			|| !visited || !print_data || visited[curr])
		return ;
	visited[curr] = true;
	printf("%u번 vertex, data = ", curr);
	print_data(graph->data[curr]);
	i = 0;
	while (i < graph->size)
	{
		if (graph->matrix[curr][i])
			traverse(graph, i, visited, print_data);
		i++;
	}
}

void	graph_traverse(t_graph *graph, void (*print_data)(void *))
{
	bool	*visited;
	uint	i;

	if (!graph || !print_data
			|| !(visited = malloc(sizeof(bool) * graph->size)))
		return ;
	i = 0;
	while (i < graph->size)
		visited[i++] = false;
	traverse(graph, 0, visited, print_data);
	free(visited);
}

static char	*ft_strdup(const char *src)
{
	char	*str;
	uint	len;
	uint	i;

	if (!src)
		return (0);
	len = 0;
	while (src[len])
		len++;
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

t_graph	*make_graph(void)
{
	t_graph	*graph;
	char	*str;

	if (!(graph = graph_init(5)))
		return (0);
	if (!(str = ft_strdup("a0"))
			|| !graph_set_data(graph, 0, str)
			|| !(str = ft_strdup("b1"))
			|| !graph_set_data(graph, 1, str)
			|| !(str = ft_strdup("c2"))
			|| !graph_set_data(graph, 2, str)
			|| !(str = ft_strdup("d3"))
			|| !graph_set_data(graph, 3, str)
			|| !(str = ft_strdup("e4"))
			|| !graph_set_data(graph, 4, str)
			|| !graph_set_edge(graph, 0, 1, true)
			|| !graph_set_edge(graph, 0, 3, true)
			|| !graph_set_edge(graph, 1, 2, true)
			|| !graph_set_edge(graph, 1, 3, true)
			|| !graph_set_edge(graph, 3, 4, true))
	{
		free_graph(graph, free);
		return (0);
	}
	return (graph);
}
