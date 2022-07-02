/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-or.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 06:50:35 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/14 17:59:27 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	parse_or(t_list **cmds, t_cmd **cmd, const char *s)
{
	if (*s != '|')
		return (0);
	if (s[1] != '|')
		return (0);
	if (*cmd)
	{
		(*cmd)->right_delimiter = OR;
		ft_lstadd_back(cmds, ft_lstnew(*cmd));
		return (1);
	}
	else
	{
		*cmd = malloc(sizeof(t_cmd));
		init_cmd(*cmd);
		(*cmd)->left_delimiter = OR;
		return (1);
	}
}
