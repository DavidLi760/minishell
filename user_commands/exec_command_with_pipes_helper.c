/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command_with_pipes_helper.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 08:29:08 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/05 15:23:06 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

int	wait_for_all_commands(int num_commands)
{
	int	status;
	int	i;

	i = 0;
	while (i < num_commands)
	{
		wait(&status);
		i++;
	}
	return (0);
}

int	update_input_fd(int in_fd, int i, int num_commands, int pipe_fds[2])
{
	if (in_fd != STDIN_FILENO)
		close(in_fd);
	if (i < num_commands - 1)
	{
		close(pipe_fds[1]);
		return (pipe_fds[0]);
	}
	return (STDIN_FILENO);
}

char	*get_command_path(const char *command)
{
	struct stat	buffer;
	char		*command_path;

	if (command[0] == '/' || strchr(command, '/'))
	{
		command_path = strdup(command);
		if (stat(command_path, &buffer) != 0 || !(buffer.st_mode & S_IXUSR))
		{
			free(command_path);
			return (NULL);
		}
	}
	else
	{
		command_path = find_user_command(command);
		if (command_path == NULL)
			return (NULL);
	}
	return (command_path);
}

int	create_pipe(int pipe_fds[2])
{
	if (pipe(pipe_fds) == -1)
	{
		perror("pipe error in minishell");
		return (-1);
	}
	return (0);
}
