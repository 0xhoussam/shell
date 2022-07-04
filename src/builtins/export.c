/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:50:05 by aoumouss          #+#    #+#             */
/*   Updated: 2022/07/04 14:26:13 by aoumouss         ###   ########.fr       */
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
	{
		print_env_list(params->env, fd);
		g_exit_code = 0;
		return ;
	}
	env_list_insert(&params->env, cmd->args->next);
	if (g_exit_code == -1)
		g_exit_code = 1;
	else
		g_exit_code = 0;
}

static void	print_env_list(t_env_list *env, int fd)
{
	char		**env_strs;
	t_env_list	*env_list;
	t_env_list	*tmp;

	env_strs = env_list_to_array(env);
	sort_strs(env_strs);
	env_list = env_array_to_list(env_strs);
	free_2d_array(env_strs);
	tmp = env_list;
	while (tmp)
	{
		write(fd, "declare -x ", 11);
		write(fd, tmp->key, ft_strlen(tmp->key));
		write(fd, "=", 1);
		if (!tmp->value)
			write(fd, "", 0);
		else
			print_env_value(tmp->value, fd);
		write(fd, "\n", 1);
		tmp = tmp->next;
	}
	env_list_clean(&env_list);
}

static void	print_env_value(char *str, int fd)
{
	int	i;

	i = 0;
	write(fd, "\"", 1);
	while (str[i])
	{
		if (str[i] == '"')
			write(fd, "\\\"", 2);
		else
			ft_putchar_fd(str[i], fd);
		i++;
	}
	write(fd, "\"", 1);
}
