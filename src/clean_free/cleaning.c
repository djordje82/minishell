/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodordev <dodordev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:08:30 by jadyar            #+#    #+#             */
/*   Updated: 2024/10/25 14:16:00 by dodordev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	minishell_reset(t_shell *shell)
{
	if (shell->input)
	{
		free(shell->input);
		shell->input = NULL;
	}
	if (shell->tokens)
	{
		ft_lstclear(&shell->tokens);
		free(shell->tokens);
		shell->tokens = NULL;
	}
}

//  memoery leak here
int	minishell_clean(t_shell *shell, int exit_code)
{
	if (shell->input)
		minishell_free_token(shell->input);
	if (shell->tokens)
	{
		ft_lstclear(&shell->tokens);
	}
	if (shell->env)
	{
		minishell_free_env(shell->env);
		ft_lstclear(&shell->env);
	}
	return (exit_code);
}
