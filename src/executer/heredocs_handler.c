/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:52:05 by marvin            #+#    #+#             */
/*   Updated: 2022/07/02 16:47:50 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"
#include "minishell.h"
#include "types.h"
#include "utils.h"

static void	heredoc_handler(t_params *params);
static void	heredocs(t_list *cmds, t_params *params);
static int	signal_handler(int sig);
static int	is_heredoc(t_list *cmds);

int	heredocs_handler(t_list *commands, t_params *params)
{
	int	i;
	int	pid;

	if (!is_heredoc(commands))
		return (1);
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_IGN);
		heredocs(commands, params);
		close_pipes(params);
		exit (0);
	}
	else
	{
		i = signal_handler(pid);
		if (i == 0)
			free_params(params);
		return (i);
	}
}

static void	heredocs(t_list *cmds, t_params *params)
{
	int	i;

	i = 0;
	while (i < params->cmds_list_size)
	{
		params->cmd = (t_cmd *)cmds->content;
		params->index = i;
		heredoc_handler(params);
		cmds = cmds->next;
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
		while (1)
		{
			line = readline("> ");
			if (!line)
				break ;
			if (line && !ft_strcmp(args->content, line))
			{
				free(line);
				break ;
			}
			if (!args->next)
			{
				write(params->pipes[params->index][1], line, ft_strlen(line));
				write(params->pipes[params->index][1], "\n", 1);
			}
			free(line);
		}
		args = args->next;
	}
}

static int	is_heredoc(t_list *commands)
{
	t_cmd	*cmd;

	while (commands)
	{
		cmd = (t_cmd *)commands->content;
		if (cmd->in_redir == HEREDOC)
			return (1);
		commands = commands->next;
	}
	return (0);
}

static int	signal_handler(int pid)
{
	waitpid(pid, &g_exit_code, 0);
	if (WIFSIGNALED(g_exit_code))
	{
		if (128 + WTERMSIG(g_exit_code) == 130)
			ft_putstr_fd("\n", STDOUT_FILENO);
		g_exit_code = 128 + WTERMSIG(g_exit_code);
		return (0);
	}
	if (WEXITSTATUS(g_exit_code) != 0)
	{
		g_exit_code = WEXITSTATUS(g_exit_code);
		return (0);
	}
	return (1);
}
