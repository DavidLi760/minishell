/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:12:51 by davli             #+#    #+#             */
/*   Updated: 2024/08/24 18:28:13 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	ft_strisin(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
		i++;
	if (!s2[i] && s1[i])
			return (0);
	return (1);
}

char	*env_value(t_var *var, char *str)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = var->env->next;
	while (temp != var->env)
	{
		if (!ft_strisin(temp->str, str))
			var->temp_path = ft_strdup(temp->str + ft_strlen(str));
		temp = temp->next;
	}
	return (var->temp_path);
}

int	cmp_char(char c1, char c2)
{
	if (c1 == c2)
		return (1);
	return (0);
}

int	is_alnum(char c)
{
	if ((c >= 'a' && c <= 'z') && (c >= 'A' && c <= 'Z') && (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int	free_list(t_list **list)
{
	t_list	*temp;
	t_list	*current;

	if (!(*list))
		return (0);
	current = *list;
	while (current->next != *list)
	{
		temp = current;
		current = current->next;
		free(temp->str);
		free(temp);
	}
	free(current->str);
	free(current);
	*list = NULL;
	return (0);
}
