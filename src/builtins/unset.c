/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:57:26 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/25 19:48:05 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset(t_params *params)
{
	t_env_list	*env;
	t_cmd		*cmd;
	t_list		*args;
	char		*key;

	cmd = params->cmd;
	if (ft_lstsize(cmd->args) <= 1)
		return ;
	args = cmd->args->next;
	env = params->env;
	while (args)
	{
		key = args->content;
		env_list_delete(&env, key);
		args = args->next;
	}
	g_exit_code = 0;
}
