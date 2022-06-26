/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:14:08 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/26 09:23:51 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H

#include "types.h"
#include <dirent.h>
#include <stdio.h>

// int prev_exit_code;

t_list *parser(char *line, t_env_list *lst);
void    recursive_parser(t_list **cmds, t_cmd *cmd, char *s, t_env_list *lst);
int     get_cmd_name(t_list **cmds, t_cmd *cmd, char *s, t_env_list *lst);
int     get_input_redir(t_list **cmds, t_cmd *cmd, char *s, t_env_list *env);
int     get_output_redir(t_list **cmds, t_cmd *cmd, char *s, t_env_list *env);
int     get_args(t_list **cmds, t_cmd *cmd, char *s, t_env_list *lst);
int     expand_asterisk(t_list **cmds, t_cmd *cmd, char *s, t_env_list *lst);
size_t  parse_pipe(t_list **cmds, t_cmd **cmd, const char *s);
void    init_cmd(t_cmd *cmd);
size_t  parse_semicolon(t_list **cmds, t_cmd **cmd, const char *s);
size_t  parse_and(t_list **cmds, t_cmd **cmd, const char *s);
size_t  parse_or(t_list **cmds, t_cmd **cmd, const char *s);
int     is_inside_single_quotes(char *s, size_t idx);
void    expand(char **str, t_env_list *env);
char   *_expand(const char *s, t_env_list *env);
void    evaluate_str_and_var(t_list *cmds, t_env_list *env);
char   *remove_last_and_first(char *s);
void    remove_single_quotes(char **s);
void    remove_double_quotes(char **s, t_env_list *env);
char   *extract_word(const char *s, size_t *k, int start);
void    delete_commands(t_list **cmds);
int     check_quotes(char *s);
int     check_pipe(char *s);
int     check_redirection(char *s);
void    log_error(const char *msg);
#endif
