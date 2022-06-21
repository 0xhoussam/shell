/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:45:04 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/21 17:05:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

# define PROGRAM_NAME "minishell"
# define BUILTINS "echo cd pwd export unset env exit"

// getcwd path max length
# define MAX_BUF 100

// ERRORS
# define CMD_NOT_FOUND "command not found"
# define CMD_NOT_FOUND_ERRNO 127
# define PERMISSION_DENIED_ERRNO 126
# define EXECVE_FAILED "execve failed"
# define EXECVE_FAILED_ERRNO 3
# define PIPE_ERROR "pipe error"
# define USE_ERRNO ""

// PROMPT
#define PROMPT  BOLD BLUE "minishell-1.0$" RESET " "

// colors
# define RESET "\x1B[0m"
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define BLUE "\x1B[36m"
// typography
#define BOLD "\x1B[1m"

#endif