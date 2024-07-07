/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:14:55 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/05 15:23:58 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define MAX_ARGS 64
# define MAX_PATH_LENGTH 1024

# include <sys/wait.h>
# include <sys/stat.h>
# include <string.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>


// User Commands
void	execute_command(char **args);
int		create_pipe(int pipe_fds[2]);
int		exec_user_command(char *input);
char	**parse_user_input(char *input);
int		handle_single_command(char *input);
char	*find_in_path(const char *command);
int		exec_command_with_pipes(char *input, int i);
char	*get_command_path(const char *command);
int		wait_for_all_commands(int num_commands);
char	*find_user_command(const char *command);
char	*find_absolute_command(const char *command);
char	*get_command_path_from_args(const char *arg);
int		split_commands(int *in_fd, char *input, char *commands[]);
int		handle_file_redirection(char **args, int index);
int		handle_heredoc_redirection(char **args, int index);
int		process_input_redirection(char **args, char *input);
int		exec_single_command(char **args, char *command_path, int in_fd);
int		update_input_fd(int in_fd, int i, int num_commands, int pipe_fds[2]);
int		fork_and_exec_command(char **args, int i, int num_commands, int in_fd, int pipe_fds[2]);
void	setup_child_pipes(int i, int num_commands, int in_fd, int pipe_fds[2]);
int		hdoc_helper(char **delimiter, FILE **temp_file, char **args, int index);
void	hdoc_helper2(FILE *temp_file, char ***args, int index, int *in_fd);

// Built-Ins
void	ft_env(void);
void	ft_pwd(void);
void	ft_cd(char *input);
void	ft_exit(char *input);
void	ft_echo(char *input);
void	ft_unset(char *input);
void	ft_export(char *input);
void	ft_cmd_status(int status);
int		exec_user_command(char *input);
int		is_echo_option(char *input, int i);

// Signals
void	signal_constructor(void);
void	sigint_handler(int signum);

// Main
void	input_manager(char *input);
void	minishell_init(char **input);
void	command_not_found(char *input);
int		check_command(char *input, char *test);

// Redirections
int		forward(char *input);
char	*ft_forward_output(char *str);
int		ft_forward_output_len(char *str);
int		forward_redirection_errors(char *input);
int		backward_redirection_errors(char *input);
char	*ft_forward_file(char *input, char *sep);

// Quotes
char	*remove_quotes(char *input);
int		is_in_quote(char *str, int index);

// Utils
char	*ft_itoa(int n);
int		ft_isspace(int c);
int		ft_isalpha(char c);
int		ft_strlen(char	*str);
int		ft_isnumber(char *str);
char	*ft_fetchenv(char *str);
int		ft_atoi(const char *str);
char	*ft_strtrim(char *input);
int		is_empty_string(char *str);
int		ft_strtrim_len(char *input);
int		ft_subchar(char *str, char *sub);
char	*ft_substr(char *str, int from, int to);
char	*ft_strtok(char *str, const char *delim);
int		is_last_characters(char *input, int index);
char	*ft_strchr(const char *str, int character);
size_t	ft_strspn(const char *str, const char *delim);
int		ft_strcmp(const char *str1, const char *str2);
size_t	ft_strcspn(const char *str, const char *reject);
int		next_occ(char *str, int i, char *sep, int reverse);
int		next_occ_noq(char *str, int i, char *sep, int reverse);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
int		ft_contains(char *str, int from_index, int to_index, char c);
int		ft_contains_seq(char *str, int from_index, int to_index, char *seq);
void	ft_strtrim_helper(int *in_dquote, int *in_squote, char *input, int i);

#endif /* MINISHELL_H */