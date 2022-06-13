/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:56:50 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/13 14:57:17 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int **init_pipes(int size)
{
	int **pipes;
	int i;

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