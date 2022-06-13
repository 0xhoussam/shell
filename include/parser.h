/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:14:08 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/13 11:32:12 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H

#include "builtins.h"
#include "libft.h"
#include <stdio.h>

// int prev_exit_code;

typedef enum e_redir_type { NIL, SINGLE, DOUBLE, HEREDOC } t_redir_type;

typedef enum e_delimiter { NONE, AND, OR, SEMICOLON, PIPE } t_delimiter;

typedef struct s_cmd {
  const char *cmd_name;
  t_list *args;           // default NULL
  char *in;               // default NULL
  char *out;              // default NULL
  char *heredoc_del;      // default NULL
  t_redir_type in_redir;  // default
  t_redir_type out_redir; // default
  t_delimiter left_priority;
  t_delimiter right_priority;
} t_cmd;

t_list *parser(char *line);
char *expande_string(char *s, t_env_list *env);
size_t get_cmd_name(t_cmd *cmd, char const *s);
size_t get_input_redir(t_cmd *cmd, const char *s);
size_t get_output_redir(t_cmd *cmd, const char *s);
size_t get_args(t_cmd *cmd, const char *s);
size_t parse_semicolon(t_cmd *cmd, const char *s);
size_t parse_pipe(t_list **cmds, t_cmd **cmd, const char *s);
void init_cmd(t_cmd *cmd);
#endif
