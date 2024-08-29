/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:18:35 by davli             #+#    #+#             */
/*   Updated: 2024/08/27 16:13:19 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	g_signal;

void    ft_lstaddfront(t_list **lst, t_list *new)
{
    *lst = new;
    new->next = *lst;
    new->prev = *lst;
}

int	ft_lstnew_helper(t_list **new, int code)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (code == 1)
		while ((*new)->str[i] != '=')
			i++;
	else if (code == 2)
	{
		while ((*new)->str[j] != '=')
			j++;
		while ((*new)->str[i + j])
			i++;
	}
	return (i);
	
}

int	ft_lstnew(t_list **new, char *elem)
{
	int	i;
	int	len;
	int	len2;

	i = 0;
	(*new) = malloc(sizeof(t_list));
	if (*new == NULL)
		return (0);
	(*new)->str = elem;
	len = ft_lstnew_helper(new, 1) + 1;
	(*new)->name = malloc(len);
	while ((*new)->str[i] != '=')
	{
		(*new)->name[i] = (*new)->str[i];
		i++;
	}
	(*new)->name[i] = 0;
	len2 = ft_lstnew_helper(new, 2);
	(*new)->value = malloc(len2 + 1);
	i = 0;
	while ((*new)->str[i + len])
	{
		(*new)->value[i] = (*new)->str[len + i];
		i++;
	}
	(*new)->value[i] = 0;
	(*new)->next = NULL;
	(*new)->prev = NULL;
	return (1);
}

char	*ft_strdup(const char *src)
{
	char	*new;
	int		i;

	i = 0;
	while (src[i])
		i++;
	new = malloc(sizeof(char) * (i + 1));
	if (!new)
		return (NULL);
	i = -1;
	while (src[++i])
		new[i] = src[i];
	new[i] = '\0';
	return (new);
}

int	append(t_list **list, char *elem)
{
	t_list	*new;

	if (!ft_lstnew(&new, elem))
		return (0);
	if (!(*list))
		ft_lstaddfront(list, new);
	else
	{
		new->prev = (*list)->prev;
		new->next = (*list);
		(*list)->prev->next = new;
		(*list)->prev = new;
	}
	return (1);
}

void	add_env(t_list **list, char *env_var)
{
	char	*temp;

	temp = ft_strdup(env_var);
	if (!temp || !append(list, temp))
		free_list(list);
}

void	recup_env(t_var *var, char **env)
{
	t_list	*list;
	int		i;

	list = NULL;
	i = 0;
	while (env[i])
	{
		add_env(&list ,env[i]);
		i++;
	}
	var->env = list;
}

int	init_var(t_var *var, char **env)
{
	var->squote = 0;
	var->dquote = 0;
	var->dollar = 0;
	var->word = 0;
	var->temp = 0;
	var->tokens = tokenizer(var->input, var);
	if (!var->tokens)
		free(var->input);
	// var->tokens = transformers(var);
	var->count = count_token(var->input, var);
	recup_env(var, env);
	return (0);
}

int	minishell(t_var *var, char **env)
{
	int		i;
	t_list	*temp;

	while (1)
	{
		var->input = readline("minishell$> ");
		// var->input = " echo -n  this >file| &|cd invalid";
		if (!var->input)
			break ;
		init_var(var, env);
		if (!(*var->input))
			continue ;
		add_history(var->input);
		executer(var);
		i = 0;
		while (i < var->count)
		{
			printf("%d[", i + 1);
			printf("%s] ", var->tokens[i++]);
		}
		i = 0;
		temp = var->env;
		while (ft_strcmp(temp->name, "USER"))
			temp = temp->next;

		printf("%s\n", temp->str);
		printf("%s\n", temp->name);
		printf("%s\n", temp->value);
		printf("\n");
		if (var->input[i] == ':')
		{	
			while (i < count_token(var->input, var))
				free(var->tokens[i++]);
			free(var->tokens);
			free_list(&var->env);
			break ;
		}
		while (i < count_token(var->input, var))
			free(var->tokens[i++]);
		free(var->tokens);
		free_list(&var->env);
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_var	var;

	(void)argc;
	(void)argv;
	var.argv = env;
	var.found = 0;
	if (!getenv("PATH"))
		return (0);
	handle_signals();
	minishell(&var, env);
	// free(var.path);
	// free(var.temp_path);
	free(var.input);
	rl_clear_history();
	return (0);
}
