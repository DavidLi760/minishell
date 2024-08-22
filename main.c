/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:18:35 by davli             #+#    #+#             */
/*   Updated: 2024/08/22 19:33:52 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	g_signal;

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

int	count_token(char *str, t_var *var)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		while (str[i] != ' ' && str[i] != '>' && str[i] != '<' && str[i] != '|' && str[i])
		{
			if (str[i] == '\'')
			{
				var->squote = 1;
				i++;
			}
			if (str[i] == '"')
			{
				var->dquote = 1;
				i++;
			}
			while ((var->squote == 1 || var->dquote == 1) && str[i])
			{
				if (str[i] == '\'' && var->squote == 1)
					var->squote = 0;
				if (str[i] == '"' && var->dquote == 1)
					var->dquote = 0;
				i++;
			}
			if (str[i] != ' ' && str[i] != '>' && str[i] != '<' && str[i] != '|' && str[i])
				i++;
			var->word = 1;
		}
		if (var->word == 1)
		{
			var->word = 0;
			count++;
		}
		if (str[i] == '|')
		{
			count++;
			i++;
		}
		else if (str[i] == '<')
		{
			count++;
			i++;
			j = 0;
			while (str[i] == '<' && j++ < 3)
				i++;
		}
		else if (str[i] == '>')
		{
			count++;
			i++;
			if (str[i] == '>')
				i++;
		}
	}
	return (count);
}

char	**tokenizer(char *str, t_var *var)
{
	int		i;
	int		j;
	int		k;
	int		l;
	char	**tokens;

	i = 0;
	k = 0;
	tokens = malloc(sizeof(char *) * count_token(str, var) + 1);
	while (str[i])
	{
		j = 0;
		l = 0;
		while (str[i] == ' ')
			i++;
		while (str[i] != ' ' && str[i] != '>' && str[i] != '<' && str[i] != '|' && str[i])
		{
			if (str[i] == '\'')
			{
				var->squote = 1;
				i++;
				j++;
			}
			if (str[i] == '"')
			{
				var->dquote = 1;
				i++;
				j++;
			}
			while ((var->squote == 1 || var->dquote == 1) && str[i])
			{
				if (str[i] == '\'' && var->squote == 1)
					var->squote = 0;
				if (str[i] == '"' && var->dquote == 1)
					var->dquote = 0;
				i++;
				j++;
			}
			if (str[i] != ' ' && str[i] != '>' && str[i] != '<' && str[i] != '|' && str[i])
			{
				i++;
				j++;
			}
		}
		if (j > 0)
			tokens[k] = malloc(sizeof(char) * (j + 1));
		while (l < j)
		{
			tokens[k][l] = str[i - j + l];
			l++;
		}
		if (j > 0)
		{
			tokens[k][l] = 0;
			k++;
		}
		if (str[i] == '|')
		{
			tokens[k] = malloc(sizeof(char) * 2);
			tokens[k][0] = '|';
			i++;
			tokens[k][1] = 0;
			k++;
		}
		else if (str[i] == '<')
		{
			l = 0;
			tokens[k] = malloc(sizeof(char) * 3);
			tokens[k][l++] = str[i];
			i++;
			while (str[i] == '<')
				tokens[k][l++] = str[i++];
			tokens[k][l] = 0;
			k++;
		}
		else if (str[i] == '>')
		{
			l = 0;
			tokens[k] = malloc(sizeof(char) * 3);
			tokens[k][l++] = str[i];
			i++;
			if (str[i] == '>')
				tokens[k][l++] = str[i++];
			tokens[k][l] = 0;
			k++;
		}
		else if (str[i] == ' ')
			while (str[i] == ' ')
				i++;
	}
	return (tokens);
}

// void    ft_lstadd_front(t_list **lst, t_list *new)
// {
//     *lst = new;
//     new->next = *lst;
//     new->prev = *lst;
// }

// int	ft_lstnew(t_list **new, char *elem)
// {
// 	(*new) = malloc(sizeof(t_list));
// 	if (*new == NULL)
// 		return (0);
// 	(*new)->str = elem;
// 	(*new)->next = NULL;
// 	(*new)->prev = NULL;
// 	return (1);
// }

// void	append(t_list **list, char elem)
// {
// 	t_list	*new;

// 	if (!ft_lstnew(&new, elem))
// 		return (0);
// 	if (!(*list))
// 		ft_lstaddfront(list, new);
// 	else
// 	{
// 		new->prev = (*list)->prev;
// 		new->next = (*list);
// 		(*list)->prev->next = new;
// 		(*list)->prev = new;
// 	}
// 	return (1);
// }

// void	add_env(t_list **list, char *env_var)
// {
// 	char	*temp;

// 	temp = ft_strdup(env_var);
// 	if (!temp || !append(list, temp))
// 		free_list(list);
// }

// void	recup_env(t_var *var, char **env)
// {
// 	t_list	*list;
// 	int		i;

// 	list = NULL;
// 	i = 0;
// 	while (env[i])
// 	{
// 		add_env(&list ,env[i]);
// 		i++;
// 	}
// 	var->env = list;
// }

int	init_var(t_var *var)
{
	var->squote = 0;
	var->dquote = 0;
	var->word = 0;
	handle_signals();
	// recup_env(var, env);
	return (0);
}

int	main(int argc, char **argv)
{
	t_var	var;
	int		i;
	char	**tokens;
	int		count;

	(void)argc;
	(void)argv;
	tokens = 0;
	if (!getenv("PATH"))
		return (0);
	while (1)
	{
		i = 0;
		init_var(&var);
		var.input = readline("minishell$> ");
		if (!var.input)
			break ;
		tokens = tokenizer(var.input, &var);
		if (!tokens)
			free(var.input);
		count = count_token(var.input, &var);
		while (i < count)
		{
			printf("%s", tokens[i++]);
			printf(" %d\n", count);
		}
		add_history(var.input);
		i = 0;
		if (var.input[i] == ':')
		{	
			while (i < count_token(var.input, &var))
				free(tokens[i++]);
			free(tokens);
			break ;
		}
		while (i < count_token(var.input, &var))
			free(tokens[i++]);
		free(tokens);
	}
	return (0);
}
