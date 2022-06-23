/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:50:05 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/23 15:53:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env_list(t_env_list *list, int std);

void	export(t_params *params)
{
	t_env_list	*list;
	t_cmd		*cmd;
	char		*key;
	char		*value;
	int			write_end;

	cmd = params->cmd;
	write_end = get_redir_fd(params);
	if (cmd->right_delimiter == PIPE)
		write_end = params->pipes[params->index + 1][1];
	list = env_array_to_list(params->env);
	if (ft_lstsize(cmd->args) <= 1)
		return (print_env_list(list, write_end));
	key = NULL;
	value = NULL;
	if (cmd->args->next)
		key = cmd->args->next->content;
	if (cmd->args->next && cmd->args->next->next)
		value = cmd->args->next->next->content;
	env_list_insert(&list, key, value);
	params->env = env_list_to_array(list);
}

void	print_env_list(t_env_list *list, int std)
{
	char	**env;
	int		i;

	env = env_list_to_array(list);
	sort_strs(env);
	i = 0;
	while (env[i])
	{
		write(std, env[i], ft_strlen(env[i]));
		write(std, "\n", 1);
		i++;
	}
}
