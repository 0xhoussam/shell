/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:02:11 by aoumouss          #+#    #+#             */
/*   Updated: 2022/07/02 16:52:06 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

# include "types.h"

void		ft_exec(t_params *params);
char		*get_cmd_path(t_params *params);
int			heredocs_handler(t_list *commands, t_params *params);
void		redir_handler(t_params *params);
int			and_or_handler(t_params *params);
void		print_error(const char *cmd, char *error);
void		print_error_no_exit(const char *cmd, char *error);
void		print_export_error(char *key, char *arg);
int			**init_pipes(int size);
void		executer(t_params *params, t_list *cmds);
int			init_params(t_params *params, int list_size);
void		free_params(t_params *params);
void		close_pipe(int *pipe);
void		close_pipes(t_params *params);
void		free_pipes(int **pipes, int size);

// utils
char		**join_args(t_list *list);
int			wait_for_processes(int change_exit_code);

#endif
