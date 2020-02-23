# Trie

작성 중....

[뒤로 가기](..)

## exercise 00
- allowed functions : malloc, free
- trie을 구현 합니다.
- 아래와 같은 trie.h를 사용 합니다.
	```
	typedef struct	s_trie
	{
		unsigned int	max_size;
		void		**data;
	}		t_trie;
	```

### trie_init
- t_trie형 struct를 반환 하는 함수를 작성하세요.
- 반환되는 t_trie는 메모리 할당과 초기화를 거쳐야합니다.
- cmp는 t_node의 data를 비교하는데 사용 됩니다. 첫번째 인자가 더 크면 양수, 작으면 음수, 같다면 0을 반환 합니다.
	```
	t_trie *trie_init(void);
	```

### trie_push
- trie에 data를 삽입하는 함수를 작성하세요.
- data는 부모의 data보다 크거나 같아야 합니다.
- 성공하면 1, 실패하면 0을 반환 합니다.
	```
	int trie_insert(t_trie *trie, void *data);
	```

### free_trie
- trie에 있는 data 전체를 삭제하고 trie의 메모리 할당을 해제하는 함수를 작성하세요.
- data는 free_data를 사용해서 메모리 할당을 해제해야 합니다.
	```
	void free_trie(t_trie *trie, void (*free_data)(void *));
	```


[뒤로 가기](..)
