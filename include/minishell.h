/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:00:49 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/20 17:35:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <dirent.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>

# include "types.h"
# include "defs.h"

# include "libft.h"
# include "parser.h"
# include "executer.h"
# include "builtins.h"
# include "utils.h"
# include "readline/readline.h"


extern int	g_exit_code;

#endif // MINISHELL_H
