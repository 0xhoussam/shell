/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:56:50 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/13 00:02:26 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int *init_pipes(int size)
{
	int *pipes;
	int i;

	if (size % 2)
		size += 1;
	pipes = ft_calloc(sizeof(int), size);
	i = 0;
	while (i < size)
	{
		if (pipe(pipes + i) < 0)
		{
			print_error("pipe", USE_ERRNO);
			free(pipes);
			return (NULL);
		}
		i += 2;
	}
	return (pipes);
}