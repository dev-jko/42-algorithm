typedef struct	s_node
{
	void		*data;
	struct s_node	*next;
}		t_node;

typedef struct	s_queue
{
	unsigned int	size;
	t_node		*head;
	t_node		*tail;
}		t_queue;
