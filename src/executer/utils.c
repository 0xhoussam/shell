/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 21:51:35 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/27 15:36:00 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**join_args(t_list *list)
{
	char	**args;
	int		i;
	int		list_size;

	if (!list)
		return (NULL);
	list_size = ft_lstsize(list);
	args = ft_calloc(sizeof(char *), list_size + 1);
	if (!args)
		return (NULL);
	i = 0;
	while (list)
	{
		args[i] = ft_strdup(list->content);
		list = list->next;
		i++;
	}
	args[i] = NULL;
	return (args);
}

int	wait_for_processes(int change_exit_code)
{
	int	i;
	int	ret;

	i = 0;
	ret = 1;
	while (ret > 0)
	{	
		if (change_exit_code)
		{
			ret = waitpid(-1, &g_exit_code, 0);
			if (errno != ECHILD)
				g_exit_code = WEXITSTATUS(g_exit_code);
		}
		else
			ret = waitpid(-1, NULL, 0);
		i++;
	}
	return (0);
}
