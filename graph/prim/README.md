# Prim

[뒤로 가기](..)

## exercise 00
- allowed functions : malloc, free
- Prim 알고리즘을 구현 합니다.
- 아래와 같은 weighted undirected graph(adjacency list)를 사용합니다.
	```
	typedef unsigned int uint;

	typedef struct s_node
	{
		unsigned int vertex;
		int cost;
		struct s_node *next;
	} t_node;

	typedef struct s_graph
	{
		unsigned int size;
		void **data;
		t_node **list;
	} t_graph;

	t_graph *graph_init(uint size);
	bool graph_set_data(t_graph *graph, uint vertex, void *data);
	void *graph_get_data(t_graph *graph, uint vertex);
	bool graph_set_edge(t_graph *graph,uint vertex1, uint vertex2, bool state, int cost);
	bool graph_get_edge(t_graph *graph,uint vertex1, uint vertex2, int *cost);
	void free_graph(t_graph *graph, void (*free_data)(void *));
	```

### make_mst
- src의 minimum spanning tree를 만들어 반환하는 함수를 작성하세요.
- Prim algorithm을 이용하여 MST를 찾습니다.
- 반환되는 t_graph는 새로 메모리를 할당하여 MST를 이루는데 필요한 edge만을 연결한 것입니다.(data는 복사하지 않습니다.)
- 실패 시 null pointer를 반환합니다.
	```
	t_graph *make_mst(const t_graph *src);
	```


[뒤로 가기](..)
