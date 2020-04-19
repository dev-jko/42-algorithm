# Hash Set

[뒤로 가기](..)

## exercise 00
- allowed functions : malloc, free
- hash set을 구현 합니다.
- 아래와 같은 set.h를 사용 합니다.
	```
	typedef struct	s_node
	{
		void	*data;
		struct s_node	*next;
	}				t_node;

	typedef struct	s_hash_set
	{
		unsigned int	size;
		t_node			**set;
		int				(*cmp)(void *, void *);
	}				t_hash_set;
	```

### set_init
- t_hash_set형 struct를 반환 하는 함수를 작성하세요.
- 반환되는 t_hash_set은 메모리 할당과 초기화를 거쳐야합니다.
- cmp는 t_node의 data를 비교하는데 사용 됩니다. 첫번째 인자가 더 크면 양수, 작으면 음수, 같다면 0을 반환합니다.
	```
	t_hash_set	*set_init(int (*cmp)(void *, void *));
	```

### set_insert
- hash set에 data를 삽입하는 함수를 작성하세요.
- hash collision 발생 시 linked list를 사용하여 chaining합니다.
- 삽입에 성공하면 1, 실패하면 0을 반환합니다.
- 이미 hash set 안에 존재하는 data를 삽입하면 실패합니다.
	```
	int set_insert(t_hash_set *set, void *data, unsigned int data_size);
	```

### set_exists
- hash set 안에 data가 존재하는지 확인하는 함수를 작성하세요.
- 존재한다면 1, 없다면 0을 반환합니다.
	```
	int set_exists(t_hash_set *set, void *data, unsigned int data_size);
	```

### set_delete
- hash set에서 data를 삭제하는 함수를 작성하세요.
- 삭제에 성공하면 1, 실패하면 0을 반환합니다.
- hash set 안에 없는 data를 삭제하려 하면 성공으로 간주합니다.
- data는 free_data를 사용해서 메모리 할당을 해제해야합니다.
	```
	int set_delete(t_hash_set *set, void *data, unsigned int data_size, void (*free_data)(void *));
	```

### free_set
- hash set에 있는 data 전체를 삭제하고 hash set의 메모리 할당을 해제하는 함수를 작성하세요.
- data는 free_data를 사용해서 메모리 할당을 해제해야합니다.
	```
	void free_set(t_hash_set *set, void (*free_data)(void *));
	```


[뒤로 가기](..)
