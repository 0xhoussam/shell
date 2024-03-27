/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:18:44 by marvin            #+#    #+#             */
/*   Updated: 2022/06/25 21:01:50 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include <fcntl.h>

int	get_redir_fd(t_params *params)
{
	t_cmd	*cmd;
	int		fd;

	cmd = params->cmd;
	fd = STDOUT_FILENO;
	if (cmd->out_redir == SINGLE)
		fd = open(cmd->out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (cmd->out_redir == DOUBLE)
		fd = open(cmd->out, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (cmd->right_delimiter == PIPE)
		fd = params->pipes[params->index + 1][1];
	return (fd);
}
