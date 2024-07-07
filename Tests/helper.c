/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:20:01 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/05 09:10:52 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

void	checkInt(int index, char *test, int exp, int res)
{
	if (exp == res)
		printf("\033[32m#%d:[%s]:expected[%d]:result[%d]\033[0m\n", index, test, exp, res);
	else
		printf("\033[31m#%d:[%s]:expected[%d]:result[%d]\033[0m\n", index, test, exp, res);
}

void	checkString(int index, char *test, char *exp, char *res)
{
	if (ft_strcmp(exp, res) == 0)
		printf("\033[32m#%d:[%s]:expected[%s]:result[%s]\033[0m\n", index, test, exp, res);
	else
		printf("\033[31m#%d:[%s]:expected[%s]:result[%s]\033[0m\n", index, test, exp, res);
}

void printBandeau(const char *str)
{
	int	strLength = strlen(str);
	int	bandeauWidth = strLength + 20; 
	int	padding = (bandeauWidth - strLength - 2) / 2;

	printf("\n\n");
	printf("+");
	for (int i = 0; i < bandeauWidth - 2; i++)
		printf("-");
	printf("+\n");

	printf("|");
	for (int i = 0; i < bandeauWidth - 2; i++)
		printf(" ");
	printf("|\n");

	printf("|");
	for (int i = 0; i < padding; i++)
		printf(" ");
	printf("%s", str);
	for (int i = 0; i < padding; i++)
		printf(" ");

	if ((bandeauWidth - strLength - 2) % 2 != 0)
		printf(" ");
	printf("|\n");

	printf("|");
	for (int i = 0; i < bandeauWidth - 2; i++)
		printf(" ");
	printf("|\n");

	printf("+");
	for (int i = 0; i < bandeauWidth - 2; i++)
		printf("-");
	printf("+\n\n");
}