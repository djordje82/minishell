/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodordev <dodordev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:52:07 by dodordev          #+#    #+#             */
/*   Updated: 2024/10/25 13:25:40 by dodordev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	ft_echo(char **args)
{
	int	i;
	int	newline;

	if (count_args(args) <= 1)
	{
		ft_putstr_fd("No arguments for echo\n", STDERR_FILENO);
		return (-1);
	}

	i = 1;
	newline = 1;
	if (args[1] && !ft_strcmp(args[1], "-n"))
	{
		newline = 0;
		i++;
	}
	/*
	if the arg is -na or -nn you will print -na or -nn
	 in the while loop and print the new line
	*/
	while (args[i])
	{
		ft_putstr_fd(args[i], STDOUT_FILENO);
		if (args[i + 1])
			ft_putstr_fd(" ", STDOUT_FILENO);
		i++;
	}
	if (newline)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (EXIT_SUCCESS);
}