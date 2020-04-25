/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 20:57:47 by jko               #+#    #+#             */
/*   Updated: 2020/04/25 16:34:53 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

t_graph	*graph_init(uint size)
{
	t_graph	*graph;
	uint	i;

	if (size < 1 || !(graph = malloc(sizeof(t_graph))))
		return (0);
	if (!(graph->data = malloc(sizeof(void *) * size)))
	{
		free(graph);
		return (0);
	}
	if (!(graph->list = malloc(sizeof(t_node *) * size)))
	{
		free(graph->data);
		free(graph);
		return (0);
	}
	i = 0;
	while (i < size)
	{
		graph->data[i] = 0;
		graph->list[i] = 0;
		i++;
	}
	graph->size = size;
	return (graph);
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

static t_node	*create_elem(uint vertex)
{
	t_node *node;

	if (!(node = malloc(sizeof(t_node))))
		return (0);
	node->vertex = vertex;
	node->next = 0;
	return (node);
}

static bool		add_list(t_node **head, t_node *new)
{
	t_node	*prev;
	t_node	*curr;

	if (!head || !new)
		return (false);
	if (*head == 0)
	{
		*head = new;
		return (true);
	}
	prev = 0;
	curr = *head;
	while (curr && new->vertex < curr->vertex)
	{
		prev = curr;
		curr = curr->next;
	}
	if (!prev)
		*head = new;
	else
		prev->next = new;
	new->next = curr;
	return (true);
}

static bool		find_list(t_node *head, uint vertex)
{
	t_node	*curr;

	if (!head)
		return (false);
	curr = head;
	while (curr)
	{
		if (curr->vertex == vertex)
			return (true);
		curr = curr->next;
	}
	return (false);
}

static bool		remove_list(t_node **head, uint vertex)
{
	t_node	*prev;
	t_node	*curr;

	if (!head)
		return (false);
	if (!(*head))
		return (true);
	prev = 0;
	curr = *head;
	while (curr)
	{
		if (curr->vertex == vertex)
			break ;
		prev = curr;
		curr = curr->next;
	}
	if (!curr)
		return (true);
	if (!prev)
		*head = curr->next;
	else
		prev->next = curr->next;
	free(curr);
	return (true);
}

bool	graph_set_edge(t_graph *graph, uint vertex1, uint vertex2, bool state)
{
	t_node	*new1;
	t_node	*new2;

	if (!graph || vertex1 >= graph->size || vertex2 >= graph->size)
		return (false);
	if (find_list(graph->list[vertex1], vertex2) == state)
		return (true);
	if (!state)
	{
		if (remove_list(&(graph->list[vertex1]), vertex2)
				&& remove_list(&(graph->list[vertex2]), vertex1))
			return (true);
		else
			return (false);
	}
	if (!(new1 = create_elem(vertex2)))
		return (false);
	if (!(new2 = create_elem(vertex1)))
	{
		free(new1);
		return (false);
	}
	if (!add_list(&(graph->list[vertex1]), new1)
			|| !add_list(&(graph->list[vertex2]), new2))
	{
		free(new1);
		free(new2);
		return (false);
	}
	return (true);
}

bool	graph_get_edge(t_graph *graph, uint vertex1, uint vertex2)
{
	if (!graph || vertex1 >= graph->size || vertex2 >= graph->size)
		return (false);
	return (find_list(graph->list[vertex1], vertex2));
}

static void	free_list(t_node *curr)
{
	t_node *temp;

	while (curr)
	{
		temp = curr;
		curr = curr->next;
		free(temp);
	}
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
		free_list(graph->list[i]);
		i++;
	}
	free(graph->data);
	free(graph->list);
	free(graph);
}

static void	add_stack(uint *stack, uint *index, t_node *node, bool *visited)
{
	while (node)
	{
		if (!visited[node->vertex])
		{
			visited[node->vertex] = true;
			++(*index);
			stack[*index] = node->vertex;
		}
		node = node->next;
	}
}

void	graph_traverse(t_graph *graph, void (*print_data)(void *))
{
	bool	*visited;
	uint	*stack;
	uint	i;
	uint	vertex;

	if (!graph || !print_data
			|| !(visited = malloc(sizeof(bool) * graph->size))
			|| !(stack = malloc(sizeof(uint) * (graph->size + 1))))
		return ;
	i = 0;
	while (i < graph->size)
		visited[i++] = false;
	i = 1;
	stack[1] = 0;
	visited[0] = true;
	while (i > 0)
	{
		vertex = stack[i--];
		printf("%u번 vertex, data = ", vertex);
		print_data(graph->data[vertex]);
		add_stack(stack, &i, graph->list[vertex], visited);
	}
	free(stack);
	free(visited);
}
