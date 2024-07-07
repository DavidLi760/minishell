/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:59:52 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/05 14:11:50 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

int	helper1(int *i, char **content, char *str)
{
	*i = 4 + is_echo_option(str, 5);
	*content = (char *) malloc((ft_forward_output_len(str) + 1) * sizeof(char));
	if (*content == NULL)
		return (1);
	if (str[4] == ' ')
		(*i)++;
	while (str[*i] && (is_in_quote(str, *i)
			|| (!ft_contains("><", 0, 2, str[*i])
				&& !(str[*i] == ' '
					&& ft_contains("><", 0, 2, str[*i + 1])))))
	{
		(*content)[ft_strlen(*content)] = str[*i];
		(*i)++;
	}
	return (0);
}

int	helper2(int *i, char **content, char *str)
{
	*i = next_occ(str, *i, " ", 0) + 2;
	if (!str[*i - 1] || !str[*i])
	{
		if (!is_echo_option(str, 5))
			(*content)[ft_strlen(*content)] = '\n';
		(*content)[ft_strlen(*content)] = '\0';
		return (1);
	}
	return (0);
}

void	helper3(char **content, char *str, int *i)
{
	if (ft_strlen(*content) != 0)
		(*content)[ft_strlen(*content)] = ' ';
	while (str[*i] && !ft_contains("><", 0, 2, str[*i])
		&& !(str[*i] == ' ' && ft_contains("><", 0, 2, str[*i + 1])))
	{
		(*content)[ft_strlen(*content)] = str[*i];
		(*i)++;
	}
}

void	helper4(char *str, char **content)
{
	if (!is_echo_option(str, 5))
		(*content)[ft_strlen(*content)] = '\n';
	(*content)[ft_strlen(*content)] = '\0';
}

char	*ft_forward_output(char *str)
{
	char	*output;
	char	*content;
	int		i;

	helper1(&i, &content, str);
	while (str[i])
	{
		while (str[i] && ft_contains(">< ", 0, 3, str[i]))
			i++;
		if (!ft_contains(str, i, next_occ(str, i, "><", 0), ' '))
		{
			i = next_occ(str, i, "><", 0) + 1;
			continue ;
		}
		helper2(&i, &content, str);
		if (ft_contains(">< ", 0, 3, str[i]))
			continue ;
		helper3(&content, str, &i);
	}
	helper4(str, &content);
	output = remove_quotes(content);
	free(content);
	return (output);
}
