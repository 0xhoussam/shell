/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:14:08 by habouiba          #+#    #+#             */
/*   Updated: 2022/07/03 17:01:23 by aoumouss         ###   ########.fr       */
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
size_t	parse_pipe(t_list **cmds, t_cmd **cmd, char *s, t_env_list *lst);
void	init_cmd(t_cmd *cmd);
size_t	parse_semicolon(t_list **cmds, t_cmd **cmd, char *s, t_env_list *env);
size_t	parse_and(t_list **cmds, t_cmd **cmd, char *s, t_env_list *env);
size_t	parse_or(t_list **cmds, t_cmd **cmd, char *s, t_env_list *env);
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
void	setup_matrix(char **matrix, char *pattern, char *filename, int *i);
void	remove_matrix(char **matrix, size_t height);
void	printc(t_list *cmds);
int		check_if_expandable(t_list *curr);
void	insert_at_front(t_list *expanded_arg, t_list *curr, t_cmd *cmd);
void	insert_at_any(t_list *prev, t_list *expanded_arg, t_list *curr);
void	_expand_asterisk_init(t_cmd **cmd, void **_cmd,
			t_list **curr, t_list **prev);
char	*expand_string(char *s, t_env_list *env);
char	*get_double_quotes(char *s, t_env_list *env);
void	add_appropriate_val(char *key, t_env_list *env, t_list **lst);
char	*get_single_quotes(char *s);
void	expand_if_single(char *s, t_list **splits, size_t *i);
void	expand_if_double(char *s, t_list **splits, size_t *i, t_env_list *env);
void	expand_if_dollar(char *s, t_list **splits, t_env_list *env, size_t *i);
char	*expand_ret(t_list **splits);
void	add_appropriate_val_v2(char *key, t_env_list *env, t_list **lst);
void	_add_appropriate_val(char *key, t_env_list *env, t_list **lst);

// syntax analysis
int		syntax_analysis(t_list *tokens);
int		syntax_error_logger(char *token);
int		is_binary_operator(t_token *token);
int		check_binary_operators(t_list *prev_node, t_list *node);
int		check_unary_operators(t_list *node);
int		check_parentheses_syntax(t_list *prev_n, t_list *node, t_analysis *an);
int		check_word_syntax(t_list *node, t_analysis *an);

#endif
