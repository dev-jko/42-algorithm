/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 22:05:16 by jko               #+#    #+#             */
/*   Updated: 2020/04/23 00:49:10 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"
#include <string.h>

void print_data(void *data)
{
	printf("%s\n", (char *)data);
}

int main(void)
{

	t_graph	*graph = graph_init(5);
	graph_traverse(graph, print_data);
	printf("\n");

	graph_set_data(graph, 0, strdup("a"));
	graph_set_data(graph, 1, strdup("b"));
	graph_set_data(graph, 2, strdup("c"));
	graph_set_data(graph, 3, strdup("d"));
	graph_set_data(graph, 4, strdup("e"));
	graph_traverse(graph, print_data);
	printf("\n");

	graph_set_edge(graph, 0, 1, true);
	graph_traverse(graph, print_data);
	printf("\n");

	graph_set_edge(graph, 0, 2, true);
	graph_traverse(graph, print_data);
	printf("\n");

	graph_set_edge(graph, 1, 2, true);
	graph_traverse(graph, print_data);
	printf("\n");

	graph_set_edge(graph, 3, 2, true);
	graph_traverse(graph, print_data);
	printf("\n");

	graph_set_edge(graph, 3, 4, true);
	graph_traverse(graph, print_data);
	printf("\n");

	graph_set_edge(graph, 1, 0, false);
	graph_traverse(graph, print_data);
	printf("\n");

	graph_set_edge(graph, 3, 0, true);
	graph_traverse(graph, print_data);
	printf("\n");

	graph_set_edge(graph, 3, 2, false);
	graph_traverse(graph, print_data);
	printf("\n");

	graph_set_edge(graph, 2, 4, true);
	graph_traverse(graph, print_data);
	printf("\n");

	printf("0번 data = %s\n", graph_get_data(graph, 0));
	printf("1번 data = %s\n", graph_get_data(graph, 1));
	printf("1, 4번 edge = %d\n", graph_get_edge(graph, 1, 4));
	printf("2, 3번 edge = %d\n", graph_get_edge(graph, 2, 3));
	printf("0, 1번 edge = %d\n\n", graph_get_edge(graph, 0, 1));

	free_graph(graph, free);


	system("leaks a.out > leaks_result && cat leaks_result | grep leaked");

	return (0);
}
