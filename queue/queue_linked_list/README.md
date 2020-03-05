# Queue(Linked List)

[뒤로 가기](..)

## exercise 00
- allowed functions : malloc, free
- linked list를 사용하여 queue를 구현 합니다.
- 아래와 같은 queue.h를 사용 합니다.
	```
	typedef struct	s_node
	{
		void		*data;
		struct s_node	*next;
	}		t_node;

	typedef struct	s_queue
	{
		unsigned int	size;
		t_node		*head;
		t_node		*tail;
	}		t_queue;
	```

### queue_init
- t_queue형 struct를 반환 하는 함수를 작성하세요.
- 반환되는 t_queue는 메모리 할당과 초기화를 거쳐야합니다.
	```
	t_queue *queue_init(void);
	```

### create_elem
- t_node형 새로운 요소를 생성하는 함수를 작성하세요.
	```
	t_node *create_elem(void *data);
	```
	
### queue_push
- queue의 가장 뒤에 data를 갖는 새로운 요소를 생성하는 함수를 작성하세요.
- 성공하면 1, 실패하면 0을 반환 합니다.
	```
	int queue_push(t_queue *queue, void *data);
	```

### queue_size
- queue에 있는 요소의 개수를 반환하는 함수를 작성하세요.
	```
	int queue_size(t_queue *queue);
	```

### queue_front
- queue에서 가장 앞에 있는 요소를 반환하는 함수를 작성하세요.
	```
	t_node *queue_front(t_queue *queue);
	```

### queue_pop
- queue에서 가장 앞에 있는 요소를 꺼내는 함수를 작성하세요.
	```
	t_node *queue_pop(t_queue *queue);
	```

### queue_clear
- queue의 요소 전체를 삭제하는 함수를 작성하세요.
- 요소의 데이터는 free_data를 사용해서 메모리 할당을 해제해야 합니다.
	```
	void queue_clear(t_queue *queue, void (*free_data)(void *));
	```

### free_queue
- queue에 있는 요소 전체를 삭제하고 queue의 메모리 할당을 해제하는 함수를 작성하세요.
- 요소의 데이터는 free_data를 사용해서 메모리 할당을 해제해야 합니다.
	```
	void free_queue(t_queue *queue, void (*free_data)(void *));
	```


[뒤로 가기](..)
