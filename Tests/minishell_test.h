/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_test.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:48:46 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/04 19:05:22 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELLTEST_H
# define MINISHELLTEST_H

# include "../main/minishell.h"

void	printBandeau(const char *str);
void	checkInt(int index, char *test, int exp, int res);
void	checkString(int index, char *test, char *exp, char *res);

void	TEST_ft_strtrim();
void	TEST_is_in_quote();
void	TEST_ft_strtrim_len();
void	TEST_ft_forward_file();
void	TEST_ft_forward_output();
void	TEST_ft_forward_output_len();




#endif /* MINISHELLTEST_H */