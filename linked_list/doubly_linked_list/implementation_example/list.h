typedef struct	s_node
{
	int		data;
	struct s_node	*prev;
	struct s_node	*next;
}		t_node;

typedef struct	s_linked_list
{
	unsigned int	size;
	t_node		*head;
	t_node		*tail;
}		t_linked_list;
