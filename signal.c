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
	if (g_signal == 0)
		rl_redisplay();
}

void	handle_sigsegv(int signum)
{
	(void) signum;
	write(2, "Segmentation fault\n", 19);
	exit(11);
}

void	handle_sigabrt(int signum)
{
	(void) signum;
	write(1, "abort\n", 6);
}

void	handle_sigquit(int signum)
{
	(void) signum;
}

void	handle_signals(void)
{
	signal(SIGINT, &handle_sigint);
	signal(SIGSEGV, &handle_sigsegv);
	signal(SIGABRT, &handle_sigabrt);
	signal(SIGQUIT, &handle_sigquit);
}
