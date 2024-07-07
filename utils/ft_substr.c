/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:04:26 by edecorce          #+#    #+#             */
/*   Updated: 2024/06/30 00:33:13 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

char	*ft_substr(char *str, int from, int to)
{
	char	*substr;
	int		i;

	substr = (char *) malloc((to - from + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (str[from + i] && from + i <= to)
	{
		substr[i] = str[from + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
