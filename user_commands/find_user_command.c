/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_user_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 08:27:55 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/05 12:36:22 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

char	*find_absolute_command(const char *command)
{
	struct stat	buffer;

	if (command[0] == '/' || strchr(command, '/'))
	{
		if (stat(command, &buffer) == 0 && (buffer.st_mode & S_IXUSR))
			return (strdup(command));
		else
			return (NULL);
	}
	return (NULL);
}

char	*find_in_path(const char *command)
{
	char		*path;
	char		*path_copy;
	char		*dir;
	char		full_path[MAX_PATH_LENGTH];
	struct stat	buffer;

	path = getenv("PATH");
	if (!path)
		return (NULL);
	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
		if (stat(full_path, &buffer) == 0 && (buffer.st_mode & S_IXUSR))
			return (free(path_copy), strdup(full_path));
		dir = strtok(NULL, ":");
	}
	return (free(path_copy), NULL);
}

char	*find_user_command(const char *command)
{
	char	*command_path;

	command_path = find_absolute_command(command);
	if (command_path)
		return (command_path);
	return (find_in_path(command));
}
