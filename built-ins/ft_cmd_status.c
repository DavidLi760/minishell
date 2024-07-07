/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_status.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:50:18 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/05 11:46:10 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

void	ft_cmd_status(int status)
{
	char	*nb;

	nb = ft_itoa(status);
	if (nb == NULL)
	{
		setenv("?", "0", 1);
		return ;
	}
	setenv("?", nb, 1);
	free(nb);
}
