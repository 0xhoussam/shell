/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:01:21 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/23 15:53:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_env_variables(char **env, int std);

void	env(t_params *params)
{
	int	write_end;

	write_end = get_redir_fd(params);
	if (params->cmd->right_delimiter == PIPE)
		write_end = params->pipes[params->index + 1][1];
	g_exit_code = 0;
	print_env_variables(params->env, write_end);
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