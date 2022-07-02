/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:13:49 by aoumouss          #+#    #+#             */
/*   Updated: 2022/07/02 22:20:39 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_dir(t_params *params);

void	ft_exec(t_params *params)
{
	char	*cmd;
	char	**args;
	char	**env;

	if (is_dir(params))
		return ;
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

static int	is_dir(t_params *params)
{
	DIR	*dir;

	if (!params->cmd->cmd_name)
		return (1);
	if (!ft_strcmp(params->cmd->cmd_name, ".."))
		return (0);
	if (!ft_strcmp(params->cmd->cmd_name, "."))
	{
		print_error_no_exit(".", "file argument required");
		ft_putstr_fd(".: usage: . filename [arguments]\n", STDERR_FILENO);
		exit(2);
	}
	dir = opendir(params->cmd->cmd_name);
	if (dir)
	{
		closedir(dir);
		print_error(params->cmd->cmd_name, "Is a directory");
		return (1);
	}
	return (0);
}
