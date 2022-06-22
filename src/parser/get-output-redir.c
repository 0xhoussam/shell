/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get-output-redir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 07:50:39 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/18 09:53:05 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	get_output_redir(t_list **cmds, t_cmd *cmd, char *s, t_env_list *env)
{
	size_t	s_len;
	size_t	i;
	size_t	j;

	if (!cmd || !s || !*s)
		return (0);
	s_len = ft_strlen(s);
	if (s_len < 2)
		return (0);
	if (s[0] != '>')
		return (0);
	if (s[1] == '>')
	{
		cmd->out_redir = DOUBLE;
		i = 2;
	}
	else
	{
		cmd->out_redir = SINGLE;
		i = 1;
	}
	cmd->out = extract_word(s, &j, 1);
	recursive_parser(cmds, cmd, &s[j], env);
	return (1);
}
