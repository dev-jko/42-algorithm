# Deque(Linked List)

[뒤로 가기](..)

## exercise 00
- allowed functions : malloc, free
- linked list를 사용하여 deque을 구현 합니다.
- 아래와 같은 deque.h를 사용 합니다.
	```
	typedef struct	s_node
	{
		void		*data;
		struct s_node	*prev;
		struct s_node	*next;
	}		t_node;

	typedef struct	s_deque
	{
		unsigned int	size;
		t_node		*front;
		t_node		*back;
	}		t_deque;
	```

### deque_init
- t_deque형 struct를 반환 하는 함수를 작성하세요.
- 반환되는 t_deque는 메모리 할당과 초기화를 거쳐야합니다.
	```
	t_deque *deque_init(void);
	```

### create_elem
- t_node형 새로운 요소를 생성하는 함수를 작성하세요.
	```
	t_node *create_elem(void *data);
	```
	
### deque_push_front
- deque의 가장 앞에 data를 갖는 새로운 요소를 생성하는 함수를 작성하세요.
- 성공하면 1, 실패하면 0을 반환 합니다.
	```
	int deque_push_front(t_deque *deque, void *data);
	```

### deque_push_back
- deque의 가장 뒤에 data를 갖는 새로운 요소를 생성하는 함수를 작성하세요.
- 성공하면 1, 실패하면 0을 반환 합니다.
	```
	int deque_push_back(t_deque *deque, void *data);
	```

### deque_size
- deque에 있는 요소의 개수를 반환하는 함수를 작성하세요.
	```
	int deque_size(t_deque *deque);
	```

### deque_front
- deque에서 가장 앞에 있는 요소를 반환하는 함수를 작성하세요.
	```
	t_node *deque_front(t_deque *deque);
	```

### deque_back
- deque에서 가장 뒤에 있는 요소를 반환하는 함수를 작성하세요.
	```
	t_node *deque_back(t_deque *deque);
	```

### deque_pop_front
- deque에서 가장 앞에 있는 요소를 꺼내는 함수를 작성하세요.
	```
	t_node *deque_pop_front(t_deque *deque);
	```

### deque_pop_back
- deque에서 가장 뒤에 있는 요소를 꺼내는 함수를 작성하세요.
	```
	t_node *deque_pop_back(t_deque *deque);
	```

### deque_clear
- deque의 요소 전체를 삭제하는 함수를 작성하세요.
- 요소의 데이터는 free_data를 사용해서 메모리 할당을 해제해야 합니다.
	```
	void deque_clear(t_deque *deque, void (*free_data)(void *));
	```

### free_deque
- deque에 있는 요소 전체를 삭제하고 deque의 메모리 할당을 해제하는 함수를 작성하세요.
- 요소의 데이터는 free_data를 사용해서 메모리 할당을 해제해야 합니다.
	```
	void free_deque(t_deque *deque, void (*free_data)(void *));
	```


[뒤로 가기](..)
