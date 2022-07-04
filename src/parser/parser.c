/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:34:33 by habouiba          #+#    #+#             */
/*   Updated: 2022/07/04 18:38:26 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "lexer.h"

void	init_cmd(t_cmd *cmd)
{
	if (!cmd)
		return ;
	ft_bzero(cmd, sizeof(t_cmd));
}

void	_recursive_parser(t_list **cmds, t_cmd **cmd, char *s, t_env_list *lst)
{
	if (get_cmd_name(cmds, *cmd, s, lst))
		return ;
	if (get_input_redir(cmds, *cmd, s, lst))
		return ;
	if (get_output_redir(cmds, *cmd, s, lst))
		return ;
	if (get_args(cmds, *cmd, s, lst))
		return ;
	if (parse_pipe(cmds, cmd, s, lst))
		return ;
	if (parse_and(cmds, cmd, s, lst))
		return ;
	if (parse_semicolon(cmds, cmd, s, lst))
		return ;
	if (parse_or(cmds, cmd, s, lst))
		return ;
}

void	recursive_parser(t_list **cmds, t_cmd *cmd, char *s, t_env_list *lst)
{
	if (!s)
		return ;
	while (*s && ft_isspace(*s))
		s++;
	if (!*s)
	{
		if (cmd)
			ft_lstadd_back(cmds, ft_lstnew(cmd));
		return ;
	}
	if (!cmd)
	{
		cmd = malloc(sizeof(t_cmd));
		init_cmd(cmd);
	}
	_recursive_parser(cmds, &cmd, s, lst);
}

t_list	*parser(char *line, t_env_list *lst)
{
	t_list	*cmds;
	t_list	*tokens;

	tokens = lexer(line);
	if (!tokens || !syntax_analysis(tokens))
	{
		ft_lstclear(&tokens, free_token);
		return (NULL);
	}
	ft_lstclear(&tokens, free_token);
	cmds = NULL;
	recursive_parser(&cmds, NULL, line, lst);
	expand_asterisk(cmds);
	evaluate_str_and_var(cmds, lst);
	return (cmds);
}
