typedef struct	s_node
{
	void		*data;
	struct s_node	*next;
}		t_node;

typedef struct s_stack
{
	unsigned int	size;
	t_node		*top;
}		t_stack;
