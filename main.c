/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:45:51 by davli             #+#    #+#             */
/*   Updated: 2024/07/18 16:42:33 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_command_path(const char *command)
{
	char	*path_env;
	char	*path;
	char	*token;
	char	*full_path;

	path_env = getenv("PATH");
	if (!path_env)
		return NULL;
	path = strdup(path_env);
	token = strtok(path, ":");
	full_path = malloc(strlen(token) + strlen(command) + 2);

	while (token != NULL) {
		sprintf(full_path, "%s/%s", token, command);
		if (access(full_path, X_OK) == 0) {
			free(path);
			return full_path;
		}
		token = strtok(NULL, ":");
	}

	free(full_path);
	free(path);
	return NULL;
}

void execute_command(char *command, char *const argv[])
{
    pid_t	pid;
	int		status;

	pid = fork();
    if (pid == -1)
	{
        perror("fork");
        return;
    } else if (pid == 0)
	{
        execve(command, argv, environ);
        perror("execve");
        exit(EXIT_FAILURE);
    } else
	{
        status;
        waitpid(pid, &status, 0);
    }
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '+' || str[i] == '-')
		if (str[i] == '-')
			sign = -1;
	while (str[i])
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}

int	main()
{
	t_var	var;
	int		i;
	int		j;
	char	*ret;
	char	*command_path;

	exit_value = 0;
	i = 0;
	ret = malloc(3 * sizeof(char) + 1);
	if (!ret)
		return (0);
	while (i < 3)
		ret[i++] = 0;
	while (1)
	{
		i = 0;
		j = 0;
		var.input = readline("minishell$> ");
		//		var.input = "exit 5 5 ";
		command_path = find_command_path(var.input);
		if (command_path)
		{
			var.argv = {command_path,NULL};
			execute_command(command_path_argv);
			free(command_path);
		}
		else
			printf("Command not found %s\n", var.input);
		add_history(var.input);
//		var.tokens = ft_split(var.input, ' ');
		while (var.input[i])
		{
			i++;
			j++;
			while (var.input[i] == ' ')
				i++;
			if (!var.input[i] || !"exit"[j])
			{
				exit_value = 1;
				break ;
			}
		}
		j = 0;
		while (var.input[i] >= '0' && var.input[i] <= '9')
		{
			ret[j++] = var.input[i++];
			while (var.input[i] == ' ')
				i++;
			if (!var.input[i])
			{
				if (ret[j] != '\0')
					ret = 0;
				exit_value = ft_atoi(ret);
			}
			else
			{
				printf("Too many arguments\n");
				exit_value = 0;
			}
		}
		if (exit_value > 255)
		{
			free(var.input);
			free(ret);
			printf("exit\n");
			exit (1);
		}
		if (exit_value != 0)
		{
			free(var.input);
			free(ret);
			printf("exit\n");
			exit (exit_value);
		}
		else
			free(var.input);
	}
}
