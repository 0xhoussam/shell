/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <habouiba@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:14:08 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/09 07:00:50 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef LEXER_H
# define LEXER_H

#include "libft.h"
#include <stdio.h>
#include "builtins.h"

// int prev_exit_code;

typedef enum e_redir_type {
  NIL,
  SINGLE,
  DOUBLE,
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
  char  *in; // default NULL
  char  *out; // default NULL
  char  *deli; // default NULL
  t_redir_type in_redir; // default 
  t_redir_type out_redir; // default 
  t_priority  priority;
} t_cmd;

t_list	*parser(const char *line);
char	*expande_string(char *s, t_env_list *env);
size_t	get_cmd_name(t_cmd *cmd, char const *s);
size_t	get_input_dir(t_cmd *cmd, const char *s);
size_t	get_output_dir(t_cmd *cmd, const char *s);
size_t	get_args(t_cmd *cmd, const char *s);
#endif