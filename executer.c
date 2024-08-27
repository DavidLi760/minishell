/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:27:02 by davli             #+#    #+#             */
/*   Updated: 2024/08/25 18:35:21 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *ft_strjoin(char *s1, char *s2)
{
    char    *str;
    size_t  i;
    size_t  c;

	i = ft_strlen(s1) + ft_strlen(s2);
    str = (char *)malloc(sizeof(char) * i + 2);
    if (!str)
		return (0);
	i = -1;
    while (s1[++i])
		str[i] = s1[i];
	str[i++] = '/';
    c = -1;
    while (s2[++c])
        str[i + c] = s2[c];
    str[i + c] = '\0';
    return (str);
}

int	execute_cmd(t_var *var)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = var->env->next;
	while (temp != var->env)
	{
		if (!ft_strisin(temp->str, "PATH="))
			var->temp_path = ft_strdup(temp->str);
		temp = temp->next;
	}
	var->path = ft_split(var->temp_path, ':');
	free(var->temp_path);
	g_signal = fork();
	if (g_signal == -1)
		return (0);
	if (g_signal == 0)
	{
		while (var->path[i] && !var->found)
		{
			var->found = 1;
			var->temp_path = ft_strjoin(var->path[i], var->tokens[0]);
			i++;
			if (execve(var->temp_path, var->tokens, 0) == -1)
				var->found = 0;
			free(var->temp_path);
		}
		i = 0;
		while (var->path[i])
			free(var->path[i++]);
		free(var->path);
		i = 0;
		while (i < count_token(var->input, var))
			free(var->tokens[i++]);
		free(var->tokens);
		free_list(&var->env);
		exit (0);
	}
	else if (g_signal > 0)
		wait(0);
	i = 0;
	while (var->path[i])
		free(var->path[i++]);
	free(var->path);
	return (0);
}

int	is_builtin(char *str, t_var *var)
{
	// if (ft_strcmp(str, "echo"))
	// 	return (ft_echo());
	// if (ft_strcmp(str, "cd"))
	// 	return (ft_cd());
	// if (ft_strcmp(str, "pwd"))
	// 	return (ft_pwd());
	// if (ft_strcmp(str, "export"))
	// 	return (ft_export());
	if (!ft_strcmp(str, "unset"))
		return (ft_unset(var));
	if (!ft_strcmp(str, "env"))
		return (ft_env(var));
	// if (ft_strcmp(str, "exit"))
	// 	return (ft_exit());
	// else
	// 	return (execute_cmd(var));
	return (0);
}

int	executer(t_var *var)
{
	is_builtin(var->tokens[0], var);
	return (0);
}
