/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 13:59:57 by jko               #+#    #+#             */
/*   Updated: 2020/06/09 11:21:26 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"
#include "bf.h"
#include <string.h>
#include <stdio.h>

void print_graph(t_graph *graph)
{
	uint	i;
	t_node	*curr;

	if (!graph)
		return ;
	i = 0;
	while (i < graph->size)
	{
		curr = graph->list[i];
		while (curr)
		{
			printf("%2u -> %2u, %d\n", i, curr->vertex, curr->cost);
			curr = curr->next;
		}
		i++;
	}
	printf("\n");
}

void print_sp(t_graph *graph)
{
	int result;
	int *path = 0;

	for (uint i = 0; i < graph->size; ++i) {
		result = find_shortest_path(graph, i, &path);

		if (result == SUCCESS)
		{
			printf("** %d start shortest path cost **\n", i);
			for (uint j = 0; j < graph->size; ++j) {
				printf("vertex %d : cost %d\n", j, path[j]);
			}
		}
		else if (result == FAILURE)
			printf("shortest path error\n");
		else 
			printf("negative cycle, %d\n", result);

		free(path);
		path = 0;
	}
}

int main(void)
{
	t_graph	*graph = graph_init(6);

	graph_set_data(graph, 0, strdup("a"));
	graph_set_data(graph, 1, strdup("b"));
	graph_set_data(graph, 2, strdup("c"));
	graph_set_data(graph, 3, strdup("d"));
	graph_set_data(graph, 4, strdup("e"));
	graph_set_data(graph, 5, strdup("f"));

	graph_set_edge(graph, 0, 1, true, 1);
	graph_set_edge(graph, 0, 2, true, 5);
	graph_set_edge(graph, 0, 3, true, 8);

	graph_set_edge(graph, 1, 2, true, 11);
	graph_set_edge(graph, 1, 4, true, 6);
	graph_set_edge(graph, 1, 5, true, 4);
	
	graph_set_edge(graph, 2, 3, true, 9);
	graph_set_edge(graph, 2, 5, true, 10);

	graph_set_edge(graph, 3, 4, true, 3);
	graph_set_edge(graph, 3, 5, true, 0);
	
	graph_set_edge(graph, 4, 5, true, 7);
	
	graph_set_edge(graph, 5, 0, true, 3);


	print_graph(graph);
	printf("\n");

	print_sp(graph);
	printf("\n");



	graph_set_edge(graph, 3, 0, true, -1);

	print_graph(graph);
	printf("\n");

	print_sp(graph);
	printf("\n");



	graph_set_edge(graph, 2, 0, true, -9);

	print_graph(graph);
	printf("\n");

	print_sp(graph);
	printf("\n");




	free_graph(graph, free);
	graph = 0;

	system("leaks a.out > leaks_result && cat leaks_result | grep leaked");

	return (0);
}
