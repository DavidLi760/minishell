/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 08:59:54 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/05 09:00:32 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *str, int character)
{
	while (*str != '\0')
	{
		if (*str == character)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
