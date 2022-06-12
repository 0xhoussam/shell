/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:02:11 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/12 19:02:24 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
#define EXECUTER_H

#include <fcntl.h>

#include "parser.h"

// ERRORS
#define CMD_NOT_FOUND "command not found"
#define CMD_NOT_FOUND_ERRNO 127
#define EXECVE_FIALED "execve failed"
#define EXECVE_FIALED_ERRNO 126
#define PIPE_ERROR "pipe error"
#define USE_ERRNO ""

extern int	g_exit_code = 0;

struct s_params
{
	t_cmd	*cmd;
	char	**env;
	int		*pipes;
	int		*pids;
	int		index;
};

typedef struct s_params t_params;

int		ft_exec(t_params *params);
char	*get_cmd_path(t_params *params);
char	*get_env_path(char *env[]);
int		redir_handler(t_params *params);
int		print_error(char *cmd, char *error);

#endif