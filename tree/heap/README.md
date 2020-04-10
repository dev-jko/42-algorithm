# Heap

[뒤로 가기](..)

## exercise 00
- allowed functions : malloc, free
- heap을 구현 합니다.
- 아래와 같은 heap.h를 사용 합니다.
	```
	typedef struct	s_heap
	{
		unsigned int	max_size;
		unsigned int	size;
		int				(*cmp)(void *, void *);
		void			**data;
	}				t_heap;
	```

### heap_init
- t_heap형 struct를 반환 하는 함수를 작성하세요.
- 반환되는 t_heap는 메모리 할당과 초기화를 거쳐야합니다.
- cmp는 t_node의 data를 비교하는데 사용 됩니다. 첫번째 인자가 더 크면 양수, 작으면 음수, 같다면 0을 반환 합니다.
	```
	t_heap *heap_init(unsigned int max_size, int (*cmp)(void *, void *));
	```

### heap_push
- heap에 data를 삽입하는 함수를 작성하세요.
- data는 부모의 data보다 크거나 같아야 합니다.(min heap)
- 성공하면 1, 실패하면 0을 반환 합니다.
	```
	int heap_push(t_heap *heap, void *data);
	```

### heap_peek
- heap의 root에 있는 data를 반환하는 함수를 작성하세요.
	```
	void *heap_peek(t_heap *heap);
	```

### heap_pop
- heap의 root에 있는 data를 꺼내는 함수를 작성하세요.
	```
	void *heap_pop(t_heap *heap);
	```

### free_heap
- heap에 있는 data 전체를 삭제하고 heap의 메모리 할당을 해제하는 함수를 작성하세요.
- data는 free_data를 사용해서 메모리 할당을 해제해야 합니다.
	```
	void free_heap(t_heap *heap, void (*free_data)(void *));
	```


[뒤로 가기](..)
