# Circular Linked List

[뒤로 가기](..)

## exercise 00
- allowed functions : malloc, free
- list의 head가 바뀌는 경우는 4가지 입니다.
	1. 빈 list에 노드를 추가할 때(list의 size가 0에서 1이 될 때)
	1. head가 가리키는 노드가 삭제될 때(해당 노드의 next가 head가 됩니다.)
	1. head를 이동하는 함수 list_move_head_to_next를 사용할 때
	1. head를 이동하는 함수 list_move_head_to_prev를 사용할 때
- list의 인덱스는 항상 head가 가리키는 노드가 0번 입니다.
- circular linked list에서는 인덱스가 순환합니다.
	- ex) 사이즈가 5일 때, 0-1-2-3-4-0-1-2-3-4-...
	- 사이즈가 5이고 인덱스 5번 -> 0 (한바퀴 돌아서 다시 0번으로 옴)
	- 사이즈가 5이고 인덱스가 -2번 -> 3 (뒤에서 2번째)
- 아래와 같은 list.h를 사용 합니다.
	```
	typedef struct	s_node
	{
		void		*data;
		struct s_node	*prev;
		struct s_node	*next;
	}		t_node;

	typedef struct	s_linked_list
	{
		unsigned int	size;
		t_node		*head;
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
	t_node *create_elem(void *data);
	```
	
### list_add
- 목록의 n번 인덱스에 data를 갖는 새로운 요소를 생성하는 함수를 작성하세요.
- 생성된 요소의 인덱스를 반환 합니다. (0 혹은 양수)
- 실패 시 -1을 반환 합니다.
	```
	int list_add(t_linked_list *list, void *data, int n);
	```

### list_size
- 목록에 있는 요소의 개수를 반환하는 함수를 작성하세요.
	```
	int list_size(t_linked_list *list);
	```

### list_move_head_to_next
- list의 head를 head의 next로 옮기는 함수를 작성하세요.
	```
	void list_move_head_to_next(t_linked_list *list);
	```

### list_move_head_to_prev
- list의 head를 head의 prev로 옮기는 함수를 작성하세요.
	```
	void list_move_head_to_prev(t_linked_list *list);
	```

### list_get
- 목록에서 n번 인덱스의 요소를 반환하는 함수를 작성하세요.
- 실패 시 널포인터를 반환 합니다.
	```
	t_node *list_get(t_linked_list *list, int n);
	```

### list_find
- 목록에서 data의 값이 같은 요소의 인덱스를 반환하는 함수를 작성하세요. (0 혹은 양수)
- 실패 시 -1를 반환 합니다.
- 매개변수로 주어진 cmp 함수는 두 data가 같으면 0, 다르면 1을 반환 합니다.
	```
	int list_find(t_linked_list *list, void* data, int (*cmp)(void *data1, void *data2));
	```

### list_remove
- 목록에서 n번 인덱스의 요소를 삭제하는 함수를 작성하세요.
- 요소의 데이터는 free_data를 사용해서 메모리 할당을 해제해야 합니다.
	```
	void list_remove(t_linked_list *list, int n, void (*free_data)(void *));
	```

### list_clear
- 목록 전체를 삭제하는 함수를 작성하세요.
- 요소의 데이터는 free_data를 사용해서 메모리 할당을 해제해야 합니다.
	```
	void list_clear(t_linked_list *list, void (*free_data)(void *));
	```

### free_list
- 목록의 메모리 할당을 해제하는 함수를 작성하세요.
- 요소의 데이터는 free_data를 사용해서 메모리 할당을 해제해야 합니다.
- 목록에 있는 요소와 목록 모두 해제해야 합니다.
	```
	void free_list(t_linked_list *list, void (*free_data)(void *));
	```

### list_foreach
- 목록에 있는 모든 요소의 data에 매개변수로 주어진 함수 f를 적용하는 함수를 작성하세요.
	```
	void list_foreach(t_linked_list *list, void (*f)(void *));
	```


## grademe
- `grademe.sh`, `grademe_files`가 있는 디렉토리에 소스코드를 넣는다 (main함수는 지우거나 주석처리)
- 터미널 명령어 `sh ./grademe.sh`를 입력
- 테스트 코드의 출력을 `user_output` 파일로, memory leaks 체크 결과를 `leaks_result` 파일로 생성합니다.
- 결과를 diff -u 명령어로 비교하고 less 명령어로 출력해줍니다.(`u` 위로, `d` 아래로, `q` 종료)

[뒤로 가기](..)
