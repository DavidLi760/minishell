/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:49:14 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/05 12:13:39 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

int	substring_occ(char *string, char *substring)
{
	int	i;
	int	j;
	int	count;
	int	match;

	i = 0;
	count = 0;
	while (i <= ft_strlen(string) - ft_strlen(substring))
	{
		match = 1;
		j = 0;
		while (j < ft_strlen(substring))
		{
			if (string[i + j] != substring[j])
			{
				match = 0;
				break ;
			}
			j++;
		}
		if (match)
			count++;
		i++;
	}
	return (count);
}

int	ft_subchar(char *str, char *sub)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (!is_in_quote(str, i) && str[i + j]
			&& sub[j] && str[i + j] == sub[j])
		{
			if (!sub[j + 1])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_contains(char *str, int from_index, int to_index, char sep)
{
	while (str[from_index] && from_index <= to_index)
	{
		if (!is_in_quote(str, from_index) && str[from_index] == sep)
		{
			return (1);
		}
		from_index++;
	}
	return (0);
}

int	ft_contains_seq(char *str, int from_index, int to_index, char *seq)
{
	int	i;

	i = 0;
	while (str[from_index] && from_index <= to_index)
	{
		while (seq[i])
		{
			if (!is_in_quote(str, from_index) && str[from_index] == seq[i])
				return (1);
			i++;
		}
		from_index++;
	}
	return (0);
}
