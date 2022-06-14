/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:34:33 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/14 07:25:29 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "utils.h"

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

void recursive_parser(t_list **cmds, t_cmd *cmd, char *s) {
  size_t i;

  if (!s)
    return;
  if (!*s) {
    if (cmd) {
      ft_lstadd_back(cmds, ft_lstnew(cmd));
    }
    return;
  }
  while (ft_isspace(*s))
    s++;
  if (!cmd) {
    cmd = malloc(sizeof(t_cmd));
    init_cmd(cmd);
  }
  i = get_cmd_name(cmd, s);
  if (i > 0)
    return recursive_parser(cmds, cmd, &s[i]);
  i = get_input_redir(cmd, s);
  if (i > 0) {
    return recursive_parser(cmds, cmd, &s[i]);
  }
  i = get_output_redir(cmd, s);
  if (i > 0) {
    return recursive_parser(cmds, cmd, &s[i]);
  }
  i = get_args(cmd, s);
  if (i > 0) {
    return recursive_parser(cmds, cmd, &s[i]);
  }
  /*------------------------------------------------*/
  i = parse_pipe(cmds, &cmd, s);
  if (i > 0) {
    cmd = NULL;
    parse_pipe(cmds, &cmd, s);
    recursive_parser(cmds, cmd, &s[1]);
  }
  i = parse_semicolon(cmds, &cmd, s);
  if (i > 0) {
    cmd = NULL;
    parse_semicolon(cmds, &cmd, s);
    recursive_parser(cmds, cmd, &s[1]);
  }
  i = parse_and(cmds, &cmd, s);
  if (i > 0) {
    cmd = NULL;
    parse_and(cmds, &cmd, s);
    recursive_parser(cmds, cmd, &s[2]);
  }
  i = parse_or(cmds, &cmd, s);
  if (i > 0) {
    cmd = NULL;
    parse_or(cmds, &cmd, s);
    recursive_parser(cmds, cmd, &s[2]);
  }
}

t_list *parser(char *line) {
  t_list *cmds;

  cmds = malloc(sizeof(t_list));
  cmds = NULL;
  recursive_parser(&cmds, NULL, line);
  return (cmds);
}
