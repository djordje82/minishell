/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodordev <dodordev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:54:29 by dodordev          #+#    #+#             */
/*   Updated: 2024/10/24 15:38:19 by dodordev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	ft_exit(char **args, t_shell *shell)
{
	int	exit_code;

	if (count_args(args) > 2)
	{
		ft_putstr_fd("exit\n", STDERR_FILENO);
		exit_error("", NULL, 1, shell);
	}
	if (args[1] && !is_numeric(args[1]))
	{
		ft_putstr_fd("exit\n", STDERR_FILENO);
		exit_error("", args[1], 255, shell);
	}
	if (args[1])
		exit_code = (ft_atoi(args[1]) % 256); //ft_atol instead of ft_atoi to handle owerflow
	else
	{
		exit_code = 0;
	}
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	shell->exit_status = exit_code;
	exit(exit_code);
}