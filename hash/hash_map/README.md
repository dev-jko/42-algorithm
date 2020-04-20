# Hash Map

[뒤로 가기](..)

## exercise 00
- allowed functions : malloc, free
- hash map을 구현 합니다.
- 편의상 key는 string을 사용합니다.
- 아래와 같은 map.h를 사용합니다.
	```
	typedef struct	s_node
	{
		const char	*key;
		void		*value;
		struct s_node	*next;
	}				t_node;

	typedef struct	s_hash_map
	{
		unsigned int	size;
		t_node			**map;
	}				t_hash_map;
	```

### map_init
- t_hash_map형 struct를 반환 하는 함수를 작성하세요.
- 반환되는 t_hash_map은 메모리 할당과 초기화를 거쳐야합니다.
	```
	t_hash_map	*map_init(void);
	```

### map_insert
- hash map에 key, value 쌍을 삽입하는 함수를 작성하세요.
- hash collision 발생 시 linked list를 사용하여 chaining합니다.
- 삽입에 성공하면 1, 실패하면 0을 반환합니다.
- 이미 hash map 안에 존재하는 key를 삽입하면 실패합니다.
	```
	int map_insert(t_hash_map *map, const char *key, void *value);
	```

### map_get
- hash map에서 key와 쌍을 이루는 value를 반환하는 함수를 작성하세요.
- 존재한다면 value를, 없다면 0을 반환합니다.
	```
	void *map_get(t_hash_map *map, const char *key);
	```

### map_delete
- hash map에서 주어진 key와 같은 데이터를 삭제하고 value를 반환하는 함수를 작성하세요.
- 삭제에 성공하면 value를, 실패하면 null pointer를 반환합니다.
- hash map 안에 없는 key를 삭제하려 하면 실패로 간주합니다.
- node->key는 메모리 할당을 해제하지 않습니다.
	```
	void *map_delete(t_hash_map *map, const char *key);
	```

### free_map
- hash map에 있는 key, value 쌍 전체를 삭제하고 hash map의 메모리 할당을 해제하는 함수를 작성하세요.
- node->key는 메모리 할당을 해제하지 않습니다.
- value는 free_data를 사용해서 메모리 할당을 해제해야합니다.
	```
	void free_map(t_hash_map *map, void (*free_data)(void *));
	```


[뒤로 가기](..)
