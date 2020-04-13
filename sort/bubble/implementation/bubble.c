/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 00:07:02 by jko               #+#    #+#             */
/*   Updated: 2020/04/14 00:12:58 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	bubble_sort(void **items, int size, int (*cmp)(void *, void *))
{
	int		i;
	int		j;
	void	*temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (cmp(items[j], items[j + 1]) > 0)
			{
				temp = items[j];
				items[j] = items[j + 1];
				items[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
