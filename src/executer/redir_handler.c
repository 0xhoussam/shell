/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:04:05 by aoumouss          #+#    #+#             */
/*   Updated: 2022/07/02 22:32:08 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	dup_std(t_cmd *cmd, char *file, int std, int mode);
static void	pipe_handler(t_params *params);

void	redir_handler(t_params *params)
{
	t_cmd	*cmd;

	cmd = params->cmd;
	if (cmd->in_redir == SINGLE)
		dup_std(cmd, cmd->in, STDIN_FILENO, O_RDONLY);
	if (cmd->in_redir == DOUBLE)
		dup_std(cmd, cmd->in, STDIN_FILENO, O_RDONLY);
	if (cmd->out_redir == SINGLE)
		dup_std(cmd, cmd->out, STDOUT_FILENO, O_CREAT | O_WRONLY | O_TRUNC);
	if (cmd->out_redir == DOUBLE)
		dup_std(cmd, cmd->out, STDOUT_FILENO, O_CREAT | O_WRONLY | O_APPEND);
	pipe_handler(params);
}

static void	dup_std(t_cmd *cmd, char *file, int std, int mode)
{
	int	fd;

	fd = open(file, mode, 0644);
	if (fd < 0)
		print_error(file, USE_ERRNO);
	if (dup2(fd, std) < 0)
		print_error(file, USE_ERRNO);
	close(fd);
	if (std == STDIN_FILENO && cmd->left_delimiter == PIPE)
		cmd->left_delimiter = NONE;
	if (std == STDOUT_FILENO && cmd->right_delimiter == PIPE)
		cmd->right_delimiter = NONE;
	close(fd);
}

static void	pipe_handler(t_params *params)
{
	t_cmd	*cmd;
	int		**pipes;
	int		i;

	cmd = params->cmd;
	pipes = params->pipes;
	i = params->index;
	if (cmd->left_delimiter == PIPE || cmd->in_redir == HEREDOC)
	{
		if (dup2(pipes[i][0], STDIN_FILENO) < 0)
			print_error("dup2", USE_ERRNO);
	}
	if (cmd->right_delimiter == PIPE)
	{
		if (dup2(pipes[i + 1][1], STDOUT_FILENO) < 0)
			print_error("dup2", USE_ERRNO);
	}
	close_pipes(params);
}
