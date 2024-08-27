/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:09:15 by davli             #+#    #+#             */
/*   Updated: 2024/08/24 17:09:26 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_sigint(int signum)
{
	(void) signum;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	handle_sigquit(int signum)
{
	(void) signum;
	if (g_signal != 0)
	{
		write(1, "Quit (core dumped)\n", 19);
	}
}

void	handle_signals(void)
{
	signal(SIGINT, &handle_sigint);
	signal(SIGQUIT, &handle_sigquit);
}
