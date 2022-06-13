/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:49:53 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/13 17:58:36 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int wait_for_processes(int size);
void init_params(t_params *params, char **env, int list_size);

int executer(t_list *list, char **env)
{
	t_params params;
	int i;

	g_exit_code = 0;
	init_params(&params, env, ft_lstsize(list));
	i = 0;
	while (i < params.cmds_list_size)
	{
		params.pids[i] = fork();
		if (params.pids[i] < 0)
			return (print_error("fork", USE_ERRNO));
		if (!params.pids[i])
		{
			params.cmd = (t_cmd *)list->content;
			params.index = i;
			ft_exec(&params);
			exit(0);
		}
		if (close(params.pipes[i][1]) < 0)
			return (print_error("close", USE_ERRNO));
		if (close(params.pipes[i][0]))
			return (print_error("close", USE_ERRNO));
		list = list->next;
		i++;
	}
	if (close(params.pipes[i][1]))
		return (print_error("close", USE_ERRNO));
	if (close(params.pipes[i][0]))
		return (print_error("close", USE_ERRNO));
	wait_for_processes(params.cmds_list_size);
	return (0);
}

int wait_for_processes(int size)
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

void init_params(t_params *params, char **env, int list_size)
{
	params->pipes = init_pipes(list_size + 1);
	params->pids = malloc(sizeof(int) * (list_size));
	params->cmds_list_size = list_size;
	params->env = env;
}
