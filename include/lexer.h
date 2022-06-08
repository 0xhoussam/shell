/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <habouiba@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:14:08 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/07 12:14:11 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef LEXER_H
# define LEXER_H

#include "libft.h"
#include <stdio.h>

// int prev_exit_code;

typedef enum e_redir_type {
  DOUBLE,
  SINGLE,
  HEREDOC
} t_redir_type;

typedef enum e_priority {
  NONE,
  AND,
  OR
} t_priority;

typedef struct s_cmd {
  const char  *cmd_name;
  t_list      *args; // default NULL
  const char  *in; // default NULL
  const char  *out; // default NULL
  const char  *deli; // default NULL
  t_redir_type redir; // default 
  t_priority  priority;
} t_cmd;

t_list	*parser(const char *line);
#endif
