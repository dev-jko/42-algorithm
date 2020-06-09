# Floyd-Warshall

[뒤로 가기](..)

## exercise 00
- allowed functions : malloc, free
- Floyd-Warshall 알고리즘을 구현 합니다.
- 아래와 같은 weighted directed graph(adjacency list)를 사용합니다.
	```
	typedef unsigned int uint;

	typedef struct		s_node
	{
		unsigned int	vertex;
		int				cost;
		struct s_node	*next;
	}					t_node;

	typedef struct		s_graph
	{
		unsigned int	size;
		void			**data;
		t_node			**list;
	}					t_graph;

	t_graph *graph_init(uint size);
	bool graph_set_data(t_graph *graph, uint vertex, void *data);
	bool graph_set_edge(t_graph *graph, uint start, uint end, bool state, int cost);
	void free_graph(t_graph *graph, void (*free_data)(void *));
	```

### find_shortest_path
- src의 모든 정점에서 모든 정점까지의 최소 비용 경로를 구하는 함수를 작성하세요.
- Floyd-Warshall 알고리즘을 이용하여 최소 비용 경로를 찾습니다.
- src의 edge에 음수 가중치가 있을 수 있습니다.
- 성공 시 모든 정점에서 모든 정점까지의 경로의 최소 비용을 가진 2차원 int 배열을 반환합니다.
- 실패 시 null-pointer를 반환합니다.
	```
	int **find_shortest_path(const t_graph *src);
	```


[뒤로 가기](..)
