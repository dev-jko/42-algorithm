/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 16:24:17 by jko               #+#    #+#             */
/*   Updated: 2020/04/12 19:30:52 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trie.h"

t_trie			*trie_init(void)
{
	t_trie	*trie;
	int		i;

	trie = malloc(sizeof(t_trie));
	if (!trie)
		return (0);
	i = 0;
	while (i < 26)
	{
		(*trie)[i] = 0;
		i++;
	}
	return (trie);
}

static t_node	*create_node(void)
{
	t_node	*node;
	int		i;

	node = malloc(sizeof(t_node));
	if (!node)
		return (0);
	i = 0;
	while (i < 26)
	{
		node->next[i] = 0;
		i++;
	}
	node->finish = false;
	return (node);
}

static bool		insert_str(t_node *node, char *str)
{
	if (!node || !str)
		return (false);
	if (!str[0])
	{
		node->finish = true;
		return (true);
	}
	if (!node->next[str[0] - 'a'])
		node->next[str[0] - 'a'] = create_node();
	return (insert_str(node->next[str[0] - 'a'], str + 1));
}

bool			trie_insert(t_trie *trie, char *str)
{
	if (!trie || !str || !str[0])
		return (false);
	if (!(*trie)[str[0] - 'a'])
		(*trie)[str[0] - 'a'] = create_node();
	return (insert_str((*trie)[str[0] - 'a'], str + 1));
}

static bool		find_str(t_node *node, char *str)
{
	if (!node || !str)
		return (false);
	if (!str[0])
		return (node->finish);
	if (!node->next[str[0] - 'a'])
		return (false);
	return (find_str(node->next[str[0] -'a'], str + 1));
}

bool			trie_find(t_trie *trie, char *str)
{
	if (!trie || !str || !str[0])
		return (false);
	return (find_str((*trie)[str[0] - 'a'], str + 1));
}

static void		free_node(t_node *node)
{
	int	i;

	if (!node)
		return ;
	i = 0;
	while (i < 26)
	{
		free_node(node->next[i]);
		i++;
	}
	free(node);
}

void			free_trie(t_trie *trie)
{
	int	i;

	if (!trie)
		return ;
	i = 0;
	while (i < 26)
	{
		free_node((*trie)[i]);
		i++;
	}
	free(trie);
}
