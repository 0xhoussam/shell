/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:13:49 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/11 18:25:56 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_exec(t_params *params)
{
	char *cmd;
	char **args;

	cmd = get_cmd_path(params->cmd->cmd_name);
	args = join_args(params->cmd);
	if (!cmd)
		return (print_error(params->cmd->cmd_name, CMD_NOT_FOUND));
	redir_handler(params);
	if (execve(cmd, args, params->env) < 0)
	{
		array_2d_free(args);
		free(cmd);
		free_params(params);
		return (print_error(params->cmd->cmd_name, EXECVE_FIALED));
	}
}

char	**join_args(t_cmd *cmd)
{
	t_list	*list;
	char	**args;
	int		list_size;
	int		i;

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
	}
	args[i] = NULL;
	return (args);
}