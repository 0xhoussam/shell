/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get-input-redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 07:28:33 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/18 16:23:54 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_input_redir(t_list **cmds, t_cmd *cmd, char *s, t_env_list *env)
{
	size_t s_len;
	size_t i;
	size_t j;

	if (!cmd || !s || !*s)
		return (0);
	s_len = ft_strlen(s);
	if (s_len < 2)
		return (0);
	if (s[0] != '<')
		return (0);
	if (s[1] == '<')
	{
		cmd->in_redir = HEREDOC;
		i = 2;
	}
	else
	{
		cmd->in_redir = SINGLE;
		i = 1;
	}
	if (i == 2)
		ft_lstadd_back(&cmd->heredoc_del, ft_lstnew(extract_word(s, &j, i)));
	else
		cmd->in = extract_word(s, &j, i);
	recursive_parser(cmds, cmd, &s[j], env);
	return (1);
}
