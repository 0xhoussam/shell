/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:49:53 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/27 15:35:42 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	builtins_handler(t_params *params, int id);
static void	binary_handler(t_params *params, int id);
static int	and_or_handler(t_params *params);

void	executer(t_params *params, t_list *cmds)
{
	char		*cmd_name;
	int			i;

	init_params(params, ft_lstsize(cmds));
	heredocs_handler(cmds, params);
	i = 0;
	while (i < params->cmds_list_size)
	{
		params->cmd = (t_cmd *)cmds->content;
		params->index = i;
		cmd_name = (char *)params->cmd->cmd_name;
		if (ft_includes_str(BUILTINS, cmd_name))
			builtins_handler(params, i);
		else
			binary_handler(params, i);
		if (!and_or_handler(params))
			break ;
		cmds = cmds->next;
		i++;
	}
	close_pipes(params);
	wait_for_processes(1);
	free_params(params);
}

static void	builtins_handler(t_params *params, int id)
{
	char	*cmd_name;

	cmd_name = (char *)params->cmd->cmd_name;
	if (!ft_strcmp(cmd_name, "echo"))
		echo(params);
	if (!ft_strcmp(cmd_name, "cd"))
		cd(params);
	if (!ft_strcmp(cmd_name, "pwd"))
		pwd(params);
	if (!ft_strcmp(cmd_name, "export"))
		export(params);
	if (!ft_strcmp(cmd_name, "unset"))
		unset(params);
	if (!ft_strcmp(cmd_name, "env"))
		env(params);
	if (!ft_strcmp(cmd_name, "exit"))
		ft_exit(params);
}

static void	binary_handler(t_params *params, int id)
{
	params->pids[id] = fork();
	if (params->pids[id] < 0)
		print_error("fork", USE_ERRNO);
	if (!params->pids[id])
	{
		redir_handler(params);
		ft_exec(params);
		exit(0);
	}
}

static int	and_or_handler(t_params *params)
{	
	t_cmd	*cmd;

	cmd = (t_cmd *)params->cmd;
	if (cmd->right_delimiter == AND || cmd->right_delimiter == OR)
	{
		if (!ft_includes_str(BUILTINS, cmd->cmd_name))
		{
			waitpid(params->pids[params->index], &g_exit_code, 0);
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
