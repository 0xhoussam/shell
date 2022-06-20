/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:34:33 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/18 09:03:21 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void init_cmd(t_cmd *cmd) {
  if (!cmd)
    return;
  cmd->cmd_name = NULL;
  cmd->args = NULL;
  cmd->heredoc_del = NULL;
  cmd->in = NULL;
  cmd->out = NULL;
  cmd->in_redir = NIL;
  cmd->out_redir = NIL;
  cmd->left_delimiter = NONE;
  cmd->right_delimiter = NONE;
}

void recursive_parser(t_list **cmds, t_cmd *cmd, char *s, t_env_list *lst) {
  size_t i;

  if (!s)
    return;
  while (ft_isspace(*s))
    s++;
  if (!*s) {
    if (cmd) {
      ft_lstadd_back(cmds, ft_lstnew(cmd));
    }
    return;
  }
  if (!cmd) {
    cmd = malloc(sizeof(t_cmd));
    init_cmd(cmd);
  }
  i = get_cmd_name(cmd, s, lst);
  if (i > 0)
    return recursive_parser(cmds, cmd, &s[i], lst);
  i = get_input_redir(cmd, s);
  if (i > 0) {
    return recursive_parser(cmds, cmd, &s[i], lst);
  }
  i = get_output_redir(cmd, s);
  if (i > 0) {
    return recursive_parser(cmds, cmd, &s[i], lst);
  }
  i = get_args(cmd, s);
  if (i > 0) {
    return recursive_parser(cmds, cmd, &s[i], lst);
  }
	i = expand_asterisk(cmd, s);
	if (i > 0)
		return recursive_parser(cmds, cmd ,&s[i], lst);
  /*------------------------------------------------*/
	i = parse_pipe(cmds, &cmd, s);
  if (i > 0) {
    cmd = NULL;
    parse_pipe(cmds, &cmd, s);
    return recursive_parser(cmds, cmd, &s[1], lst);
  }
  i = parse_semicolon(cmds, &cmd, s);
  if (i > 0) {
    cmd = NULL;
    parse_semicolon(cmds, &cmd, s);
    return recursive_parser(cmds, cmd, &s[1], lst);
  }
  i = parse_and(cmds, &cmd, s);
  if (i > 0) {
    cmd = NULL;
    parse_and(cmds, &cmd, s);
    return recursive_parser(cmds, cmd, &s[2], lst);
  }
  i = parse_or(cmds, &cmd, s);
  if (i > 0) {
    cmd = NULL;
    parse_or(cmds, &cmd, s);
    return recursive_parser(cmds, cmd, &s[2], lst);
  }
}

t_list *parser(char *line, t_env_list *lst) {
  t_list *cmds;

  cmds = NULL;
  recursive_parser(&cmds, NULL, line, lst);
  return (cmds);
}
