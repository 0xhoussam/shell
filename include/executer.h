/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:02:11 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/13 21:52:40 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
#define EXECUTER_H

#include <fcntl.h>

#include "parser.h"
#include "../utils/get_next_line/get_next_line.h"

// ERRORS
#define CMD_NOT_FOUND "command not found"
#define CMD_NOT_FOUND_ERRNO -1
#define EXECVE_FIALED "execve failed"
#define EXECVE_FIALED_ERRNO 3
#define PIPE_ERROR "pipe error"
#define USE_ERRNO ""

struct s_params
{
	t_cmd *cmd;
	char **env;
	int **pipes;
	int *pids;
	int cmds_list_size;
	int index;
};

typedef struct s_params t_params;

int ft_exec(t_params *params);
char *get_cmd_path(t_params *params);
char *get_env_path(char *env[]);
int redir_handler(t_params *params);
int print_error(const char *cmd, char *error);
int **init_pipes(int size);
int executer(t_list *list, char **env);

// utils
void close_pipe(int *pipe);

#endif