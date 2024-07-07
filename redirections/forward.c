/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 12:39:03 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/05 14:12:03 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

int	forward_redirection_errors(char *input)
{
	if (input[ft_strlen(input) - 1] == '>')
		printf("bash: syntax error near unexpected token `newline'\n");
	else if (ft_subchar(input, "> >>") || ft_subchar(input, ">>>>"))
		printf("bash: syntax error near unexpected token `>>'\n");
	else if (ft_subchar(input, "> >") || ft_subchar(input, ">>>"))
		printf("bash: syntax error near unexpected token `>'\n");
	else
		return (0);
	return (1);
}

int	is_forward(char *str)
{
	int	i;

	i = next_occ(str, 0, ">", 1);
	return (str[i] != '>' && str[i + 2] != '>');
}

int	is_forward_append(char *str)
{
	int	i;

	i = next_occ(str, 0, ">", 1);
	return (str[i - 1] != '>' && str[i] == '>' && str[i + 2] != '>');
}

char	*ft_forward_file(char *input, char *sep)
{
	int	start;

	start = next_occ(input, 0, sep, 1);
	if (input[start + 2] == ' ')
		return (ft_substr(input, start + 3,
				next_occ(input, start + 3, " ", 0)));
	else
		return (ft_substr(input, start + 2,
				next_occ(input, start + 2, " ", 0)));
}

int	forward(char *input)
{
	ssize_t	bytes_written;
	char	*output;
	char	*file;
	int		fd;

	fd = -1;
	output = ft_forward_output(input);
	if (output == NULL)
		return (1);
	file = ft_forward_file(input, ">");
	if (file == NULL)
		return (free(output), 1);
	if (is_forward(input))
		fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	else if (is_forward_append(input))
		fd = open(file, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (fd < 0)
		return (free(output), free(file), 0);
	bytes_written = write(fd, output, ft_strlen(output));
	if (bytes_written < 0)
		close(fd);
	if (bytes_written < 0)
		return (free(output), free(file), 0);
	close(fd);
	return (free(output), free(file), 1);
}
