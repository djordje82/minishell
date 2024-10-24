/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodordev <dodordev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:57:08 by dodordev          #+#    #+#             */
/*   Updated: 2024/10/17 17:57:32 by dodordev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	count_args(char **args)
{
	int	i;

	if (!args || !*args)
		return (EXIT_FAILURE);
	i = -1;
	while (args[++i])
		;
	return (i);
}