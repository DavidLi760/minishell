/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_len.test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:50:06 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/04 10:05:23 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_test.h"

void	TEST_ft_strtrim_len()
{
	printBandeau("ft_strtrim_len");
	char *test = "    Ok    "; checkInt(1, test, 2, ft_strtrim_len(test));
	test = "Ok    "; checkInt(2, test, 2, ft_strtrim_len(test));
	test = "Ok"; checkInt(3, test, 2, ft_strtrim_len(test));
	test = "    Ok"; checkInt(4, test, 2, ft_strtrim_len(test));
	test = "    Ok    Ok    "; checkInt(5, test, 5, ft_strtrim_len(test));
	test = "    Ok    Ok"; checkInt(6, test, 5, ft_strtrim_len(test));
	test = "Ok    Ok"; checkInt(7, test, 5, ft_strtrim_len(test));
	test = "Ok    Ok    "; checkInt(8, test, 5, ft_strtrim_len(test));
	test = "  OkOk    "; checkInt(9, test, 4, ft_strtrim_len(test));
	test = "  Ok Ok    "; checkInt(10, test, 5, ft_strtrim_len(test));
	test = "Ok Ok"; checkInt(11, test, 5, ft_strtrim_len(test));
	test = "\"Ok    Ok\""; checkInt(12, test, 10, ft_strtrim_len(test));
}