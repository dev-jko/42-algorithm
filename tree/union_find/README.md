# Union-Find

[뒤로 가기](..)

## exercise 00
- union-find를 구현 합니다.
- allowed functions : malloc, free
- 아래와 같은 union_find.h를 사용 합니다.
	```
	#include <stdbool.h>

	typedef struct	s_node
	{
		struct	s_node	*parent;
		void			*data;
	}				t_node;
	```

### create_elem
- t_node형 새로운 요소를 생성하는 함수를 작성하세요.
	```
	t_node	*create_elem(void *data);
	```

### find
- 주어진 node가 속한 집합의 root node를 반환하는 함수를 작성하세요.
	```
	t_node	*find(t_node *node);
	```

### is_disjoint
- 두 node가 서로소 집합인지 확인하는 함수를 작성하세요.
- 두 node가 같은 집합에 속해 있다면 false, 아니라면 true를 반환 합니다.
	```
	bool	is_disjoint(t_node *node1, t_node *node2);
	```

### union
- 두 node가 속해 있는 집합을 하나로 합하는 함수를 작성하세요.
- 집합을 합한 뒤, 집합의 root node를 반환 합니다.
- 두 집합을 합할 땐, node1의 root node가 두 집합의 root node가 됩니다.
- 두 node가 이미 같은 집합에 속해 있더라도 집합의 root node를 반환합니다.
	```
	t_node	*union_func(t_node *node1, t_node *node2);
	```

[뒤로 가기](..)
