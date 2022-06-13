/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:00:49 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/12 22:35:02 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "builtins.h"
# include "utils.h"
# include "libft.h"
# include "parser.h"
# include "executer.h"

int	g_exit_code;


# define PROGRAM_NAME "minishell"
#endif // MINISHELL_H
