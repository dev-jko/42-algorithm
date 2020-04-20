/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 15:33:58 by jko               #+#    #+#             */
/*   Updated: 2020/04/20 17:21:16 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int		ft_strcmp(const char *s1, const char *s2)
{
	uint	i;

	if (!s1 && !s2)
		return (0);
	else if (!s2)
		return (s1[0]);
	else if (!s1)
		return (-s2[0]);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

t_hash_map		*map_init(void)
{
	t_hash_map	*map;
	int			i;

	if (!(map = malloc(sizeof(t_hash_map))))
		return (0);
	if (!(map->map = malloc(sizeof(t_node *) * BIG_PRIM)))
	{
		free(map);
		return (0);
	}
	i = 0;
	while (i < BIG_PRIM)
	{
		map->map[i] = 0;
		i++;
	}
	map->size = 0;
	return (map);
}

static t_node	*create_elem(const char *key, void *value)
{
	t_node	*node;

	if (!(node = malloc(sizeof(t_node))))
		return (0);
	node->key = key;
	node->value = value;
	node->next = 0;
	return (node);
}

static uint		get_hash(const char *key)
{
	uint	hash;
	uint	i;

	if (!key)
		return (0);
	hash = 0;
	i = 0;
	while (key[i])
	{
		hash = (hash * POWER + key[i]) % BIG_PRIM;
		i++;
	}
	return (hash);
}

int				map_insert(t_hash_map *map, const char *key, void *value)
{
	uint	hash;
	t_node	*new;
	t_node	*curr;
	int		cmp_result;

	if (!map || !(new = create_elem(key, value)))
		return (0);
	hash = get_hash(key);
	if (!map->map[hash])
	{
		map->map[hash] = new;
		map->size++;
		return (1);
	}
	curr = map->map[hash];
	while (!(cmp_result = ft_strcmp(key, curr->key)) && curr->next)
			curr = curr->next;
	if (cmp_result == 0)
	{
		free(new);
		return (0);
	}
	curr->next = new;
	map->size++;
	return (1);
}

void			*map_get(t_hash_map *map, const char *key)
{
	uint	hash;
	t_node	*curr;

	if (!map)
		return (0);
	hash = get_hash(key);
	curr = map->map[hash];
	while (curr)
	{
		if (ft_strcmp(key, curr->key) == 0)
			return (curr->value);
		curr = curr->next;
	}
	return (0);
}

void			*map_delete(t_hash_map *map, const char *key)
{
	uint	hash;
	t_node	*prev;
	t_node	*curr;
	void	*value;

	if (!map)
		return (0);
	hash = get_hash(key);
	prev = 0;
	curr = map->map[hash];
	while (curr)
	{
		if (ft_strcmp(key, curr->key) == 0)
			break ;
		prev = curr;
		curr = curr->next;
	}
	if (!curr)
		return (0);
	if (prev)
		prev->next = curr->next;
	else
		map->map[hash] = curr->next;
	map->size--;
	value = curr->value;
	free(curr);
	return (value);
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
		free_data(temp->value);
		free(temp);
	}
}

void			free_map(t_hash_map *map, void (*free_data)(void *))
{
	t_node	*curr;
	t_node	*temp;
	int		i;

	if (!map || !free_data)
		return ;
	i = 0;
	while (i < BIG_PRIM)
	{
		lst_clear(map->map[i], free_data);
		i++;
	}
	free(map->map);
	free(map);
}
