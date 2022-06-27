/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:56:50 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/27 15:09:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	**init_pipes(int size)
{
	int	**pipes;
	int	i;

	pipes = malloc(sizeof(int *) * size);
	if (!pipes)
		return (NULL);
	i = 0;
	while (i < size)
	{
		pipes[i] = malloc(sizeof(int) * 2);
		if (pipe(pipes[i]) < 0)
		{
			print_error("pipe", USE_ERRNO);
			free(pipes);
			return (NULL);
		}
		i++;
	}
	return (pipes);
}

void	close_pipe(int *pipe)
{
	if (close(pipe[1]) < 0)
		print_error("close pipe", USE_ERRNO);
	if (close(pipe[0]))
		print_error("close pipe", USE_ERRNO);
}

void	close_pipes(t_params *params)
{
	int		i;
	int		**pipes;

	i = 0;
	pipes = params->pipes;
	while (i < params->cmds_list_size + 1)
	{
		close_pipe(pipes[i]);
		i++;
	}
}

void	free_pipes(int **pipes, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(pipes[i]);
		i++;
	}
	free(pipes);
}
