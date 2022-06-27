/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:05:04 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/27 18:45:30 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int and_or_handler(t_params *params)
{
	t_cmd *cmd;

	cmd = (t_cmd *)params->cmd;
	if (cmd->right_delimiter == AND || cmd->right_delimiter == OR)
	{
		if (!ft_includes_str(BUILTINS, cmd->cmd_name))
		{
			waitpid(params->pids[params->index], &g_exit_code, 0);
			if (WIFSIGNALED(g_exit_code)) 
					g_exit_code = 128 + WTERMSIG(g_exit_code);
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