# Doubly Linked List

[뒤로 가기](..)

## exercise 00
- allowed functions : malloc, free
- 아래와 같은 list.h를 사용 합니다.
	```
	typedef struct	s_node
	{
		int		data;
		struct s_node	*prev;
		struct s_node	*next;
	}		t_node;

	typedef struct	s_linked_list
	{
		unsigned int	size;
		t_node		*head;
		t_node		*tail;
	}		t_linked_list;
	```

### list_init
- t_linked_list형 struct를 반환 하는 함수를 작성하세요.
- 반환되는 t_linked_list는 메모리 할당과 초기화를 거쳐야합니다.
	```
	t_linked_list *list_init(void);
	```

### create_elem
- t_node형 새로운 요소를 생성하는 함수를 작성하세요.
	```
	t_node *create_elem(int data);
	```

### list_size
- 목록에 있는 요소의 개수를 반환하는 함수를 작성하세요.
	```
	int list_size(t_linked_list *list);
	```

### list_get
- 목록에서 n번 인덱스의 요소를 반환하는 함수를 작성하세요.
- 목록에 있는 요소의 수가 더 적을 땐, 널포인터를 반환 합니다.
	```
	t_node *list_get(t_linked_list *list, int n);
	```

### list_add
- 목록의 n번 인덱스에 data를 갖는 새로운 요소를 생성하는 함수를 작성하세요.
- n이 목록의 요소의 수보다 클 경우엔 마지막 위치에 생성하세요.
- 생성된 요소의 인덱스를 반환 합니다.
	```
	int list_add(t_linked_list *list, int data, int n);
	```

### list_remove
- 목록에서 n번 인덱스의 요소를 삭제하는 함수를 작성하세요.
- 삭제에 성공 했을 때는 1, 실패 했을 때는 0을 반환 합니다.
	```
	int list_remove(t_linked_list *list, int n);
	```

### list_clear
- 목록에 있는 전체 요소를 삭제하는 함수를 작성하세요.
	```
	void list_clear(t_linked_list *list);
	```

### free_list
- 목록의 메모리 할당을 해제하는 함수를 작성하세요.
- 목록에 있는 요소와 목록 모두 해제해야 합니다.
	```
	void free_list(t_linked_list *list);
	```


## grademe
- `grademe.sh`, `grademe_files`가 있는 디렉토리에 소스코드를 넣는다 (main함수는 지우거나 주석처리)
- 터미널 명령어 `sh ./grademe.sh`를 입력


[뒤로 가기](..)
