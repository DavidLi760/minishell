/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:29:04 by davli             #+#    #+#             */
/*   Updated: 2024/08/25 17:00:21 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_unset(t_var *var)
{
	t_list  *temp;
	int        i;

	i = 1;
	while (var->tokens[i])
	{
		temp = var->env->next;
		while (temp != var->env)
		{
			if (!ft_strcmp(temp->str, var->tokens[i]))
			{
				temp->next->prev = temp->prev;
				temp->prev->next = temp->next;
                free(temp->str);
				break ;
			}
			temp = temp->next;
			if (temp == var->env && !ft_strcmp(temp->str, var->tokens[i]))
			{
				temp->next->prev = temp->prev;
				temp->prev->next = temp->next;
				free(temp->str);
			}
		}
		i++;
	}
	return (0);
}
