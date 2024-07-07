/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_user_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 07:57:53 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/07 13:29:18 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

void	exec_single_command_helper(int in_fd, char *command_path, char **args)
{
	if (in_fd != -1)
	{
		dup2(in_fd, STDIN_FILENO);
		close(in_fd);
	}
	if (execv(command_path, args) == -1)
	{
		perror("exec error in minishell");
		exit(EXIT_FAILURE);
	}
}

int	exec_single_command(char **args, char *command_path, int in_fd)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		exec_single_command_helper(in_fd, command_path, args);
	}
	else if (pid < 0)
	{
		perror("fork error in minishell");
		return (1);
	}
	else
	{
		while (waitpid(pid, &status, WUNTRACED) != -1)
			if (WIFEXITED(status) || WIFSIGNALED(status))
				break ;
	}
	return (0);
}

int	handle_single_command_logic(char **command_path, char **args)
{
	if (args[0][0] == '/' || strchr(args[0], '/'))
	{
		*command_path = get_command_path_from_args(args[0]);
		if (!(*command_path))
		{
			printf("minishell: %s: No such file or directory\n", args[0]);
			return (1);
		}
	}
	else
	{
		*command_path = find_user_command(args[0]);
		if (!(*command_path))
		{
			printf("minishell: %s: command not found\n", args[0]);
			ft_cmd_status(127);
			return (1);
		}
	}
	return (0);
}

int	handle_single_command(char *input)
{
	char	*command_path;
	char	**args;
	int		in_fd;
	int		result;

	args = parse_user_input(input);
	in_fd = process_input_redirection(args, input);
	if (in_fd == -1 && args[0] == NULL)
		return (free(args), 1);
	if (handle_single_command_logic(&command_path, args))
		return (free(args), 1);
	result = exec_single_command(args, command_path, in_fd);
	return (free(command_path), free(args), result);
}

int	exec_user_command(char *input)
{
	if (strchr(input, '|'))
		return (exec_command_with_pipes(input, 0));
	else
		return (handle_single_command(input));
}
