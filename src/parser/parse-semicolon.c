/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-semicolon.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:55:31 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/14 17:59:38 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

size_t	parse_semicolon(t_list **cmds, t_cmd **cmd, char *s, t_env_list *env)
{
	if (*s != ';')
		return (0);
	if (*cmd)
	{
		(*cmd)->right_delimiter = SEMICOLON;
		ft_lstadd_back(cmds, ft_lstnew(*cmd));
		*cmd = NULL;
		parse_semicolon(cmds, cmd, s, env);
		return (1);
	}
	*cmd = malloc(sizeof(t_cmd));
	init_cmd(*cmd);
	(*cmd)->left_delimiter = SEMICOLON;
	recursive_parser(cmds, *cmd, &s[1], env);
	return (1);
}
