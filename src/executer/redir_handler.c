/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:04:05 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/18 19:31:06 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	dup_std(t_cmd *cmd, char *file, int std, int mode);
static int	heredoc_handler(t_params *params);
static int	pipe_handler(t_params *params);
void		close_pipes(t_params *params);

int redir_handler(t_params *params)
{
	t_cmd *cmd;

	cmd = params->cmd;
	if (cmd->in_redir == HEREDOC)
		heredoc_handler(params);
	else if (cmd->in_redir == SINGLE)
		dup_std(cmd, cmd->in, STDIN_FILENO, O_RDONLY);
	else if (cmd->in_redir == DOUBLE)
		dup_std(cmd, cmd->in, STDIN_FILENO, O_RDONLY);
	else if (cmd->out_redir == SINGLE)
		dup_std(cmd, cmd->out, STDOUT_FILENO, O_CREAT | O_WRONLY | O_TRUNC);
	else if (cmd->out_redir == DOUBLE)
		dup_std(cmd, cmd->out, STDOUT_FILENO, O_CREAT | O_WRONLY | O_APPEND);
	pipe_handler(params);
	return (0);
}

static int dup_std(t_cmd *cmd, char *file, int std, int mode)
{
	int fd;

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
	return (0);
}

static int heredoc_handler(t_params *params)
{
	char *line;
	t_list *args;

	args = params->cmd->heredoc_del;
	while (args)
	{
		close_pipe(params->pipes[params->index]);
		pipe(params->pipes[params->index]);
		while (1)
		{
			ft_putstr_fd("> ", 1);
			line = get_next_line(STDIN_FILENO);
			line[ft_strlen(line) - 1] = '\0';
			if (!ft_strcmp(args->content, line))
			{
				free(line);
				break;
			}
			write(params->pipes[params->index][1], line, ft_strlen(line));
			write(params->pipes[params->index][1], "\n", 1);
			free(line);
		}
		args = args->next;
	}
	return (0);
}

static int pipe_handler(t_params *params)
{
	t_cmd *cmd;
	int **pipes;
	int i;

	cmd = params->cmd;
	pipes = params->pipes;
	i = params->index;
	if (cmd->left_delimiter == PIPE)
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
	return (0);
}

void close_pipes(t_params *params)
{
	int i;
	int **pipes;

	i = params->index;
	pipes = params->pipes;
	while (i < params->cmds_list_size + 1)
	{
		close_pipe(pipes[i]);
		i++;
	}
}
