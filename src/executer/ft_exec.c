/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:13:49 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/27 15:26:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exec(t_params *params)
{
	char	*cmd;
	char	**args;
	char	**env;

	cmd = get_cmd_path(params);
	args = join_args(params->cmd->args);
	env = env_list_to_array(params->env);
	if (!cmd)
		print_error(params->cmd->cmd_name, CMD_NOT_FOUND);
	if (execve(cmd, args, env) < 0)
	{
		if (errno != ENOEXEC)
		{
			free_2d_array(args);
			free_2d_array(env);
			print_error(ft_strjoin("execve: ", cmd), USE_ERRNO);
		}
	}
	free_2d_array(args);
	free_2d_array(env);
	free(cmd);
}
