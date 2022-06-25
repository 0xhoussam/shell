/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:16:37 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/25 20:14:28 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_pipes(int **pipes, int size);
static char	**ft_strdup_tab(char **tab);

void	init_params(t_params *params, t_env_list *env, int list_size)
{
	params->pipes = init_pipes(list_size + 1);
	params->pids = malloc(sizeof(int) * (list_size));
	params->cmds_list_size = list_size;
	params->env = env;
}

void	free_params(t_params *params)
{
	free_pipes(params->pipes, params->cmds_list_size + 1);
	free(params->pids);
}

static void	free_pipes(int **pipes, int size)
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

static char	**ft_strdup_tab(char **tab)
{
	char	**tab_cpy;
	int		i;
	int		tab_size;

	tab_size = 0;
	while (tab[tab_size])
		tab_size++;
	tab_cpy = malloc(sizeof(char *) * (tab_size + 1));
	i = 0;
	while (tab[i])
	{
		tab_cpy[i] = ft_strdup(tab[i]);
		i++;
	}
	tab_cpy[i] = NULL;
	return (tab_cpy);
}
