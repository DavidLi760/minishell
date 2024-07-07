/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_user_commands.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:30:12 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/05 15:25:14 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

int	handle_heredoc_redirection(char **args, int index)
{
	FILE	*temp_file;
	int		in_fd;
	char	*delimiter;
	char	line[1024];

	if (args[index + 1] != NULL)
	{
		if (hdoc_helper(&delimiter, &temp_file, args, index) == -1)
			return (-1);
		while (fgets(line, sizeof(line), stdin))
		{
			if (strncmp(line, delimiter, strlen(delimiter)) == 0
				&& line[strlen(delimiter)] == '\n')
				break ;
			fputs(line, temp_file);
			printf("> ");
		}
		hdoc_helper2(temp_file, &args, index, &in_fd);
		return (in_fd);
	}
	else
	{
		printf("minishell: syntax error near unexpected token `newline'\n");
		return (-1);
	}
}

int	handle_file_redirection(char **args, int index)
{
	int	in_fd;

	if (args[index + 1] != NULL)
	{
		in_fd = open(args[index + 1], O_RDONLY);
		if (in_fd == -1)
		{
			perror("minishell: error opening file for input redirection");
			return (-1);
		}
		args[index] = NULL;
		args[index + 1] = NULL;
		return (in_fd);
	}
	else
	{
		printf("minishell: syntax error near unexpected token `newline'\n");
		return (-1);
	}
}

int	process_input_redirection(char **args, char *input)
{
	int	in_fd;
	int	i;

	in_fd = -1;
	i = 0;
	while (args[i] != NULL)
	{
		if (strcmp(args[i], "<") == 0
			&& !is_in_quote(input, strstr(input, "<") - input))
		{
			in_fd = handle_file_redirection(args, i);
			break ;
		}
		else if (strcmp(args[i], "<<") == 0
			&& !is_in_quote(input, strstr(input, "<<") - input))
		{
			in_fd = handle_heredoc_redirection(args, i);
			break ;
		}
		i++;
	}
	return (in_fd);
}

char	*get_command_path_from_args(const char *arg)
{
	struct stat	buffer;

	if (stat(arg, &buffer) != 0 || !(buffer.st_mode & S_IXUSR))
	{
		return (NULL);
	}
	return (strdup(arg));
}
