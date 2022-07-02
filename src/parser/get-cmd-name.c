/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get-cmd-name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 07:08:42 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/20 11:57:07 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	get_cmd_name(t_list **cmds, t_cmd *cmd, char *s, t_env_list *lst)
{
	size_t	i;

	if (!cmd || cmd->cmd_name || !s || !*s || *s == '<' || *s == '>'
		|| *s == ';' || *s == '&' || *s == '|')
		return (0);
	i = 0;
	while (s[i] && !ft_isspace(s[i]))
		i++;
	cmd->cmd_name = extract_word(s, &i, 0);
	ft_lstadd_back(&cmd->args, ft_lstnew(ft_strdup(cmd->cmd_name)));
	recursive_parser(cmds, cmd, &s[i], lst);
	return (1);
}
