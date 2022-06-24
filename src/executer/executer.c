/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:49:53 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/24 19:12:26 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_params(t_params *params, char **env, int list_size);
void	builtins_handler(t_params *params, t_list *list, int id);
void	binary_handler(t_params *params, t_list *list, int id);
void	and_or_handler(t_params *params);

char	**executer(t_list *list, char **env)
{
	t_params	params;
	char		*cmd_name;
	int			i;

	init_params(&params, env, ft_lstsize(list));
	heredocs_handler(list, &params);
	i = 0;
	while (i < params.cmds_list_size)
	{
		params.cmd = (t_cmd *)list->content;
		params.index = i;
		cmd_name = (char *)params.cmd->cmd_name;
		if (ft_includes_str(BUILTINS, cmd_name))
			builtins_handler(&params, list, i);
		else
			binary_handler(&params, list, i);
		and_or_handler(&params);
		list = list->next;
		i++;
	}
	close_pipes(&params);
	wait_for_processes(1);
	return (params.env);
}

void	init_params(t_params *params, char **env, int list_size)
{
	params->pipes = init_pipes(list_size + 1);
	params->pids = malloc(sizeof(int) * (list_size));
	params->cmds_list_size = list_size;
	params->env = env;
}

void	builtins_handler(t_params *params, t_list *list, int id)
{
	char	*cmd_name;

	cmd_name = (char *)params->cmd->cmd_name;
	if (!ft_strcmp(cmd_name, "echo"))
		echo(params);
	if (!ft_strcmp(cmd_name, "cd"))
		cd(params);
	if (!ft_strcmp(cmd_name, "pwd"))
		pwd(params, 1);
	if (!ft_strcmp(cmd_name, "export"))
		export(params);
	if (!ft_strcmp(cmd_name, "unset"))
		unset(params);
	if (!ft_strcmp(cmd_name, "env"))
		env(params);
	if (!ft_strcmp(cmd_name, "exit"))
		ft_exit(params);
}

void	binary_handler(t_params *params, t_list *list, int id)
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

void	and_or_handler(t_params *params)
{	
	t_cmd	*cmd;

	cmd = (t_cmd *)params->cmd;
	if (cmd->right_delimiter == AND || cmd->right_delimiter == OR)
	{
		if (!ft_includes_str(BUILTINS, cmd->cmd_name))
		{
			waitpid(params->pids[params->index], &g_exit_code, 0);
			wait_for_processes(0);
		}
		if (WEXITSTATUS(g_exit_code) != 0 && cmd->right_delimiter == AND)
		{
			wait_for_processes(0);
			exit(WEXITSTATUS(g_exit_code));
		}
		if (WEXITSTATUS(g_exit_code) == 0 && cmd->right_delimiter == OR)
		{
			wait_for_processes(0);
			exit(EXIT_SUCCESS);
		}
	}
}
