/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:17:59 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/05 13:52:20 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

void	ft_strtrim_len_init(int *in_dquote, int *in_squote)
{
	*in_dquote = 0;
	*in_squote = 0;
}

int	ft_strtrim_len(char *input)
{
	int	in_dquote;
	int	in_squote;
	int	in_word;
	int	len;
	int	i;

	in_word = 0;
	len = 0;
	i = 0;
	ft_strtrim_len_init(&in_dquote, &in_squote);
	while (input[i])
	{
		ft_strtrim_helper(&in_dquote, &in_squote, input, i);
		if (!ft_isspace(input[i]) || (in_word && !is_last_characters(input, i)))
		{
			in_word = 1;
			len++;
		}
		if (!in_dquote && !in_squote && ft_isspace(input[i]))
			while (ft_isspace(input[i]))
				i++;
		else
			i++;
	}
	return (len);
}

int	ft_strtrim_init(char **trimmed, int *in_word, char *input, int *in_dquote)
{
	*trimmed = (char *) malloc((ft_strtrim_len(input) + 1) * sizeof(char));
	if (*trimmed == NULL)
		return (1);
	*in_word = 0;
	*in_dquote = 0;
	return (0);
}

void	ft_strtrim_init2(int *in_squote, int *i)
{
	*in_squote = 0;
	*i = 0;
}

char	*ft_strtrim(char *input)
{
	int		in_dquote;
	int		in_squote;
	char	*trimmed;
	int		in_word;
	int		i;
	int		j;

	if (ft_strtrim_init(&trimmed, &in_word, input, &in_dquote))
		return (NULL);
	ft_strtrim_init2(&in_squote, &i);
	j = 0;
	while (input[i])
	{
		ft_strtrim_helper(&in_dquote, &in_squote, input, i);
		if (!ft_isspace(input[i]) || (in_word && !is_last_characters(input, i)))
		{
			in_word = 1;
			trimmed[j++] = input[i];
		}
		if (!in_dquote && !in_squote && ft_isspace(input[i]))
		{
			while (ft_isspace(input[i]))
				i++;
			i--;
		}
			i++;
	}
	trimmed[j] = '\0';
	return (trimmed);
}
