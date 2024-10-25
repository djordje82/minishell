/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodordev <dodordev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:07:41 by dodordev          #+#    #+#             */
/*   Updated: 2024/10/24 13:04:38 by dodordev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	free_shell(t_shell *shell)
{
	if (shell->pid)
	{
		free(shell->pid);
		shell->pid = NULL;
	}
	if (shell->pipe)
	{
		free_array((void **)shell->pipe, shell->n_cmnds + 1);
		shell->pipe = NULL;
	}
}

static void	free_envp(t_shell *shell)
{
	if (shell->envp)
		free_array((void **)shell->envp, -1);
	shell->envp = NULL;
}

int	exit_error(char *err_msg, char *src, int err_code, t_shell *shell)
{
	char	*result;

	if (src)
	{
		result = ft_strjoin(src, err_msg);
		if (!result)
		{
			ft_putendl_fd(ERR_MAL, STDERR_FILENO);
			exit(-1);
		}
		ft_putendl_fd(result, STDERR_FILENO);
		free(result);
	}
	else if (err_msg)
		ft_putendl_fd(err_msg, STDERR_FILENO);
	if (shell)
	{
		free_list(shell->commands);
        //free(shell);
        //free(shell->envp);
        //free_commands(shell->commands);
        shell->exit_status = err_code;
	}
	rl_clear_history();
	exit(err_code);
}