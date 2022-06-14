/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:49:53 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/14 15:49:44 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int 	wait_for_processes(int size);
void 	init_params(t_params *params, char **env, int list_size);
void 	builtins_handler(t_params *params, t_list *list, int id);
void 	binary_handler(t_params *params, t_list *list, int id);

int executer(t_list *list, char **env)
{
	t_params params;
	char *cmd_name;
	int i;

	init_params(&params, env, ft_lstsize(list));
	i = 0;
	while (i < params.cmds_list_size)
	{
		params.cmd = (t_cmd *)list->content;
		params.index = i;
		cmd_name = (char *)params.cmd->cmd_name;
		if (ft_strnstr(BUILTINS, cmd_name, ft_strlen(cmd_name)))
			builtins_handler(&params, list, i);
		else
			binary_handler(&params, list, i);
		close_pipe(params.pipes[i]);
		list = list->next;
		i++;
	}
	close_pipe(params.pipes[i]);
	wait_for_processes(params.cmds_list_size);
	return (0);
}

int	wait_for_processes(int size)
{
	int i;
	int status;

	i = 0;
	while (i < size)
	{
		waitpid(-1, &g_exit_code, 0);
		i++;
	}
	return (0);
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
		pwd(params);
	if (!ft_strcmp(cmd_name, "export"))
		export(params);
	if (!ft_strcmp(cmd_name, "unset"))
		unset(params);
	if (!ft_strcmp(cmd_name, "env"))
		env(params);
	if (!ft_strcmp(cmd_name, "exit"))
		ft_exit(params);
	return;
}

void	binary_handler(t_params *params, t_list *list, int id)
{
	params->pids[id] = fork();
	if (params->pids[id] < 0)
		print_error("fork", USE_ERRNO);
	if (!params->pids[id])
	{
		ft_exec(params);
		exit(0);
	}
}
