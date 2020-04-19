/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rabin_karp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 14:31:41 by jko               #+#    #+#             */
/*   Updated: 2020/04/19 15:41:50 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rabin_karp.h"

static unsigned int	get_strlen(const char *str)
{
	unsigned int len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

long long			get_hash_value(const char *str, unsigned int len)
{
	long long		result;
	unsigned int	str_len;
	unsigned int	i;

	str_len = get_strlen(str);
	len = len < str_len ? len : str_len;
	result = 0;
	i = 0;
	while (i < len)
	{
		result = (result * POWER + str[i]) % BIG_PRIM;
		i++;
	}
	return (result);
}

static char			*find(
		const char *str,
		unsigned int str_len,
		unsigned int pattern,
		unsigned int p_len)
{
	long long		hash;
	unsigned int	i;
	unsigned int	pow;

	hash = get_hash_value(str, p_len);
	if (hash == pattern)
		return ((char *)str);
	pow = 1;
	i = 1;
	while (i++ < p_len)
		pow = pow * POWER % BIG_PRIM;
	i = 1;
	while (i + p_len <= str_len)
	{
		hash = (hash - str[i - 1] * pow) % BIG_PRIM;
		if (hash < 0)
			hash += BIG_PRIM;
		hash = POWER * hash % BIG_PRIM;
		hash = (hash + str[i + p_len - 1]) % BIG_PRIM;
		if (hash == pattern)
			return ((char *)(str + i));
		i++;
	}
	return (0);
}

char				*find_str(const char *haystack, const char *needle)
{
	unsigned int	haystack_len;
	unsigned int	needle_len;
	long long		p;

	if (!haystack)
		return (0);
	if (!needle)
		return ((char *)haystack);
	haystack_len = get_strlen(haystack);
	needle_len = get_strlen(needle);
	if (haystack_len < needle_len)
		return (0);
	p = get_hash_value(needle, needle_len);
	return (find(haystack, haystack_len, p, needle_len));
}
