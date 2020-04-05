/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 00:50:22 by jko               #+#    #+#             */
/*   Updated: 2020/04/05 19:19:26 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	t_node	*temp;
	t_queue *queue = queue_init();
	printf("size = %d\n", queue_size(queue));
	printf("front->data = %s\n", queue_front(queue) ? queue_front(queue)->data : 0);
	printf("rear->data = %s\n\n", queue ? (queue->tail ? queue->tail->data : 0) : 0);
	
	queue_push(queue, strdup("aa"));
	printf("size = %d\n", queue_size(queue));
	printf("front->data = %s\n", queue_front(queue) ? queue_front(queue)->data : 0);
	printf("rear->data = %s\n\n", queue ? (queue->tail ? queue->tail->data : 0) : 0);

	queue_push(queue, strdup("b"));
	printf("size = %d\n", queue_size(queue));
	printf("front->data = %s\n", queue_front(queue) ? queue_front(queue)->data : 0);
	printf("rear->data = %s\n\n", queue ? (queue->tail ? queue->tail->data : 0) : 0);

	queue_push(queue, strdup("ccc"));
	printf("size = %d\n", queue_size(queue));
	printf("front->data = %s\n", queue_front(queue) ? queue_front(queue)->data : 0);
	printf("rear->data = %s\n\n", queue ? (queue->tail ? queue->tail->data : 0) : 0);

	queue_push(queue, strdup("ddddd"));
	printf("size = %d\n", queue_size(queue));
	printf("front->data = %s\n", queue_front(queue) ? queue_front(queue)->data : 0);
	printf("rear->data = %s\n\n", queue ? (queue->tail ? queue->tail->data : 0) : 0);

	queue_push(queue, strdup("ee"));
	printf("size = %d\n", queue_size(queue));
	printf("front->data = %s\n", queue_front(queue) ? queue_front(queue)->data : 0);
	printf("rear->data = %s\n\n", queue ? (queue->tail ? queue->tail->data : 0) : 0);

	queue_push(queue, strdup("f"));
	printf("size = %d\n", queue_size(queue));
	printf("front->data = %s\n", queue_front(queue) ? queue_front(queue)->data : 0);
	printf("rear->data = %s\n\n", queue ? (queue->tail ? queue->tail->data : 0) : 0);

	printf("=============== pop ===============\n");
	for (int i = 0; i < 9; i++)
	{
		temp = queue_pop(queue);
		printf("pop = %s\n", temp ? temp->data : 0);
		free(temp ? temp->data : 0);
		free(temp);
		printf("size = %d\n", queue_size(queue));
		printf("front->data = %s\n", queue_front(queue) ? queue_front(queue)->data : 0);
		printf("rear->data = %s\n", queue ? (queue->tail ? queue->tail->data : 0) : 0);
	}

	queue_clear(queue, free);

	queue_push(queue, strdup("e22"));
	printf("size = %d\n", queue_size(queue));
	printf("front->data = %s\n", queue_front(queue) ? queue_front(queue)->data : 0);
	printf("rear->data = %s\n\n", queue ? (queue->tail ? queue->tail->data : 0) : 0);

	queue_push(queue, strdup("f22"));
	printf("size = %d\n", queue_size(queue));
	printf("front->data = %s\n", queue_front(queue) ? queue_front(queue)->data : 0);
	printf("rear->data = %s\n\n", queue ? (queue->tail ? queue->tail->data : 0) : 0);
	
	free_queue(queue, free);

	queue = 0;
	system("leaks a.out > leaks_result && cat leaks_result | grep leaked");
	return (0);
}
