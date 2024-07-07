/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forward_output_len.test.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:11:57 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/02 21:43:13 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_test.h"

void	TEST_ft_forward_output_len()
{
	printBandeau("ft_retrieve_output_len");
	char *test = "echo> l >> 2 test test2 >> eer opop > o ok ll"; checkInt(1, test, 21, ft_forward_output_len(test));
	test = "echo> l >> 2 test test2 >>eer opop >o ok ll"; checkInt(2, test, 21, ft_forward_output_len(test));
	test = "echo> l >> 2 test test2>>eer opop>o ok ll"; checkInt(3, test, 21, ft_forward_output_len(test));
	test = "echo> l >> 2 test test2>>eeropop>>o ok ll"; checkInt(4, test, 16, ft_forward_output_len(test));
	test = "echo> l >> 2 testtest2>>eeropop>> o ok ll"; checkInt(5, test, 15, ft_forward_output_len(test));
	test = "echo > l >> 2 testtest2>>eeropop>o ok ll"; checkInt(6, test, 15, ft_forward_output_len(test));
	test = "echo > l test >> 2 testtest2>>eeropop>o ok ll"; checkInt(6, test, 20, ft_forward_output_len(test));
	test = "echo Ok OK > test"; checkInt(7, test, 5, ft_forward_output_len(test));
	test = "echo Ok OK > test ok ok"; checkInt(8, test, 11, ft_forward_output_len(test));
	test = "echo Ok OK > yy UU > l L LLL >> test ok ok"; checkInt(9, test, 20, ft_forward_output_len(test));
}
