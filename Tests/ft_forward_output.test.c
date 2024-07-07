/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forward_output.test.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:44:02 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/02 22:11:28 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_test.h"

void	TEST_ft_forward_output()
{
	printBandeau("ft_forward_output");
	char *test = "echo> l >> 2 test test2 >> eer opop > o ok ll"; checkString(1, test, "test test2 opop ok ll", ft_forward_output(test));
	test = "echo> l >> 2 test test2 >>eer opop >o ok ll"; checkString(2, test, "test test2 opop ok ll", ft_forward_output(test));
	test = "echo> l >> 2 test test2>>eer opop>o ok ll"; checkString(3, test, "test test2 opop ok ll", ft_forward_output(test));
	test = "echo> l >> 2 test test2>>eeropop>>o ok ll"; checkString(4, test, "test test2 ok ll", ft_forward_output(test));
	test = "echo> l >> 2 testtest2>>eeropop> o ok ll"; checkString(5, test, "testtest2 ok ll", ft_forward_output(test));
	test = "echo> l >> 2 testtest2>>eeropop >> o ok ll"; checkString(5, test, "testtest2 ok ll", ft_forward_output(test));
	test = "echo> l >> 2 testtest2>>eeropop >>o ok ll"; checkString(5, test, "testtest2 ok ll", ft_forward_output(test));
	test = "echo > l test >> 2 testtest2>>eeropop>o ok ll"; checkString(6, test, "test testtest2 ok ll", ft_forward_output(test));
	test = "echo Ok Ok > test"; checkString(7, test, "Ok Ok", ft_forward_output(test));
	test = "echo Ok Ok > test ok ok"; checkString(8, test, "Ok Ok ok ok", ft_forward_output(test));
	test = "echo Ok OK > yy UU > l L LLL >> test ok ok"; checkString(9, test, "Ok OK UU L LLL ok ok", ft_forward_output(test));
	test = "echo Ok OK >> yy UU > l L LLL >> test ok ok"; checkString(10, test, "Ok OK UU L LLL ok ok", ft_forward_output(test));
}