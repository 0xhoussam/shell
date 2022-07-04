/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete-commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 11:53:06 by habouiba          #+#    #+#             */
/*   Updated: 2022/07/04 18:39:10 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	delete_command(void *_cmd)
{
	t_cmd	*cmd;

	cmd = _cmd;
	if (!cmd)
		return ;
	if (cmd->cmd_name)
		free(cmd->cmd_name);
	ft_lstclear(&cmd->args, free);
	ft_lstclear(&cmd->heredoc_del, free);
	if (cmd->in)
		free(cmd->in);
	if (cmd->out)
		free(cmd->out);
	free(cmd);
}

void	delete_commands(t_list **cmds)
{
	ft_lstclear(cmds, delete_command);
	*cmds = NULL;
}
