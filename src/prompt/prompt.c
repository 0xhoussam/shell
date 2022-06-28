/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:33:54 by marvin            #+#    #+#             */
/*   Updated: 2022/06/28 13:05:59 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	int_handler(int sig);

char *prompt(void)
{
	char	*line;

	signal(SIGINT, int_handler);
	signal(SIGQUIT, SIG_IGN);
	line = readline(PROMPT);
	if (!line)
		exit(0);
	add_history(line);
	return (line);
}

static void int_handler(int sig)
{
	if (sig == SIGINT)
	{
		kill(0, SIGQUIT);
		ft_putchar_fd('\n', 1);
		if (errno == EINTR)
		{
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
	}
}
