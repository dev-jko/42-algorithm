/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 16:36:35 by jko               #+#    #+#             */
/*   Updated: 2020/04/05 19:18:55 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "queue.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	print_queue(t_queue *queue)
{
	if (!queue)
	{
		printf("queue == null_ptr\n");
		return ;
	}
	printf("print queue start\n");
	for (int i = 0; i <= queue->last_index; ++i) {
		printf("q [%d] -> %s\n", i, queue->data[i]);
	}
	printf("end\n\n");
}

int main(void)
{
	char *temp;
	t_queue *queue = queue_init(5);
	printf("size = %d\n", queue_size(queue));
	printf("front->data = %s\n", queue_front(queue));
	print_queue(queue);
	
	queue_push(queue, strdup("aa"));
	printf("size = %d\n", queue_size(queue));
	printf("front->data = %s\n", queue_front(queue));
	print_queue(queue);

	queue_push(queue, strdup("b"));
	printf("size = %d\n", queue_size(queue));
	printf("front->data = %s\n", queue_front(queue));
	print_queue(queue);

	queue_push(queue, strdup("ccc"));
	printf("size = %d\n", queue_size(queue));
	printf("front->data = %s\n", queue_front(queue));
	print_queue(queue);

	queue_push(queue, strdup("ddddd"));
	printf("size = %d\n", queue_size(queue));
	printf("front->data = %s\n", queue_front(queue));
	print_queue(queue);

	queue_push(queue, strdup("ee"));
	printf("size = %d\n", queue_size(queue));
	printf("front->data = %s\n", queue_front(queue));
	print_queue(queue);

	temp = strdup("f");
	queue_push(queue, temp);
	printf("size = %d\n", queue_size(queue));
	printf("front->data = %s\n", queue_front(queue));
	print_queue(queue);
	free(temp);

	printf("=============== pop ===============\n");
	for (int i = 0; i < 9; i++)
	{
		temp = queue_pop(queue);
		printf("pop = %s\n", temp);
		free(temp);
		printf("size = %d\n", queue_size(queue));
		printf("front->data = %s\n", queue_front(queue));
		print_queue(queue);
	}

	queue_clear(queue, free);
	print_queue(queue);

	queue_push(queue, strdup("e22"));
	printf("size = %d\n", queue_size(queue));
	printf("front->data = %s\n", queue_front(queue));
	print_queue(queue);

	queue_push(queue, strdup("f22"));
	printf("size = %d\n", queue_size(queue));
	printf("front->data = %s\n", queue_front(queue));
	print_queue(queue);
	
	free_queue(queue, free);

	queue = 0;
	system("leaks a.out > leaks_result && cat leaks_result | grep leaked");
	return (0);
}
