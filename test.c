/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:00:58 by davli             #+#    #+#             */
/*   Updated: 2024/08/21 16:01:19 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_execve(char *path, char **arg)
{
    execve(path, arg, 0);
    return (0);
}

int main(int argc, char **argv)
{
    (void)argc;
    argv[0] = "ls";
    argv[1] = 0;
    ft_execve("/bin/pwd", argv);
}