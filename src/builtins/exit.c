/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodordev <dodordev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:54:29 by dodordev          #+#    #+#             */
/*   Updated: 2024/10/21 15:37:39 by dodordev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	ft_exit(char **args)
{
	int	i;

	i = 1;
	if (args[1])
	{
		if (ft_isdigit(args[1][0]) == 0)
		{
			ft_putstr_fd("minishell: exit:", STDERR_FILENO);
			ft_putstr_fd(args[1], STDERR_FILENO);
			ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
			exit(255);
		}
		else if (args[2])
		{
			ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
			exit(1);
		}
		else
			exit(ft_atoi(args[1]));
	}
	else
		exit(0);
}