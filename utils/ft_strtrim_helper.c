/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:43:55 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/05 13:44:57 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

int	is_last_characters(char *input, int index)
{
	index++;
	while (input[index])
	{
		if (!ft_isspace(input[index]))
			return (0);
		index++;
	}
	return (1);
}

void	ft_strtrim_helper(int *in_dquote, int *in_squote, char *input, int i)
{
	if (!(*in_dquote) && input[i] == '\''
		&& ft_contains(input, i + 1, ft_strlen(input), '\''))
		*in_dquote = next_occ(input, i + 1, "\'", 1) + 2;
	else if (!(*in_squote) && input[i] == '\"'
		&& ft_contains(input, i + 1, ft_strlen(input), '\"'))
		*in_squote = next_occ(input, i + 1, "\"", 1) + 2;
	if (i == *in_squote)
		*in_squote = 0;
	if (i == *in_dquote)
		*in_dquote = 0;
}
