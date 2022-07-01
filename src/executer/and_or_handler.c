/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:05:04 by aoumouss          #+#    #+#             */
/*   Updated: 2022/07/01 13:56:54 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_signaled(void);

int	and_or_handler(t_params *params)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)params->cmd;
	if (cmd->right_delimiter == AND || cmd->right_delimiter == OR)
	{
		if (!ft_includes_str(BUILTINS, cmd->cmd_name))
		{
			waitpid(params->pids[params->index], &g_exit_code, 0);
			if (is_signaled())
				return (0);
			else
				g_exit_code = WEXITSTATUS(g_exit_code);
		}
		wait_for_processes(0);
		if (g_exit_code != 0 && cmd->right_delimiter == AND)
			return (0);
		if (g_exit_code == 0 && cmd->right_delimiter == OR)
			return (0);
	}
	return (1);
}

static int	is_signaled(void)
{
	if (WIFSIGNALED(g_exit_code))
	{
		g_exit_code = 128 + WTERMSIG(g_exit_code);
		if (g_exit_code == 130)
			ft_putstr_fd("\n", STDOUT_FILENO);
		if (g_exit_code == 131)
			ft_putstr_fd("Quit (core dumped) \n", STDOUT_FILENO);
		return (1);
	}
	return (0);
}
