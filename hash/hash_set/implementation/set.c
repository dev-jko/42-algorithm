/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 20:45:39 by jko               #+#    #+#             */
/*   Updated: 2020/04/19 20:46:25 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

t_hash_set	*set_init(int (*cmp)(void *, void *))
{
}

int			set_insert(t_hash_set *hash_set, void *data)
{
}

int			set_exists(t_hash_set *set, void *data)
{
}

int			set_delete(t_hash_set *set,void *data, void (*free_data)(void *))
{
}

void		free_set(t_hash_set *set, void (*free_data)(void *))
{
}
