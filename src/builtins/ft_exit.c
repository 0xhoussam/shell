/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:02:15 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/21 13:01:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_number(char *str);

void	ft_exit(t_params *params)
{
	t_cmd	*cmd;
	char	*error;
	int		exit_code;

	cmd = params->cmd;
	exit_code = 0;
	if (ft_lstsize(cmd->args) > 2)
		return (print_error("exit", "too many arguments"));
	if (cmd->args->next)
	{
		if (!is_number(cmd->args->next->content))
		{
			error = ft_strjoin("exit: ", cmd->args->next->content);
			g_exit_code = 2;
			print_error(error, "numeric argument required");
		}
		exit_code = ft_atoi(cmd->args->next->content);
	}
	exit(exit_code);
}

int	is_number(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
