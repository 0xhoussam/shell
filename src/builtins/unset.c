/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:57:26 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/24 19:13:01 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset(t_params *params)
{
	t_env_list	*list;
	t_cmd		*cmd;
	t_list		*args;
	char		*key;

	cmd = params->cmd;
	if (ft_lstsize(cmd->args) <= 1)
		return ;
	args = cmd->args->next;
	list = env_array_to_list(params->env);
	while (args)
	{
		key = args->content;
		env_list_delete(&list, key);
		args = args->next;
	}
	params->env = env_list_to_array(list);
	g_exit_code = 0;
}
