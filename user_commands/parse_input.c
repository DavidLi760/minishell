/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 08:27:09 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/05 12:14:51 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

char	**parse_user_input(char *input)
{
	int		position;
	char	**tokens;
	char	*token;

	position = 0;
	tokens = malloc(MAX_ARGS * sizeof(char *));
	if (!tokens)
		exit(EXIT_FAILURE);
	token = strtok(input, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		if (position >= MAX_ARGS)
		{
			printf("Too many arguments\n");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[position] = NULL;
	return (tokens);
}
