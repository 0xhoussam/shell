/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:01:21 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/25 16:22:54 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_env_variables(char **env, int std);

void	env(t_params *params)
{
	int	fd;

	fd = get_redir_fd(params);
	if (params->cmd->right_delimiter == PIPE)
		fd = params->pipes[params->index + 1][1];
	print_env_variables(params->env, fd);
	g_exit_code = 0;
}

static void	print_env_variables(char **env, int std)
{
	int		i;

	i = 0;
	while (env[i])
	{
		write(std, env[i], ft_strlen(env[i]));
		write(std, "\n", 1);
		i++;
	}
}
