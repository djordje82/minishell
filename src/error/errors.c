/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodordev <dodordev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:07:41 by dodordev          #+#    #+#             */
/*   Updated: 2024/10/17 16:16:41 by dodordev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	ft_close(int fd)
{
	if (fd >= 0)
	{
		close(fd);
		fd = -1;
	}
}

void	free_meta(t_meta *meta)
{
	if (meta->pid)
	{
		free(meta->pid);
		meta->pid = NULL;
	}
	if (meta->pipe)
	{
		free_array((void **)meta->pipe, meta->n_cmnds + 1);
		meta->pipe = NULL;
	}
}

static void	free_envp(t_meta *meta)
{
	if (meta->envp)
		free_array((void **)meta->envp, -1);
	meta->envp = NULL;
}

int	exit_error(char *err_msg, char *src, int err_code, t_meta *meta)
{
	char	*result;

	if (src)
	{
		result = ft_strjoin(src, err_msg);
		if (!result)
		{
			ft_putendl_fd(ERR_MEM, STDERR_FILENO);
			exit(-1);
		}
		ft_putendl_fd(result, STDERR_FILENO);
		free(result);
	}
	else if (err_msg)
		ft_putendl_fd(err_msg, STDERR_FILENO);
	if (meta)
	{
		free_list(meta->cmnd_lst);
		free_meta(meta);
		free_envp(meta);
		meta->exit_code = err_code;
	}
	rl_clear_history();
	exit(err_code);
}