/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:48:16 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/05 13:53:32 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

void	update_quote(int *in_dq, int *in_sq, int is_double)
{
	if (is_double)
	{
		if (*in_dq)
			*in_dq = 0;
		else
			*in_dq = 1;
	}
	else
	{
		if (*in_sq)
			*in_sq = 0;
		else
			*in_sq = 1;
	}
}

void	init_remove_quotes(int *in_sq, int *in_dq, int *i, int *j)
{
	*in_sq = 0;
	*in_dq = 0;
	*i = 0;
	*j = 0;
}

char	*remove_quotes(char *input)
{
	int		in_sq;
	int		in_dq;
	int		i;
	int		j;
	char	*output;

	init_remove_quotes(&in_sq, &in_dq, &i, &j);
	output = malloc(ft_strlen(input) + 1);
	if (!output)
		exit(EXIT_FAILURE);
	while (input[i] != '\0')
	{
		if (input[i] == '\"' || input[i] == '\'')
		{
			if ((in_sq && input[i] == '\"') || (in_dq && input[i] == '\''))
				output[j++] = input[i];
			else
				update_quote(&in_dq, &in_sq, input[i] == '\"');
		}
		else
			output[j++] = input[i];
		i++;
	}
	output[j] = '\0';
	return (output);
}

int	is_in_quote_helper(char *str, int *sq_start, int *sq_end, int *dq_start)
{
	int	double_quote_end;
	int	i;

	i = 0;
	double_quote_end = -1;
	while (str[i])
	{
		if (str[i] == '\'' && *sq_start == -1)
			*sq_start = i;
		else if (str[i] == '\'' && *sq_start != -1 && *sq_end == -1)
			*sq_end = i;
		if (str[i] == '\"' && *dq_start == -1)
			*dq_start = i;
		else if (str[i] == '\"' && *dq_start != -1 && double_quote_end == -1)
			double_quote_end = i;
		i++;
	}
	return (double_quote_end);
}

int	is_in_quote(char *str, int index)
{
	int	sq_start;
	int	dq_start;
	int	sq_end;
	int	double_quote_end;

	sq_start = -1;
	dq_start = -1;
	sq_end = -1;
	double_quote_end = is_in_quote_helper(str, &sq_start, &sq_end, &dq_start);
	if (sq_start < index && sq_end > index)
	{
		if (dq_start < index && double_quote_end > index)
		{
			if (sq_start < dq_start && sq_end > double_quote_end)
				return (2);
			else if (dq_start < sq_start && double_quote_end > sq_end)
				return (1);
		}
		else
			return (2);
	}
	if (dq_start < index && double_quote_end > index)
		return (1);
	return (0);
}
