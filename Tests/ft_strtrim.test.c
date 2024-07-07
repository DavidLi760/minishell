/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:50:06 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/04 11:32:25 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_test.h"

void	TEST_ft_strtrim()
{
	printBandeau("ft_strtrim");
	char *test = "    Ok    "; checkString(1, test, "Ok\0", ft_strtrim(test));
	test = "Ok    "; checkString(2, test, "Ok", ft_strtrim(test));
	test = "Ok"; checkString(3, test, "Ok", ft_strtrim(test));
	test = "    Ok"; checkString(4, test, "Ok", ft_strtrim(test));
	test = "    Ok    Ok    "; checkString(5, test, "Ok Ok", ft_strtrim(test));
	test = "    Ok    Ok"; checkString(6, test, "Ok Ok", ft_strtrim(test));
	test = "Ok    Ok"; checkString(7, test, "Ok Ok", ft_strtrim(test));
	test = "Ok    Ok    "; checkString(8, test, "Ok Ok", ft_strtrim(test));
	test = "  OkOk    "; checkString(9, test, "OkOk", ft_strtrim(test));
	test = "  Ok Ok    "; checkString(10, test, "Ok Ok", ft_strtrim(test));
	test = "Ok Ok"; checkString(11, test, "Ok Ok", ft_strtrim(test));
	test = "\"\'Ok    Ok\'\""; checkString(12, test, "\"\'Ok    Ok\'\"", ft_strtrim(test));
}