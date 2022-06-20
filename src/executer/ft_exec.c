/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:13:49 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/20 17:45:46 by marvin           ###   ########.fr       */
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
		print_error(params->cmd->cmd_name, CMD_NOT_FOUND);
	if (execve(cmd, args, params->env) < 0)
	{
		if (errno != ENOEXEC)
			print_error(ft_strjoin("execve: ", cmd), USE_ERRNO);
	}
	array_2d_free(args);
	free(cmd);
	return (0);
}
