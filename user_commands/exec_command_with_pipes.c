/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command_with_pipes.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 08:29:02 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/07 13:29:09 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

void	execute_command(char **args)
{
	char	*command_path;

	command_path = get_command_path(args[0]);
	if (command_path == NULL)
	{
		printf("minishell: %s: command not found\n", args[0]);
		ft_cmd_status(127);
		free(args);
		exit(127);
	}
	if (execv(command_path, args) == -1)
	{
		perror("execv error in minishell");
		exit(EXIT_FAILURE);
	}
}

void	setup_child_pipes(int i, int num_commands, int in_fd, int pipe_fds[2])
{
	if (in_fd != STDIN_FILENO)
	{
		dup2(in_fd, STDIN_FILENO);
		close(in_fd);
	}
	if (i < num_commands - 1)
	{
		dup2(pipe_fds[1], STDOUT_FILENO);
		close(pipe_fds[1]);
	}
}

int	split_commands(int *in_fd, char *input, char *commands[])
{
	int		num_commands;
	char	*command;

	*in_fd = STDIN_FILENO;
	num_commands = 0;
	command = strtok(input, "|");
	while (command != NULL)
	{
		commands[num_commands++] = command;
		command = strtok(NULL, "|");
	}
	commands[num_commands] = NULL;
	return (num_commands);
}

int	helper(int i, char ***args, int num_commands, int *in_fd)
{
	int		pipe_fds[2];
	pid_t	pid;

	if (i < num_commands - 1 && create_pipe(pipe_fds) != 0)
		free(*args);
	if (i < num_commands - 1 && create_pipe(pipe_fds) != 0)
		return (1);
	pid = fork();
	if (pid == 0)
	{
		if (*in_fd != STDIN_FILENO)
			dup2(*in_fd, STDIN_FILENO);
		if (*in_fd != STDIN_FILENO)
			close(*in_fd);
		if (i < num_commands - 1)
		{
			dup2(pipe_fds[1], STDOUT_FILENO);
			close(pipe_fds[1]);
		}
		execute_command(*args);
	}
	else if (pid < 0)
		return (1);
	*in_fd = update_input_fd(*in_fd, i, num_commands, pipe_fds);
	return (0);
}

int	exec_command_with_pipes(char *input, int i)
{
	char	**args;
	char	*commands[MAX_ARGS];
	int		num_commands;
	int		in_fd;

	num_commands = split_commands(&in_fd, input, commands);
	while (i < num_commands)
	{
		args = parse_user_input(commands[i]);
		if (helper(i, &args, num_commands, &in_fd))
			return (1);
		free(args);
		i++;
	}
	return (wait_for_all_commands(num_commands));
}
