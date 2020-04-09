typedef struct	s_heap
{
	unsigned int	max_size;
	unsigned int	size;
	int				(*cmp)(void *, void *);
	void			**data;
}				t_heap;
