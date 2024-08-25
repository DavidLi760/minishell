/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:29:32 by davli             #+#    #+#             */
/*   Updated: 2024/08/25 15:29:39 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_env(t_var *var)
{
    t_list  *temp;

    printf("%s\n", var->env->str);
    temp = var->env->next;
    while (temp != var->env)
    {
        if (temp->is_unset == 0)
            printf("%s\n", temp->str);
        temp = temp->next;
    }
    return (0);
}