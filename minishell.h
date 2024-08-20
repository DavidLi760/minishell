/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:46:45 by davli             #+#    #+#             */
/*   Updated: 2024/08/20 19:45:40 by davli            ###   ########.fr       */
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
# include <readline/readline.h>
# include <readline/history.h>

extern pid_t	g_signal;

typedef struct s_var
{
	char	*input;
	int		squote;
	int		dquote;
	int		word;
}	t_var;

char	**ft_split(char const *str, char c);

#endif
