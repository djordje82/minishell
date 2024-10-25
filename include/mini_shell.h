/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodordev <dodordev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:45:14 by dodordev          #+#    #+#             */
/*   Updated: 2024/10/24 13:16:53 by dodordev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SHELL_H
# define MINI_SHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../libft/inc/libft.h"
# include <fcntl.h>
# include <errno.h>

# define SHELL_NAME "minishell"
# define TOKEN_DELIMITERS " \t\n\r\a"
# define REDIR_DELIMITERS ">>"
# define PIPE_DELIMITERS "|"
# define PROMPT "minishell> "
# define SPECIAL "<>|;"

/*ERROR CODES*/
# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1
# define EXIT_ERROR 2
# define EXIT_NOT_FOUND 127
# define EXIT_NOT_EXECUTABLE 126
# define EXIT_INTERRUPT 130
# define EXIT_QUIT 131
# define EXIT_PIPE 133
# define EXIT_FORK 134
# define EXIT_REDIRECTION 135
# define EXIT_SYNTAX 136
# define EXIT_CD 137
# define EXIT_ENV 138
# define EXIT_MALLOC 139
# define EXIT_SIGNAL 140
# define EXIT_UNEXPECTED 141
# define EXIT_NOT_IMPLEMENTED 142

/*ERROR MESSAGES*/
# define ERR_MAL "Memory allocation error"

/*GLOBAL VARIABLE*/
extern int	g_sig;

/*STRUCTS*/
typedef struct s_command
{
	char		**args;
	int			argc;
}			t_command;

typedef struct s_shell
{
	char		*input;
	t_list		*tokens;
	t_list		*env;
	int			exit_status;
	char		**envp;
	t_command	*commands;
}			t_shell;

/*BUILTINS*/
int		ft_cd(char **args, t_shell *shell);
int		ft_pwd(void);
void	ft_echo(char **args);
void	ft_export(char **args);
void	ft_unset(char **args);
void	ft_env(void);
void	ft_exit(char **args);

/*ERROR HANDLIN AND FREEING*/
int		exit_error(char *err_msg, char *src, int err_code, t_shell *shell);

/*UTILS*/
int		count_args(char **args);
int		is_numeric(const char *str);
#endif
