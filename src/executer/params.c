/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:16:37 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/27 15:04:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_params(t_params *params, int list_size)
{
	params->pipes = init_pipes(list_size + 1);
	params->pids = malloc(sizeof(int) * (list_size));
	params->cmds_list_size = list_size;
}

void	free_params(t_params *params)
{
	free_pipes(params->pipes, params->cmds_list_size + 1);
	free(params->pids);
}
