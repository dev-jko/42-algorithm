typedef struct	s_list
{
	int		data;
	struct s_list	*prev;
	struct s_list	*next;
}		t_list;

typedef struct s_linked_list
{
	unsigned int	size;
	t_node		**head;
	t_node		**tail;
}		t_linked_list;
