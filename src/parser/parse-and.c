/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-and.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 06:41:59 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/14 17:59:20 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	parse_and(t_list **cmds, t_cmd **cmd, char *s, t_env_list *env)
{
	if (*s != '&')
		return (0);
	if (s[1] != '&')
		return (0);
	if (*cmd)
	{
		(*cmd)->right_delimiter = AND;
		ft_lstadd_back(cmds, ft_lstnew(*cmd));
		*cmd = NULL;
		parse_and(cmds, cmd, s, env);
		return (1);
	}
	*cmd = malloc(sizeof(t_cmd));
	init_cmd(*cmd);
	(*cmd)->left_delimiter = AND;
	recursive_parser(cmds, *cmd, &s[2], env);
	return (1);
}
