typedef struct	s_heap
{
	unsigned int	max_size;
	int				(*cmp)(void *, void *);
	void			**data;
}				t_heap;
