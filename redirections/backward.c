/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backward.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:11:51 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/05 14:06:27 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

int	backward_redirection_errors(char *input)
{
	if (input[ft_strlen(input) - 1] == '<')
		printf("bash: syntax error near unexpected token `newline'\n");
	else if (ft_subchar(input, "<<<<<<"))
		printf("bash: syntax error near unexpected token `<<<'\n");
	else if (ft_subchar(input, "<<<<<"))
		printf("bash: syntax error near unexpected token `<<'\n");
	else if (ft_subchar(input, "< <<") || ft_subchar(input, "<< <<"))
		printf("bash: syntax error near unexpected token `<<'\n");
	else if (ft_subchar(input, "<< <") || ft_subchar(input, "<<<<"))
		printf("bash: syntax error near unexpected token `<'\n");
	else
		return (0);
	return (1);
}

void	backward(char *input)
{
	char	*command;
	char	*filename;
	int		i;
	int		fd;

	i = next_occ(input, 0, "<", 0);
	if (input[i - 1] == ' ')
		command = ft_substr(input, 0, next_occ(input, 0, "<", 0) - 1);
	else
		command = ft_substr(input, 0, next_occ(input, 0, "<", 0));
	if (command == NULL)
		return ;
	filename = ft_forward_file(input, "<");
	if (filename == NULL)
	{
		free(command);
		return ;
	}
	fd = open(filename, O_RDONLY);
	if (dup2(fd, STDIN_FILENO) < 0)
	{
		free(command);
		free(filename);
		return ;
	}
}

void	heredoc(char *input)
{
	char	buffer[50000];
	char	*input2;
	char	*eof;

	eof = ft_substr(input, next_occ(input, 0, "<", 0) + 3, ft_strlen(input));
	if (eof == NULL)
		return ;
	while (1)
	{
		input2 = readline("> ");
		if (ft_strncmp(input2, eof, ft_strlen(eof)))
		{
			free(input2);
			break ;
		}
		free(input2);
	}
	free(eof);
	buffer[ft_strlen(buffer)] = '\0';
	printf("%s", buffer);
}

void	back_redirection(char *input)
{
	if (input[next_occ(input, 0, "<", 0) + 2] == '<')
		backward(input);
	else
		heredoc(input);
}
