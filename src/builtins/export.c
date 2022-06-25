/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:50:05 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/25 21:02:12 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_env_list(t_env_list *list, int fd);

void	export(t_params *params)
{
	t_cmd		*cmd;
	char		**key_value;
	int			fd;

	cmd = params->cmd;
	fd = get_redir_fd(params);
	if (cmd->right_delimiter == PIPE)
		fd = params->pipes[params->index + 1][1];
	if (ft_lstsize(cmd->args) <= 1)
		return (print_env_list(params->env, fd));
	key_value = ft_split(cmd->args->next->content, '=');
	env_list_insert(&params->env, key_value[0], key_value[1]);
	free(key_value);
	g_exit_code = 0;
}

static void	print_env_list(t_env_list *env, int fd)
{
	// sort list first
	while (env)
	{
		write(fd, env->key, ft_strlen(env->key));
		write(fd, "=", 1);
		if (!env->value)
			write(fd, "", 0);
		else
			write(fd, env->value, ft_strlen(env->value));
		write(fd, "\n", 1);
		env = env->next;
	}
}
