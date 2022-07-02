/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:16:37 by aoumouss          #+#    #+#             */
/*   Updated: 2022/07/02 16:51:17 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_params(t_params *params, int list_size)
{
	if (!list_size)
		return (0);
	params->pipes = init_pipes(list_size + 1);
	params->pids = malloc(sizeof(int) * (list_size));
	params->cmds_list_size = list_size;
	return (1);
}

void	free_params(t_params *params)
{
	free_pipes(params->pipes, params->cmds_list_size + 1);
	free(params->pids);
}
