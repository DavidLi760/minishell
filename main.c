/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:46:38 by davli             #+#    #+#             */
/*   Updated: 2024/08/18 18:45:03 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	skip_char(char *str, int i)
{
	while (str[i] == ' '
		|| (str[i] == '\'' && str[i + 1] == '\'')
		|| (str[i] == '"' && str[i + 1] == '"'))
	{
		while (str[i] == ' ')
			i++;
		while (str[i] == '\'' && str[i + 1] == '\'')
			i += 2;
		while (str[i] == '"' && str[i + 1] == '"')
			i += 2;
	}
	return (i);
}

int	count_token(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		i = skip_char(str, i);
		while (str[i] != ' ' && str[i])
		{
			i = skip_char(str, i);
			if (str[i] == '\'')
			{
				i++;
				while (str[i] != '\'' && str[i])
					i++;
			}
			if (str[i] == '"')
			{
				i++;
				while (str[i] != '"' && str[i])
					i++;
			}
			while (str[i] != '\'' && str[i] != '"' && str[i] != ' ' && str[i])
			{
				i++;
				if (str[i] == '>' || str[i] == '<' || (str[i] == '>' && str[i + 1] == '>')
					|| (str[i] == '<' && str[i + 1] == '<'))
					count++;
			}
		}
		count++;
		if (str[i] == '\0' && str[i - 1] == ' ')
			count--;
	}
	return (count);
}
/*
char	**ft_strtok(char *str)
{
	int		i;
	char	**tokens;

	i = 0;

	return ();
}
*/

int	main(void)
{
	t_var	var;
	int		i;
	//	char	**tokens;
	int		count;

	while (1)
	{
		i = 0;
		var.input = readline("minishell$> ");
//		var.input = "asd asd sd sd sd ";
		if (!var.input)
			break ;
		count = count_token(var.input);
		printf("%d\n", count);
		add_history(var.input);	
		if (var.input[i] == ':')
			break ;
	}
}
