/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward_output_len.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:06:36 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/05 14:11:46 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

void	len_helper1(int *i, int *len, char *str)
{
	*i = 4 + is_echo_option(str, 5);
	*len = 0;
	if (str[4] == ' ')
		(*i)++;
	while (str[*i] && (is_in_quote(str, *i)
			|| (!ft_contains("><", 0, 2, str[*i])
				&& !(str[*i] == ' '
					&& ft_contains("><", 0, 2, str[*i + 1])))))
	{
		(*len)++;
		(*i)++;
	}
}

int	len_helper2(char *str, int *i, int *len)
{
	*i = next_occ(str, *i, " ", 0) + 2;
	if (!str[*i - 1] || !str[*i])
	{
		if (!is_echo_option(str, 5))
			*len += 1;
		return (1);
	}
	return (0);
}

void	len_helper3(char *str, int *len, int *i)
{
	while (str[*i] && !ft_contains("><", 0, 2, str[*i])
		&& !(str[*i] == ' ' && ft_contains("><", 0, 2, str[*i + 1])))
	{
		(*i)++;
		(*len)++;
	}
}

int	ft_forward_output_len(char *str)
{
	int	len;
	int	i;

	len_helper1(&i, &len, str);
	while (str[i])
	{
		while (str[i] && ft_contains(">< ", 0, 3, str[i]))
			i++;
		if (!ft_contains(str, i, next_occ(str, i, "><", 0), ' '))
		{
			i++;
			continue ;
		}
		if (len_helper2(str, &i, &len))
			return (len);
		if (ft_contains(">< ", 0, 3, str[i]))
			continue ;
		if (len != 0)
			len++;
		len_helper3(str, &len, &i);
	}
	if (is_echo_option(str, 5))
		return (len);
	else
		return (len + 1);
}
