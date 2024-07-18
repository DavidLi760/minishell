/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:45:51 by davli             #+#    #+#             */
/*   Updated: 2024/07/18 12:59:15 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '+' || str[i] == '-')
		if (str[i] == '-')
			sign = -1;
	while (str[i])
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}

int	main()
{
	t_var	var;
	int		i;
	int		j;
	char	*ret;

	exit_value = 0;
	i = 0;
	ret = malloc(3 * sizeof(char) + 1);
	if (!ret)
		return (0);
	while (i < 3)
		ret[i++] = 0;
	while (1)
	{
		i = 0;
		j = 0;
		var.input = readline("minishell$> ");
//		var.input = "exit 5 5 ";
		add_history(var.input);
		var.tokens = ft_split(var.input, ' ');
		while (var.input[i])
		{
			i++;
			j++;
			while (var.input[i] == ' ')
				i++;
			if (!var.input[i] || !"exit"[j])
			{
				exit_value = 1;
				break ;
			}
		}
		j = 0;
		while (var.input[i] >= '0' && var.input[i] <= '9')
		{
			ret[j++] = var.input[i++];
			while (var.input[i] == ' ')
				i++;
			if (!var.input[i])
			{
				if (ret[j] != '\0')
					ret = 0;
				exiting = ft_atoi(ret);
			}
			else
			{
				printf("Too many arguments\n");
				exiting = 0;
			}
		}
		if (exiting > 255)
		{
			free(var.input);
			free(ret);
			printf("exit\n");
			exit (1);
		}
		if (exiting != 0)
		{
			free(var.input);
			free(ret);
			printf("exit\n");
			exit (exiting);
		}
		else
			free(var.input);
	}
}
