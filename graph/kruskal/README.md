# Kruskal

[뒤로 가기](..)

## exercise 00
- allowed functions : malloc, free
- Kruskal 알고리즘을 구현 합니다.
- 이전에 구현했던 undirected graph(adjacency matrix)를 사용합니다.


### make_mst
- src의 minimum spanning tree를 만들어 반환하는 함수를 작성하세요.
- Kruskal algorithm을 이용하여 MST를 찾습니다.
- 반환되는 t_graph는 새로 메모리를 할당하여 MST를 이루는데 필요한 edge만을 연결한 것입니다.
- 실패 시 null pointer를 반환합니다.
	```
	t_graph *make_mst(const t_graph *src);
	```


[뒤로 가기](..)
