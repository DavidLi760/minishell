/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:46:45 by davli             #+#    #+#             */
/*   Updated: 2024/08/24 17:08:15 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdint.h>
# include <sys/wait.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

extern pid_t	g_signal;

typedef struct s_list
{
	char			*str;
	char			*name;
	char			*value;
	int				is_unset;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_var
{
	char	*input;
	char	*temp;
	int		dollar;
	int		squote;
	int		dquote;
	int		word;
	int		count;
	char	**tokens;
	char	*temp_path;
	char	**path;
	char	**argv;
	int		pipes[2];
	int		found;
	t_list	*env;
}	t_var;

char	**ft_split(char const *str, char c);
char	**tokenizer(char *str, t_var *var);
char	**transformers(t_var *var);
int		count_token(char *str, t_var *var);
void	handle_signals(void);
int		free_list(t_list **list);
int		executer(t_var *var);
int		ft_env(t_var *var);
int		ft_unset(t_var *var);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
int		ft_strisin(char *s1, char *s2);
char	*ft_strdup(const char *src);
int		is_alnum(char c);
int		cmp_char(char c1, char c2);

#endif
