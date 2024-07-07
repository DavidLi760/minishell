/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:11:13 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/05 14:05:23 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/minishell.h"

int	ft_export_var_subs(char **substr1, char **substr2, char *input, int from)
{
	if (*substr1 == NULL)
	{
		ft_cmd_status(1);
		return (1);
	}
	if (!ft_isalpha(input[from]))
	{
		printf("bash: export: `%s': not a valid identifier\n", *substr1);
		ft_cmd_status(1);
		return (1);
	}
	*substr2 = ft_substr(input, from, next_occ(input, from, "=", 0));
	if (*substr2 == NULL)
	{
		ft_cmd_status(1);
		return (free(*substr1), 1);
	}
	return (0);
}

int	ft_export_var(char *input, int from, int to)
{
	char	*substr1;
	char	*substr2;
	char	*substr3;

	substr1 = ft_substr(input, from, to - 1);
	if (ft_export_var_subs(&substr1, &substr2, input, from))
		return (0);
	substr3 = ft_substr(input, next_occ(input, from, "=", 0) + 2, to);
	if (substr3 == NULL)
	{
		ft_cmd_status(1);
		return (free(substr1), free(substr2), 0);
	}
	if (setenv(substr2, substr3, 1) != 0)
	{
		ft_cmd_status(1);
		perror("setenv failed\n");
	}
	ft_cmd_status(0);
	return (free(substr1), free(substr2), free(substr3), to + 2);
}

int	ft_export_child_process(char *input, int from, int to)
{
	char	*substr;

	substr = ft_substr(input, from, to);
	if (substr == NULL)
	{
		ft_cmd_status(1);
		return (0);
	}
	if (!ft_isalpha(input[from]))
	{
		printf("bash: export: `%s': not a valid identifier\n", substr);
		ft_cmd_status(1);
		return (0);
	}
	if (setenv(substr, "", 1) != 0)
	{
		perror("setenv failed\n");
		ft_cmd_status(1);
	}
	ft_cmd_status(0);
	return (free(substr), to + 2);
}

void	ft_export_basic(void)
{
	extern char	**environ;
	int			i;

	i = 0;
	while (environ[i])
	{
		printf("declare -x %s\n", environ[i]);
		i++;
	}
}

void	ft_export(char *input)
{
	int	sucess_code;
	int	next;
	int	i;

	if (is_last_characters(input, 5))
		ft_export_basic();
	else
	{
		i = 7;
		sucess_code = 0;
		while (input[i])
		{
			next = next_occ(input, i + 1, " ", 0);
			if (ft_contains(input, i, next, '='))
				sucess_code = ft_export_var(input, i, next);
			else
				sucess_code = ft_export_child_process(input, i, next);
			if (sucess_code == 0)
				return ;
			else
				i = sucess_code;
		}
	}
}
