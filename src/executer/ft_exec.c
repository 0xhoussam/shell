/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:13:49 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/25 13:19:14 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec(t_params *params)
{
	char	*cmd;
	char	**args;

	cmd = get_cmd_path(params);
	args = join_args(params->cmd->args);
	if (!cmd)
		print_error(params->cmd->cmd_name, CMD_NOT_FOUND);
	if (execve(cmd, args, params->env) < 0)
	{
		free_2d_array(args);
		if (errno != ENOEXEC)
			print_error(ft_strjoin("execve: ", cmd), USE_ERRNO);
	}
	free_2d_array(args);
	free(cmd);
	return (0);
}
