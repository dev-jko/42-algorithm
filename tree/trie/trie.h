#include <stdbool.h>

typedef struct	s_node
{
	struct	s_node	*next[26];
	bool			finish;
}				t_node;

typedef t_node	*t_trie[26];
