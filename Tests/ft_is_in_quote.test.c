/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_quote.test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:01:11 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/04 19:06:30 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_test.h"

void	TEST_is_in_quote()
{
	printBandeau("is_in_quote");
	char *test = "\"<\""; checkInt(1, test, 1, is_in_quote(test, 1));
	test = "\"<\"<"; checkInt(1, test, 0, is_in_quote(test, 3));
	test = "\'<\'"; checkInt(1, test, 1, is_in_quote(test, 1));
	test = "\'<\'<"; checkInt(1, test, 0, is_in_quote(test, 3));
	test = "\"<\'"; checkInt(1, test, 0, is_in_quote(test, 1));
	test = "\'<\"<"; checkInt(1, test, 0, is_in_quote(test, 3));
}