/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:45:04 by aoumouss          #+#    #+#             */
/*   Updated: 2022/07/02 14:57:45 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

# define PROGRAM_NAME "minishell"
# define BUILTINS "echo cd pwd export unset env exit"

// ERRORS
# define CMD_NOT_FOUND "command not found"
# define CMD_NOT_FOUND_ERRNO 127
# define PERMISSION_DENIED_ERRNO 126
# define EXECVE_FAILED "execve failed"
# define EXECVE_FAILED_ERRNO 3
# define PIPE_ERROR "pipe error"
# define USE_ERRNO ""

// PROMPT
#define PROMPT "minishell-1.0$ "

# define GET_CWD_ERROR "shell-init: error retrieving current directory: \
getcwd: cannot access parent directories"

#endif
