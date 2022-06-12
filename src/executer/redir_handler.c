/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:04:05 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/11 18:17:00 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

# define OUT_TRUNC O_CREAT | O_WRONLY | O_TRUNC
# define OUT_APPEND O_CREAT | O_WRONLY | O_APPEND

static int	dup_std(int std, int mode, char *file);
static int	heredoc_handler(t_params *params);
static int	pipe_handler(t_params *params);

int	redir_handler(t_params *params)
{
	t_cmd	*cmd;

	cmd = params->cmd;
	if (cmd->in_redir == SINGLE)
		dup_std(cmd->in, STDIN_FILENO , O_RDONLY);
	else if (cmd->in_redir == DOUBLE)
		dup_std(cmd->in, STDIN_FILENO, O_RDONLY);
	else if (cmd->out_redir == SINGLE)
		dup_std(cmd->out, STDOUT_FILENO, OUT_TRUNC);
	else if (cmd->out_redir == DOUBLE)
		dup_std(cmd->out, STDOUT_FILENO, OUT_APPEND);
	else if (cmd->in_redir == HEREDOC)
	{
		heredoc_handler(cmd);
		pipe_handler(params);
	}
	else
		pipe_handler(params);
	return (0);
}

static int	dup_std(int std, int mode, char *file)
{
	int fd;

	fd = open(file, mode, 0644);
	if (fd < 0)
		return (print_error(file, USE_ERRNO));
	if (dup2(fd, std) < 0)
		return (print_error(file, USE_ERRNO));
	return (0);
}

static int heredoc_handler(t_params *params)
{
	char	*line;
	t_cmd	*cmd;

	cmd = params->cmd;
	while (1)
	{
		ft_putstr("> ", 1);
		line = get_next_line(0);
		line[ft_strlen(line) - 1] = '\0';
		if (!ft_strcmp(cmd->heredoc_deli, line))
		{
			free(line);
			break ;
		}
		write(params->pipes[params->index][1], line, ft_strlen(line));
		write(params->pipes[params->index][1], "\n", 1);
		free(line);
	}
	return (0);
}

static int pipe_handler(t_params *params)
{
	t_cmd	*cmd;
	int		i;

	cmd = params->cmd;
	if (cmd->left_delimiter == PIPE)
	{
		if (dup2(params->pipes[params->index][0], STDIN_FILENO) < 0)
			return (print_error(cmd->cmd_name, USE_ERRNO));
	}
	if (cmd->right_delimiter == PIPE)
	{
		if (dup2(params->pipes[params->index + 1][1], STDOUT_FILENO) < 0)
			return (print_error(cmd->cmd_name, USE_ERRNO));
	}
	close(params->pipes[params->index][1]);
	close(params->pipes[params->index + 1][0]);
}