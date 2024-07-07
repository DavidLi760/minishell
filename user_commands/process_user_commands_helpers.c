/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_user_commands_helpers.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:58:39 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/05 14:05:10 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

int	hdoc_helper(char **delimiter, FILE **temp_file, char **args, int index)
{
	*delimiter = args[index + 1];
	*temp_file = tmpfile();
	if (*temp_file == NULL)
	{
		perror("minishell: here document error");
		return (-1);
	}
	printf("> ");
	return (0);
}

void	hdoc_helper2(FILE *temp_file, char ***args, int index, int *in_fd)
{
	fflush(temp_file);
	fseek(temp_file, 0, SEEK_SET);
	*in_fd = fileno(temp_file);
	(*args)[index] = NULL;
	(*args)[index + 1] = NULL;
}
