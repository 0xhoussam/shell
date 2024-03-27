/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 21:51:35 by aoumouss          #+#    #+#             */
/*   Updated: 2022/07/04 10:44:28 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <errno.h>

static void	signal_handler(int ret, int *printed);

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
	int	ret;
	int	printed;

	ret = 1;
	printed = 0;
	while (ret > 0)
	{	
		if (change_exit_code)
		{
			ret = waitpid(-1, &g_exit_code, 0);
			signal_handler(ret, &printed);
			if (errno != ECHILD && !WIFSIGNALED(g_exit_code))
				g_exit_code = WEXITSTATUS(g_exit_code);
		}
		else
			ret = waitpid(-1, NULL, 0);
	}
	return (0);
}

static void	signal_handler(int ret, int *printed)
{
	if (WIFSIGNALED(g_exit_code) && ret > 0)
	{
		if (128 + WTERMSIG(g_exit_code) == 131)
		{
			if (!*printed)
				ft_putstr_fd("Quit (core dumped) \n", STDOUT_FILENO);
			*printed = 1;
		}
		if (128 + WTERMSIG(g_exit_code) == 130)
		{
			if (!*printed)
				ft_putstr_fd("\n", STDOUT_FILENO);
			*printed = 1;
		}
		g_exit_code = 128 + WTERMSIG(g_exit_code);
	}
}
