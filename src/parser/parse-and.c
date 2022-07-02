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

size_t	parse_and(t_list **cmds, t_cmd **cmd, const char *s)
{
	if (*s != '&')
		return (0);
	if (s[1] != '&')
		return (0);
	if (*cmd)
	{
		(*cmd)->right_delimiter = AND;
		ft_lstadd_back(cmds, ft_lstnew(*cmd));
		return (1);
	}
	else
	{
		*cmd = malloc(sizeof(t_cmd));
		init_cmd(*cmd);
		(*cmd)->left_delimiter = AND;
		return (1);
	}
}
