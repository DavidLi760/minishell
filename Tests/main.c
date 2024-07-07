/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:43:47 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/04 19:19:19 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_test.h"

int	main(int argc, char **argv)
{
	if (argc == 1 || ft_strncmp(argv[1], "ft_strtrim_len", 14))
		TEST_ft_strtrim_len();
	if (argc == 1 || ft_strncmp(argv[1], "ft_strtrim", 10))
		TEST_ft_strtrim();
	if (argc == 1 || ft_strncmp(argv[1], "ft_forward_output_len", 22))
		TEST_ft_forward_output_len();
	if (argc == 1 || ft_strncmp(argv[1], "ft_forward_output", 18))
		TEST_ft_forward_output();
	if (argc == 1 || ft_strncmp(argv[1], "ft_forward_file", 18))
		TEST_ft_forward_file();
	if (argc == 1 || ft_strncmp(argv[1], "ft_is_in_quote", 14))
		TEST_is_in_quote();
	return (0);
}
