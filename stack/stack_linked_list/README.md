# Stack(Linked List)

[뒤로 가기](..)

## exercise 00
- allowed functions : malloc, free
- linked list를 사용하여 stack을 구현 합니다.
- 아래와 같은 stack.h를 사용 합니다.
	```
	typedef struct	s_node
	{
		void		*data;
		struct s_node	*next;
	}		t_node;

	typedef struct	s_stack
	{
		unsigned int	size;
		t_node		*top;
	}		t_stack;
	```

### stack_init
- t_stack형 struct를 반환 하는 함수를 작성하세요.
- 반환되는 t_stack는 메모리 할당과 초기화를 거쳐야합니다.
	```
	t_stack *stack_init(void);
	```

### create_elem
- t_node형 새로운 요소를 생성하는 함수를 작성하세요.
	```
	t_node *create_elem(void *data);
	```
	
### stack_push
- stack의 가장 위에 data를 갖는 새로운 요소를 생성하는 함수를 작성하세요.
- 성공하면 1, 실패하면 0을 반환 합니다.
	```
	int stack_push(t_stack *stack, void *data);
	```

### stack_size
- stack에 있는 요소의 개수를 반환하는 함수를 작성하세요.
	```
	int stack_size(t_stack *stack);
	```

### stack_peek
- stack에서 가장 위에 있는 요소를 반환하는 함수를 작성하세요.
	```
	t_node *stack_peek(t_stack *stack);
	```

### stack_pop
- stack에서 가장 위에 있는 요소를 꺼내는 함수를 작성하세요.
- 반환하는 요소의 next를 널포인터로 바꾼후 반환 합니다.
	```
	t_node *stack_pop(t_stack *stack);
	```

### stack_clear
- stack의 요소 전체를 삭제하는 함수를 작성하세요.
- 요소의 데이터는 free_data를 사용해서 메모리 할당을 해제해야 합니다.
	```
	void stack_clear(t_stack *stack, void (*free_data)(void *));
	```

### free_stack
- stack에 있는 요소 전체를 삭제하고 stack의 메모리 할당을 해제하는 함수를 작성하세요.
- 요소의 데이터는 free_data를 사용해서 메모리 할당을 해제해야 합니다.
	```
	void free_stack(t_stack *stack, void (*free_data)(void *));
	```


[뒤로 가기](..)
