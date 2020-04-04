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
