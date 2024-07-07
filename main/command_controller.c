/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_controller.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:10:27 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/05 14:12:29 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

void	command_not_found(char *input)
{
	int	i;

	i = 0;
	printf("Bash: ");
	while (input[i] && input[i] != ' ')
	{
		printf("%c", input[i]);
		i++;
	}
	printf(":command not found\n");
	ft_cmd_status(127);
}

int	check_command(char *input, char *test)
{
	int	i;

	i = ft_strlen(test);
	return ((ft_strncmp(input, test, i) == 0 && !input[i])
		|| (ft_strncmp(input, test, i) == 0 && input[i] == ' '));
}

void	input_manager(char *input)
{
	if (check_command(input, "pwd"))
		ft_pwd();
	else if (check_command(input, "exit"))
		ft_exit(input);
	else if (check_command(input, "env"))
		ft_env();
	else if ((ft_strncmp(input, "echo", 4) == 0 && !input[4])
		|| (ft_strncmp(input, "echo", 4) == 0
			&& ft_contains("> <", 0, 2, input[4])))
		ft_echo(input);
	else if (check_command(input, "cd"))
		ft_cd(input);
	else if (check_command(input, "export"))
		ft_export(input);
	else if (check_command(input, "unset"))
		ft_unset(input);
	else if (!backward_redirection_errors(input))
		exec_user_command(input);
}
