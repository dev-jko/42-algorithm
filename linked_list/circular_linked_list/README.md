# Circular Linked List

[뒤로 가기](..)

## exercise 00
- 아래와 같은 list.h를 사용 합니다.
	```
		typedef struct	s_list
		{
			int		data;
			struct s_list	*prev;
			struct s_list	*next;
		}		t_list;

	```

### create_elem
- t_list형 새로운 요소를 생성하는 함수를 작성하세요.
	```
	t_list *create_elem(int data);
	```

### list_add1
- t_list형 새로운 요소를 목록의 맨 뒤에 추가하는 함수를 작성하세요.
- 인덱스 번호를 반환 합니다.(0부터 시작)
	```
	int list_add1(t_list **begin_list, int data);
	```

### list_size
- 목록에 있는 요소의 개수를 반환하는 함수를 작성하세요.
	```
	int list_size(t_list *begin_list);
	```

### list_get
- 목록에서 n번 인덱스의 요소를 반환하는 함수를 작성하세요.
- 목록에 있는 요소의 수가 더 적을 땐, 널포인터를 반환 합니다.
	```
	t_list *list_get(t_list *begin_list, int n);
	```

## list_find
- 목록에서 data의 값이 같은 요소를 반환하는 함수를 작성하세요.
- 없을 경우엔 널포인터를 반환 합니다.
	```
	t_list *list_find(t_list *begin_list, int data);
	```

## list_remove
- 목록에서 n번 인덱스의 요소를 삭제하는 함수를 작성하세요.
- 삭제에 성공 했을 때는 1, 실패 했을 때는 0을 반환 합니다.
	```
	int list_remove(t_list **begin_list, int n);
	```
	
## list_add
- 목록의 n번 인덱스에 data를 갖는 새로운 요소를 생성하는 함수를 작성하세요.
- n이 목록의 요소의 수보다 클 경우엔 마지막 위치에 생성하세요.
- 생성된 요소의 인덱스를 반환 합니다.
	```
	int list_add(t_list **begin_list, int data, int n);
	```

[뒤로 가기](..)
