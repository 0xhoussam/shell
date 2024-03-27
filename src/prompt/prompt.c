/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:33:54 by marvin            #+#    #+#             */
/*   Updated: 2022/06/30 18:05:22 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "libft.h"
#include "minishell.h"
#include <stdlib.h>
#include <errno.h>

static void	int_handler(int sig);
static int	is_spaces(char *line);

char	*prompt(void)
{
	char	*line;

	signal(SIGINT, int_handler);
	signal(SIGQUIT, SIG_IGN);
	line = readline(PROMPT);
	if (!line)
		exit(g_exit_code);
	if (!is_spaces(line))
		add_history(line);
	return (line);
}

static void	int_handler(int sig)
{
	if (sig == SIGINT)
	{
		kill(0, SIGQUIT);
		if (errno == EINTR)
		{
			ft_putchar_fd('\n', STDOUT_FILENO);
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
		g_exit_code = 130;
	}
}

static int	is_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (0);
		i++;
	}
	return (1);
}
