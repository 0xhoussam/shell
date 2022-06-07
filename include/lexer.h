/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:25:10 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/03 18:53:31 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef LEXER_H
# define LEXER_H

#include "libft.h"

int prev_exit_code;

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
  t_list      *args;
  const char  *in;
  const char  *out;
  const char  *deli;
  t_redir_type redir;
  t_priority  priority;
} t_cmd;
#endif
