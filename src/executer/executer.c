/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:49:53 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/13 00:04:42 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	close_pipes(int *pipe, int size);
int	wait_for_processes(int size);

int executer(t_list *list, char **env)
{
	t_params	params;
	int			i;
	int			lst_size;
	int			pid;

	lst_size = ft_lstsize(list);
	params.pipes = init_pipes(lst_size + 1);
	params.env = env;
	i = 0;
	while (i < lst_size)
	{
		pid = fork();
		if (pid < 0)
			return (print_error("fork", USE_ERRNO));
		if (!pid)
		{
			params.cmd = (t_cmd *)list->content;
			params.index = i;
			ft_exec(&params);
			exit(g_exit_code);
		}
		list = list->next;
		i++;
	}
	close_pipes(params.pipes, lst_size + 1);
	wait_for_processes(lst_size);
	return (0);
}

int	close_pipes(int *pipe, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (close(pipe[i]) < 0)
			return (print_error("close pipe", USE_ERRNO));
		i++;
	}
	free(pipe);
	return (0);
}

int	wait_for_processes(int size)
{
	int i;
	int status;

	i = 0;
	while (i < size)
	{
		wait(&status);
		i++;
	}
	return (0);
}
