/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:00:10 by davli             #+#    #+#             */
/*   Updated: 2024/07/18 15:09:51 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	token_counter(char *str)
{
	int	i;
	int	token;

	i = 0;
	token = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '\'' && str[i + 1] == '\'')
			i++;
		else if (str[i] == '\'' && str[i + 1] != '\'')
			while (str[i] != '\'')
				i++;
		if (str[i] == '\"' && str[i + 1] == '\"')
			i++;
		else if (str[i] == '\"' && str[i + 1] != '\"')
			while (str[i] != '\"')
				i++;
		while (str[i] != ' ' || str[i] != '>' || str[i] != '<' || str[i] != '|')
			i++;
		if (str[i] == ' ' || str[i] == '>' || str[i] == '<' || str[i] == '|')
		{
			token++;
			if (str[i] != ' ')
				token++;
			i++;
			while (str[i] == '>' || str[i] == '<' || str[i] == '|')
				i++;
		}
	}
	return (token);
}

char	**ft_token(char *str)
{
	char	**res;

	res =
	while ()
}
