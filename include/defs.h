/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:45:04 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/17 11:08:30 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

# define PROGRAM_NAME "minishell"
# define BUILTINS "echo cd pwd export unset env exit"
# define ECHO_N_FLAG 0x01
# define MAX_BUF 100

// ERRORS
# define CMD_NOT_FOUND "command not found"
# define CMD_NOT_FOUND_ERRNO 127
# define EXECVE_FAILED "execve failed"
# define EXECVE_FAILED_ERRNO 3
# define PIPE_ERROR "pipe error"
# define USE_ERRNO ""

#endif