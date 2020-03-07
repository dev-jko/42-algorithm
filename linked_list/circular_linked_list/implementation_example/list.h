/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 00:04:33 by jko               #+#    #+#             */
/*   Updated: 2020/03/08 00:10:52 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>

typedef struct	s_node
{
	void		*data;
	struct s_node	*prev;
	struct s_node	*next;
}		t_node;

typedef struct	s_linked_list
{
	unsigned int	size;
	t_node		*head;
}		t_linked_list;


t_linked_list	*list_init(void);
t_node		*create_elem(void *data);
int		list_add(t_linked_list *list, void *data, int n);
int		list_size(t_linked_list *list);
t_node		*list_get(t_linked_list *list, int n);
int		list_find(t_linked_list *list, void* data, int (*cmp)(void *data1, void *data2));
void		list_remove(t_linked_list *list, int n, void (*free_data)(void *));
void		list_clear(t_linked_list *list, void (*free_data)(void *));
void		free_list(t_linked_list *list, void (*free_data)(void *));
void		list_foreach(t_linked_list *list, void (*f)(void *));
void		list_move_head_to_next(t_linked_list *list);
void		list_move_head_to_prev(t_linked_list *list);

#endif
