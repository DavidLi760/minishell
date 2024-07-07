/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:30:13 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/05 12:31:21 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

int	is_empty_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	next_occ(char *str, int i, char *sep, int reverse)
{
	int	rev;

	if (reverse)
	{
		rev = 0;
		while (ft_strlen(str) - 1 - rev > i)
		{
			if (!is_in_quote(str, ft_strlen(str) - 1 - rev)
				&& ft_contains(sep, 0, ft_strlen(sep) - 1,
					str[ft_strlen(str) - 1 - rev]))
				return (ft_strlen(str) - 1 - rev - 1);
			rev++;
		}
		return (ft_strlen(str) - 1 - rev - 1);
	}
	while (str[i])
	{
		if (!is_in_quote(str, i)
			&& ft_contains(sep, 0, ft_strlen(sep) - 1, str[i]))
			return (i - 1);
		i++;
	}
	return (i - 1);
}

int	next_occ_noq(char *str, int i, char *sep, int reverse)
{
	int	rev;

	if (reverse)
	{
		rev = 0;
		while (ft_strlen(str) - 1 - rev > i)
		{
			if (ft_contains(sep, 0, ft_strlen(sep) - 1,
					str[ft_strlen(str) - 1 - rev]))
				return (ft_strlen(str) - 1 - rev - 1);
			rev++;
		}
		return (ft_strlen(str) - 1 - rev - 1);
	}
	while (str[i])
	{
		if (ft_contains(sep, 0, ft_strlen(sep) - 1, str[i]))
			return (i - 1);
		i++;
	}
	return (i - 1);
}

int	ft_isnumber(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((!(str[i] >= '0' && str[i] <= '9') && str[i] != '-')
			|| count > 1)
			return (0);
		if (str[i] == '-')
			count++;
		i++;
	}
	if ((count && str[0] == '-') || count == 0)
		return (1);
	return (0);
}

int	ft_isalpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
