/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 21:51:35 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/14 15:52:26 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void close_pipe(int *pipe)
{
	if (close(pipe[1]) < 0)
		print_error("close pipe", USE_ERRNO);
	if (close(pipe[0]))
		print_error("close pipe", USE_ERRNO);
}

char **join_args(t_cmd *cmd)
{
	t_list *list;
	char **args;
	int list_size;
	int i;

	list = cmd->args;
	if (!list)
		return (NULL);
	list_size = ft_lstsize(list);
	args = ft_calloc(sizeof(char *), list_size + 1);
	if (!args)
		return (NULL);
	i = 0;
	while (list)
	{
		args[i] = (char *)list->content;
		list = list->next;
		i++;
	}
	args[i] = NULL;
	return (args);
}