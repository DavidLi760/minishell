/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:45:51 by davli             #+#    #+#             */
/*   Updated: 2024/07/10 12:55:12 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main()
{
	char	*input;

	while (1)
	{
		input = readline("minishell$> ");
		add_history(input);
		if (strcmp(input, "exit") == 0)
		{
			free(input);
			printf("exit\n");
			break;
		}
	}
	return (0);
}
