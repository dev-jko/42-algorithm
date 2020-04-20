/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 20:45:39 by jko               #+#    #+#             */
/*   Updated: 2020/04/20 15:36:59 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

t_hash_set		*set_init(int (*cmp)(void *, void *))
{
	t_hash_set	*set;
	int			i;

	if (!cmp || !(set = malloc(sizeof(t_hash_set))))
		return (0);
	if (!(set->set = malloc(sizeof(t_node *) * BIG_PRIM)))
	{
		free(set);
		return (0);
	}
	i = 0;
	while (i < BIG_PRIM)
	{
		set->set[i] = 0;
		i++;
	}
	set->cmp = cmp;
	set->size = 0;
	return (set);
}

static t_node	*create_elem(void *data)
{
	t_node	*node;

	if (!(node = malloc(sizeof(t_node))))
		return (0);
	node->data = data;
	node->next = 0;
	return (node);
}

static uint		get_hash(void *data, uint data_size)
{
	uint	hash;
	uint	i;
	char	*temp;

	if (!data || data_size == 0)
		return (0);
	temp = (char *)data;
	hash = 0;
	i = 0;
	while (i < data_size)
	{
		hash = (hash * POWER + temp[i]) % BIG_PRIM;
		i++;
	}
	return (hash);
}

int				set_insert(t_hash_set *set, void *data, uint data_size)
{
	uint	hash;
	t_node	*new;
	t_node	*curr;
	int		cmp_result;

	if (!set || !(new = create_elem(data)))
		return (0);
	hash = get_hash(data, data_size);
	if (!set->set[hash])
	{
		set->set[hash] = new;
		set->size++;
		return (1);
	}
	curr = set->set[hash];
	while (!(cmp_result = set->cmp(data, curr->data)) && curr->next)
			curr = curr->next;
	if (cmp_result == 0)
	{
		free(new);
		return (0);
	}
	curr->next = new;
	set->size++;
	return (1);
}

int				set_exists(t_hash_set *set, void *data, uint data_size)
{
	uint	hash;
	t_node	*curr;

	if (!set)
		return (0);
	hash = get_hash(data, data_size);
	curr = set->set[hash];
	while (curr)
	{
		if (set->cmp(data, curr->data) == 0)
			return (1);
		curr = curr->next;
	}
	return (0);
}

int				set_delete(
		t_hash_set *set,
		void *data, uint data_size,
		void (*free_data)(void *))
{
	uint	hash;
	t_node	*prev;
	t_node	*curr;

	if (!set || !free_data)
		return (0);
	hash = get_hash(data, data_size);
	prev = 0;
	curr = set->set[hash];
	while (curr)
	{
		if (set->cmp(data, curr->data) == 0)
			break ;
		prev = curr;
		curr = curr->next;
	}
	if (!curr)
		return (1);
	if (prev)
		prev->next = curr->next;
	else
		set->set[hash] = curr->next;
	set->size--;
	free_data(curr->data);
	free(curr);
	return (1);
}

static	void	lst_clear(t_node *node, void (*free_data)(void *))
{
	t_node	*temp;

	if (!node || !free_data)
		return ;
	while (node)
	{
		temp = node;
		node = node->next;
		free_data(temp->data);
		free(temp);
	}
}

void			free_set(t_hash_set *set, void (*free_data)(void *))
{
	t_node	*curr;
	t_node	*temp;
	int		i;

	if (!set || !free_data)
		return ;
	i = 0;
	while (i < BIG_PRIM)
	{
		lst_clear(set->set[i], free_data);
		i++;
	}
	free(set->set);
	free(set);
}
