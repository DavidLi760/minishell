/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:17:15 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/05 12:09:33 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

void	ft_exit_helper2(char **status, char *input)
{
	if (!ft_isnumber(*status)
		|| (ft_strlen(*status) == 1 && (*status)[0] == '-'))
	{
		free(*status);
		*status = ft_substr(input, 5, next_occ(input, 5, " ", 0));
		if (*status == NULL)
		{
			ft_cmd_status(1);
			exit(1);
		}
		printf("bash: exit: %s: numeric argument required\n", *status);
		free(*status);
		ft_cmd_status(1);
		exit(1);
	}
}

void	ft_exit_helper(char **status)
{
	int		code;

	code = ft_atoi(*status);
	free(*status);
	if (code < 0 || code > 255)
		code = code % 255;
	printf("exit\n");
	exit(code);
	ft_cmd_status(code);
}

void	ft_exit(char *input)
{
	char	*status;

	if (!input[4])
	{
		printf("exit\n");
		exit(0);
	}
	status = ft_substr(input, 5, ft_strlen(input) - 1);
	if (status == NULL)
	{
		ft_cmd_status(1);
		exit(1);
	}
	ft_exit_helper2(&status, input);
	if (ft_contains(status, 0, ft_strlen(status) - 1, ' '))
	{
		printf("bash: exit: too many arguments\n");
		free(status);
		ft_cmd_status(1);
		return ;
	}
	ft_exit_helper(&status);
}
