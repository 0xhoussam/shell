/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:50:05 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/26 14:26:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_env_list(t_env_list *list, int fd);

void	export(t_params *params)
{
	t_cmd		*cmd;
	int			fd;

	cmd = params->cmd;
	fd = get_redir_fd(params);
	if (cmd->right_delimiter == PIPE)
		fd = params->pipes[params->index + 1][1];
	if (ft_lstsize(cmd->args) <= 1)
		return (print_env_list(params->env, fd));
	env_list_insert(&params->env, cmd->args->next);
	g_exit_code = 0;
}

static void	print_env_list(t_env_list *env, int fd)
{
	while (env)
	{
		write(fd, "declare -x ", 11);
		write(fd, env->key, ft_strlen(env->key));
		write(fd, "=", 1);
		if (!env->value)
			write(fd, "", 0);
		else
		{
			write(fd, "\"", 1);
			write(fd, env->value, ft_strlen(env->value));
			write(fd, "\"", 1);
		}
		write(fd, "\n", 1);
		env = env->next;
	}
}
