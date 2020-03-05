typedef struct	s_node
{
	void		*data;
	struct s_node	*prev;
	struct s_node	*next;
}		t_node;

typedef struct	s_deque
{
	unsigned int	size;
	t_node		*front;
	t_node		*back;
}		t_deque;
