/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 00:40:18 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/04 13:13:45 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

void	ft_unset(char *input)
{
	char	*subset;
	int		i;

	i = 6;
	while (input[i])
	{
		subset = ft_substr(input, i, next_occ(input, i, " ", 0));
		if (subset == NULL)
			return ;
		if (unsetenv(subset) != 0)
		{
			perror("Unsetenv failed");
			ft_cmd_status(1);
			return ;
		}
		i += ft_strlen(subset) + 1;
		free(subset);
	}
	ft_cmd_status(0);
}
