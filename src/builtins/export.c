/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:50:05 by aoumouss          #+#    #+#             */
/*   Updated: 2022/07/02 16:27:09 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_env_value(char *str, int fd);
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
	if (g_exit_code == -1)
		g_exit_code = 1;
	else
		g_exit_code = 0;
}

static void	print_env_list(t_env_list *env, int fd)
{
	int	i;

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
			print_env_value(env->value, fd);
			write(fd, "\"", 1);
		}
		write(fd, "\n", 1);
		env = env->next;
	}
	g_exit_code = 0;
}

static void	print_env_value(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '"')
			write(fd, "\\\"", 2);
		else
			ft_putchar_fd(str[i], fd);
		i++;
	}
}
