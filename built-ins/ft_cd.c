/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:16:40 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/04 13:07:24 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

void	ft_cd(char *input)
{
	int		i;
	char	*path;

	i = 2;
	while (input[i] == ' ')
		i++;
	path = &input[i];
	if (path[0] == '\0')
		path = getenv("HOME");
	if (input[2] != ' ' && input[2] != '\0')
	{
		printf("Bash: %s: command not found\n", input);
		ft_cmd_status(127);
	}
	else if (chdir(path) != 0)
	{
		perror("cd");
		ft_cmd_status(1);
	}
	else
		ft_cmd_status(0);
}
