# Trie

[뒤로 가기](..)

## exercise 00
- allowed functions : malloc, free
- trie을 구현 합니다.
- 아래와 같은 trie.h를 사용 합니다.
	```
	#include <stdbool.h>

	typedef struct	s_node
	{
		struct	s_node	*next[26];
		bool			finish;
	}				t_node;

	typedef t_node	*t_trie[26];
	```

### trie_init
- t_trie형 struct를 반환 하는 함수를 작성하세요.
- 반환되는 t_trie는 메모리 할당과 초기화를 거쳐야합니다.
	```
	t_trie	*trie_init(void);
	```

### trie_insert
- trie에 문자열 str을 삽입하는 함수를 작성하세요.
- str은 a ~ z만으로 이루어진 문자열 입니다.
- 성공하면 true, 실패하면 false를 반환 합니다.
	```
	bool	trie_insert(t_trie *trie, char *str);
	```

### trie_find
- trie에서 문자열 str이 있는지 검색하는 함수를 작성하세요.
- str은 a ~ z만으로 이루어진 문자열 입니다.
- str이 존재하면 true, 없으면 false를 반환 합니다.
	```
	bool	trie_find(t_trie *trie, char *str);
	```

### free_trie
- trie에 있는 요소 전체를 삭제하고 trie의 메모리 할당을 해제하는 함수를 작성하세요.
	```
	void	free_trie(t_trie *trie);
	```


[뒤로 가기](..)
