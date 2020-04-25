/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 17:53:58 by jko               #+#    #+#             */
/*   Updated: 2020/04/25 16:29:23 by jko              ###   ########.fr       */
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

	if (*head == 0)
	{
		*head = new;
		return (true);
	}
	prev = 0;
	curr = *head;
	while (curr && new->vertex > curr->vertex)
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

bool	graph_set_edge(t_graph *graph, uint start, uint end, bool state)
{
	t_node	*new;

	if (!graph || start >= graph->size || end >= graph->size)
		return (false);
	if (find_list(graph->list[start], end) == state)
		return (true);
	if (!state)
		return (remove_list(&(graph->list[start]), end));
	if (!(new = create_elem(end)))
		return (false);
	if (!add_list(&(graph->list[start]), new))
	{
		free(new);
		return (false);
	}
	return (true);
}

bool	graph_get_edge(t_graph *graph, uint start, uint end)
{
	if (!graph || start >= graph->size || end >= graph->size)
		return (false);
	return (find_list(graph->list[start], end));
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

static bool	queue_push(t_node **head, t_node **tail, uint vertex)
{
	t_node	*curr;
	t_node	*new;

	if (!(new = create_elem(vertex)))
		return (false);
	if (!(*head))
	{
		*head = new;
		*tail = new;
		return (true);
	}
	(*tail)->next = new;
	*tail = new;
	return (true);
}

static t_node	*queue_pop(t_node **head, t_node **tail)
{
	t_node	*node;

	if (!(*head))
		return (0);
	node = *head;
	*head = node->next;
	if (!node->next)
		*tail = 0;
	return (node);
}

static bool	push_adjacency(
		t_node **head, t_node **tail, t_node *curr, bool *visited)
{
	while (curr)
	{
		if (!visited[curr->vertex])
		{
			visited[curr->vertex] = true;
			if (!queue_push(head, tail, curr->vertex))
				return (false);
		}
		curr = curr->next;
	}
	return (true);
}

static bool	init_variable(
		bool *visited, uint size, t_node **head, t_node **tail)
{
	uint	i;

	*head = 0;
	*tail = 0;
	i = 0;
	while (i < size)
		visited[i++] = false;
	if (!queue_push(head, tail, 0))
		return (false);
	visited[0] = true;
	return (true);
}

void	graph_traverse(t_graph *graph, void (*print_data)(void *))
{
	bool	*visited;
	t_node	*head;
	t_node	*tail;
	t_node	*curr;
	uint	i;

	if (!graph || !print_data
			|| !(visited = malloc(sizeof(bool) * graph->size)))
		return ;
	if (!init_variable(visited, graph->size, &head, &tail))
	{
		free(visited);
		return ;
	}
	while ((curr = queue_pop(&head, &tail)))
	{
		i = curr->vertex;
		free(curr);
		printf("%u번 vertex, data = ", i);
		print_data(graph->data[i]);
		if (push_adjacency(&head, &tail, graph->list[i], visited))
			continue ;
		free_list(head);
		head = 0;
	}
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
			|| !graph_set_edge(graph, 0, 0, true)
			|| !graph_set_edge(graph, 0, 1, true)
			|| !graph_set_edge(graph, 0, 3, true)
			|| !graph_set_edge(graph, 1, 2, true)
			|| !graph_set_edge(graph, 1, 3, true)
			|| !graph_set_edge(graph, 3, 0, true)
			|| !graph_set_edge(graph, 2, 4, true)
			|| !graph_set_edge(graph, 4, 2, true)
			|| !graph_set_edge(graph, 4, 3, true))
	{
		free_graph(graph, free);
		return (0);
	}
	return (graph);
}
