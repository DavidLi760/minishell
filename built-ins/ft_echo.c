/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:15:34 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/05 11:46:19 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

int	is_echo_option(char *input, int i)
{
	int	option;
	int	j;

	option = 0;
	j = i;
	while (input[i] == '-' && input[i + 1] == 'n'
		&& (input[i + 2] == 'n' || input[i + 2] == ' '))
	{
		i += 2;
		while (input[i] == 'n')
		{
			i++;
		}
		while (input[i] == ' ')
		{
			option = 1;
			i++;
		}
	}
	if (option)
		return (i - j);
	else
		return (0);
}

int	echo_forward(char *input)
{
	if (ft_contains(input, 0, ft_strlen(input) - 1, '>')
		|| ft_contains(input, 0, ft_strlen(input) - 1, '<'))
	{
		if (!forward_redirection_errors(input))
			forward(input);
		return (1);
	}
	return (0);
}

void	ft_echo(char *input)
{
	char	*final_output;
	char	*output;
	int		option;
	int		i;

	i = 5;
	option = is_echo_option(input, i);
	if (echo_forward(input))
		return ;
	i += option;
	output = ft_substr(input, i, ft_strlen(input));
	final_output = remove_quotes(output);
	free(output);
	printf("%s", final_output);
	free(final_output);
	if (!option)
		printf("\n");
	ft_cmd_status(0);
}
