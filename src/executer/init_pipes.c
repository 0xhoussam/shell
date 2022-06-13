/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:56:50 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/12 18:45:43 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int *init_pipes(int size)
{
	int pipes;
	int i;

	pipes = ft_calloc(sizeof(int), size);
	i = 0;
	while (i < size)
	{
		if (pipe(pipes + i) < 0)
		{
			perror(PIPE_ERROR);
			free(pipes);
			return (NULL);
		}
		i += 2;
	}
	return (pipes);
}