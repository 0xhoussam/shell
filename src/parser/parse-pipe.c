/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:31:07 by habouiba          #+#    #+#             */
/*   Updated: 2022/07/03 17:07:09 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	parse_pipe(t_list **cmds, t_cmd **cmd, char *s, t_env_list *lst)
{
	if (*s != '|')
		return (0);
	if (s[1] == '|')
		return (0);
	if (*cmd)
	{
		(*cmd)->right_delimiter = PIPE;
		ft_lstadd_back(cmds, ft_lstnew(*cmd));
		*cmd = NULL;
		parse_pipe(cmds, cmd, s, lst);
		return (1);
	}
	*cmd = malloc(sizeof(t_cmd));
	init_cmd(*cmd);
	(*cmd)->left_delimiter = PIPE;
	recursive_parser(cmds, *cmd, &s[1], lst);
	return (1);
}
