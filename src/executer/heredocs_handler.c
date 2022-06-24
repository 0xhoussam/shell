/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:52:05 by marvin            #+#    #+#             */
/*   Updated: 2022/06/24 19:12:36 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	heredoc_handler(t_params *params);

void	heredocs_handler(t_list *list, t_params *params)
{
	int	i;

	i = 0;
	while (i < params->cmds_list_size)
	{
		params->cmd = (t_cmd *)list->content;
		params->index = i;
		heredoc_handler(params);
		list = list->next;
		i++;
	}
}

static void	heredoc_handler(t_params *params)
{
	char	*line;
	t_list	*args;

	args = params->cmd->heredoc_del;
	while (args)
	{
		close_pipe(params->pipes[params->index]);
		pipe(params->pipes[params->index]);
		while (1)
		{
			line = readline("> ");
			if (line && !ft_strcmp(args->content, line))
			{
				free(line);
				break ;
			}
			if (line)
				write(params->pipes[params->index][1], line, ft_strlen(line));
			free(line);
		}
		args = args->next;
	}
}
