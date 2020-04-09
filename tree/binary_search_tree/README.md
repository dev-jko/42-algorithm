# Binary Search Tree

[뒤로 가기](..)

## exercise 00
- allowed functions : malloc, free
- binary search tree을 구현 합니다.
- 아래와 같은 tree.h를 사용 합니다.
	```
	typedef struct	s_node
	{
		void		*data;
		struct s_node	*left;
		struct s_node	*right;
	}		t_node;

	typedef struct	s_binary_search_tree
	{
		t_node	*root;
		int	(*cmp)(void *, void *);
		int	size;
	}		t_tree;
	```

### tree_init
- t_tree형 struct를 반환 하는 함수를 작성하세요.
- 반환되는 t_tree는 메모리 할당과 초기화를 거쳐야합니다.
- cmp는 t_node의 data를 비교하는데 사용 됩니다. 첫번째 인자가 더 크면 양수, 작으면 음수, 같다면 0을 반환 합니다.
	```
	t_tree *tree_init(int (*cmp)(void *, void *));
	```

### create_elem
- t_node형 새로운 요소를 생성하는 함수를 작성하세요.
	```
	t_node *create_elem(void *data);
	```

### tree_size
- tree에 존재하는 요소의 갯수를 반환하는 함수를 작성하세요.
	```
	int	tree_size(t_tree *tree);
	```

### tree_find
- tree에 data_ref와 같은 data를 갖는 요소를 찾아 반환하는 함수를 작성하세요.
- 같은 요소가 없다면 널 포인터를 반환 합니다.
	```
	t_node *tree_find(t_tree *tree, void *data_ref);
	```

### tree_insert
- tree에 data를 갖는 새로운 요소를 삽입하는 함수를 작성하세요.
- node의 data는 left의 data보다 크고 right의 data보다 작아야 합니다.
- 성공하면 1, 실패하면 0을 반환 합니다.
- 이미 같은 data를 가진 요소가 있다면 실패 합니다.
	```
	int tree_insert(t_tree *tree, void *data);
	```

### tree_delete
- tree에서 data_ref와 같은 data를 가진 요소를 삭제하는 함수를 작성하세요.
- 요소의 데이터는 free_data를 사용해서 메모리 할당을 해제해야 합니다.
- 삭제하려는 node의 child가 2개일 경우에는 node의 오른쪽 subtree 중 가장 작은 data를 가진 child가 node를 대체하여야 합니다.
    - node의 왼쪽 subtree 중 가장 큰 data를 가진 child가 node를 대체하는 방법도 가능하지만 본 예제에서는 위의 방법으로 구현하도록 합니다.
- 성공하면 1, 실패하면 0을 반환 합니다.
- data_ref와 같은 data를 가진 요소가 없다면 실패 합니다.
	```
	int tree_delete(t_tree *tree, void *data_ref, void (*free_data)(void *));
	```

### free_tree
- tree에 있는 요소 전체를 삭제하고 tree의 메모리 할당을 해제하는 함수를 작성하세요.
- 요소의 데이터는 free_data를 사용해서 메모리 할당을 해제해야 합니다.
	```
	void free_tree(t_tree *tree, void (*free_data)(void *));
	```


[뒤로 가기](..)
