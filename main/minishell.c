/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:11:53 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/05 12:11:51 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell(void)
{
	char	*input;

	ft_cmd_status(0);
	signal_constructor();
	while (1)
	{
		input = readline("minishell: ");
		if (!input)
		{
			exit(0);
			break ;
		}
		if (is_empty_string(input) || !input[0])
		{
			ft_cmd_status(0);
			free(input);
			continue ;
		}
		else
		{
			minishell_init(&input);
			input_manager(input);
			free(input);
		}
	}
}

int	main(void)
{
	while (1)
		minishell();
	return (0);
}
