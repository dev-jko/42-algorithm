/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 16:21:10 by jko               #+#    #+#             */
/*   Updated: 2020/04/12 16:24:03 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIE_H
# define TRIE_H

# include <stdbool.h>

typedef struct	s_node
{
	struct	s_node	*next[26];
	bool			finish;
}				t_node;

typedef struct	s_trie
{
	t_node	*root[26];
}				t_trie;

t_trie	*trie_init(void);
bool	trie_insert(t_trie *trie, char *str);
bool	trie_find(t_trie *trie, char *str);
void	free_trie(t_trie *trie);

#endif
