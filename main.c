/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:46:38 by davli             #+#    #+#             */
/*   Updated: 2024/08/11 19:05:59 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main()
{
	t_var	var;
	int		i;

	i = 0;
	while (1)
	{
		var.input = readline("minishell$> ");
		if (!var.input)
			break ;
		if (var.input)
			add_history(var.input);
		if (var.input[i] == ' ')
			break ;
	}
	return (0);
}
