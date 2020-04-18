/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 17:19:10 by jko               #+#    #+#             */
/*   Updated: 2020/04/18 20:57:02 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rabin_karp.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("hash = %lld\n", get_hash_value(0, 50));
	printf("hash = %lld\n", get_hash_value("", 50));
	printf("hash = %lld\n", get_hash_value("abcdefg", 0));
	printf("hash = %lld\n", get_hash_value("abcdefg", 1));
	printf("hash = %lld\n", get_hash_value("abcdefg", 50));

	printf("find result = %s\n", find_str(0, 0));
	printf("find result = %s\n", find_str(0, ""));
	printf("find result = %s\n", find_str("", 0));
	printf("find result = %s\n", find_str("", ""));

	printf("find result = %s\n", find_str("abcdefgaabbccddeeffgg", 0));
	printf("find result = %s\n", find_str("abcdefgaabbccddeeffgg", "abcf"));
	printf("find result = %s\n", find_str("abcdefgaabbccddeeffgg", "abbc"));


	system("leaks a.out > leaks_result && cat leaks_result | grep leaked");

	return (0);
}
