/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:04:14 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/05 12:31:36 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

size_t	ft_strcspn(const char *str, const char *reject)
{
	size_t		count;
	const char	*s;

	count = 0;
	s = str;
	while (*s != '\0')
	{
		if (strchr(reject, *s) != NULL)
			return (count);
		count++;
		s++;
	}
	return (count);
}

size_t	ft_strspn(const char *str, const char *delim)
{
	const char	*s;
	const char	*d;
	size_t		count;

	s = str;
	count = 0;
	while (*s != '\0')
	{
		d = delim;
		while (*d != '\0')
		{
			if (*s == *d)
				break ;
			d++;
		}
		if (*d == '\0')
			return (count);
		count++;
		s++;
	}
	return (count);
}
