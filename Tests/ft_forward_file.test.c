/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forward_file.test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:11:57 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/04 10:03:05 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_test.h"

void	TEST_ft_forward_file()
{
	printBandeau("ft_forward_file");
	char *test = "echo> l >> 2 test test2 >> eer opop > o ok ll"; checkString(1, test, "o", ft_forward_file(test, ">"));
	test = "echo> l >> 2 test test2 >>eer opop >o ok ll"; checkString(2, test, "o", ft_forward_file(test, ">"));
	test = "echo> l >> 2 test test2>>eer opop>o ok ll"; checkString(3, test, "o", ft_forward_file(test, ">"));
	test = "echo> l >> 2 test test2>>eeropop>>o ok ll"; checkString(4, test, "o", ft_forward_file(test, ">"));
	test = "echo> l >> 2 testtest2>>eeropop>> o ok ll"; checkString(5, test, "o", ft_forward_file(test, ">"));
	test = "echo > l >> 2 testtest2>>eeropop>o ok ll"; checkString(6, test, "o", ft_forward_file(test, ">"));
	test = "echo > l test >> 2 testtest2>>eeropop>o ok ll"; checkString(6, test, "o", ft_forward_file(test, ">"));
	test = "echo Ok OK > test"; checkString(7, test, "test", ft_forward_file(test, ">"));
	test = "echo Ok OK > test ok ok"; checkString(8, test, "test", ft_forward_file(test, ">"));
	test = "echo Ok OK > yy UU > l L LLL >>okok ok"; checkString(9, test, "okok", ft_forward_file(test, ">"));
}
