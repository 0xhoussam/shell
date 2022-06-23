/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:02:11 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/23 18:29:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
#define EXECUTER_H

#include "types.h"

int		ft_exec(t_params *params);
char	*get_cmd_path(t_params *params);
void	heredocs_handler(t_list *list, t_params *params);
void	redir_handler(t_params *params);
void	print_error(const char *cmd, char *error);
void	print_error_no_exit(const char *cmd, char *error);
int		**init_pipes(int size);
char	**executer(t_list *list, char **env);

// utils
void	close_pipe(int *pipe);
char	**join_args(t_list *list);
int 	wait_for_processes(int change_exit_code);
void	close_pipes(t_params *params);
#endif