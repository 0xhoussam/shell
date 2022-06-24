/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:18:44 by marvin            #+#    #+#             */
/*   Updated: 2022/06/24 19:13:03 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_redir_fd(t_params *params)
{
	t_cmd	*cmd;
	t_list	*args;
	int		fd;

	cmd = params->cmd;
	args = cmd->args->next;
	fd = STDOUT_FILENO;
	if (cmd->out_redir == SINGLE)
		fd = open(cmd->out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (cmd->out_redir == DOUBLE)
		fd = open(cmd->out, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (cmd->right_delimiter == PIPE)
		fd = params->pipes[params->index + 1][1];
	return (fd);
}
