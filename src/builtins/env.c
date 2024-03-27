/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:01:21 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/25 19:46:34 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"

static void	print_env_variables(t_env_list *env, int fd);

void	env(t_params *params)
{
	int	fd;

	fd = get_redir_fd(params);
	if (params->cmd->right_delimiter == PIPE)
		fd = params->pipes[params->index + 1][1];
	print_env_variables(params->env, fd);
	g_exit_code = 0;
}

static void	print_env_variables(t_env_list *env, int fd)
{
	while (env)
	{
		if (env->value)
		{
			write(fd, env->key, ft_strlen(env->key));
			write(fd, "=", 1);
			write(fd, env->value, ft_strlen(env->value));
			write(fd, "\n", 1);
		}
		env = env->next;
	}
}
