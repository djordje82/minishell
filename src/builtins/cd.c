/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodordev <dodordev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:51:35 by dodordev          #+#    #+#             */
/*   Updated: 2024/10/21 13:05:29 by dodordev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

/*get_directory: Determines the target directory based on the arguments \
and environment variables*/
static char	*get_directory(char **args, t_shell *shell)
{
	char	*dir;

	if (!args[1])
	{
		dir = minishell_get_env("HOME", shell->env);
		if (!dir)
			ft_putendl_fd("minishell: cd: HOME not set", STDERR_FILENO);
	}
	else
		dir = args[1];
	return (dir);
}

/*change_directory: attempts to change the current working directory and \
handles errors*/
static int	change_directory(char *dir)
{
	if (chdir(dir) == -1)
	{
		perror("minishell: cd");
		return (1);
	}
	return (0);
}

/*update_environment: updates the environment variables OLDPWD and PWD*/
static void	update_environment(char *old_pwd, char *new_pwd, t_shell *shell)
{
	minishell_set_env("OLDPWD", old_pwd, &shell->env);
	minishell_set_env("PWD", new_pwd, &shell->env);
}

int	ft_cd(char **args, t_shell *shell)
{
	char	*dir;
	char	*old_pwd;
	char	*new_pwd;

	if (count_args(args) > 2)
	{
		ft_putstr_fd(args[0], STDERR_FILENO);
		ft_putstr_fd(": too many arguments\n", STDERR_FILENO);
		return (1);
	}
	dir = get_directory(args, shell);
	if (!dir)
		return (1);
	old_pwd = getcwd(NULL, 0);
	if (change_directory(dir))
	{
		free(old_pwd);
		return (1);
	}
	new_pwd = getcwd(NULL, 0);
	update_environment(old_pwd, new_pwd, shell);
	free(old_pwd);
	free(new_pwd);
	return (0);
}
