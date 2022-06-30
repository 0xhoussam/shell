/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:14:08 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/30 18:53:38 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "types.h"
# include <dirent.h>
# include <stdio.h>

// int prev_exit_code;

t_list	*parser(char *line, t_env_list *lst);
void	recursive_parser(t_list **cmds, t_cmd *cmd, char *s, t_env_list *lst);
int		get_cmd_name(t_list **cmds, t_cmd *cmd, char *s, t_env_list *lst);
int		get_input_redir(t_list **cmds, t_cmd *cmd, char *s, t_env_list *env);
int		get_output_redir(t_list **cmds, t_cmd *cmd, char *s, t_env_list *env);
int		get_args(t_list **cmds, t_cmd *cmd, char *s, t_env_list *lst);
void	expand_asterisk(t_list *cmds, t_env_list *lst);
size_t	parse_pipe(t_list **cmds, t_cmd **cmd, const char *s);
void	init_cmd(t_cmd *cmd);
size_t	parse_semicolon(t_list **cmds, t_cmd **cmd, const char *s);
size_t	parse_and(t_list **cmds, t_cmd **cmd, const char *s);
size_t	parse_or(t_list **cmds, t_cmd **cmd, const char *s);
int		is_inside_single_quotes(char *s, size_t idx);
char	*expand(char *str, t_env_list *env);
char	*_expand(const char *s, t_env_list *env);
void	evaluate_str_and_var(t_list *cmds, t_env_list *env);
char	*remove_last_and_first(char *s);
void	remove_single_quotes(char **s);
void	remove_double_quotes(char **s, t_env_list *env);
char	*extract_word(const char *s, size_t *k, int start);
void	delete_commands(t_list **cmds);
int		is_matched(char *s_wildcard, char *filename);
char	*get_var_key(char *s);
char	*joined_linked_list_of_strings(t_list *lst);
char	*remove_consecutive_asterisks(char *pattern);
char	**create_matching_matrix(size_t pattern_len, size_t filename_len);
void	setup_matrix(char **matrix, char *pattern, char *filename);
void	remove_matrix(char **matrix, size_t height);
void	printc(t_list *cmds);

// syntax analysis
int		syntax_analysis(t_list *tokens);
int		syntax_error_logger(char *token);
int		is_binary_operator(t_token *token);

#endif
