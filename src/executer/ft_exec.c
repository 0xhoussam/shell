/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:13:49 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/14 15:52:32 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_exec(t_params *params)
{
	char *cmd;
	char **args;

	cmd = get_cmd_path(params);
	args = join_args(params->cmd);
	if (!cmd)
		return (print_error(params->cmd->cmd_name, CMD_NOT_FOUND));
	redir_handler(params);
	if (execve(cmd, args, params->env) < 0)
	{
		print_error("execve", USE_ERRNO);
		array_2d_free(args);
		free(cmd);
		// free_params(params);
		return (print_error(params->cmd->cmd_name, EXECVE_FIALED));
	}
	array_2d_free(args);
	free(cmd);
	return (0);
}
