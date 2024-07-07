/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:01:56 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/05 12:02:46 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char		*next_token;
	char			*token_start;
	char			*token_end;

	next_token = NULL;
	if (str != NULL)
		next_token = str;
	else if (next_token == NULL)
		return (NULL);
	next_token += strspn(next_token, delim);
	if (*next_token == '\0')
	{
		next_token = NULL;
		return (NULL);
	}
	token_start = next_token;
	token_end = token_start + strcspn(token_start, delim);
	if (*token_end == '\0')
		next_token = NULL;
	else
		next_token = token_end + 1;
	*token_end = '\0';
	return (token_start);
}
