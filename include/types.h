/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:38:54 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/18 16:17:53 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
#define TYPES_H

#include "libft.h"

typedef enum e_redir_type {
  NIL,
  SINGLE,
  DOUBLE,
  HEREDOC

} t_redir_type;

typedef enum e_delimiter {
  NONE,
  AND,
  OR,
  SEMICOLON,
  PIPE

} t_delimiter;

typedef struct s_cmd {
  char *cmd_name;
  t_list *args;           // default NULL
  char *in;               // default NULL
  char *out;              // default NULL
  t_list *heredoc_del;    // default NULL
  t_redir_type in_redir;  // default
  t_redir_type out_redir; // default
  t_delimiter left_delimiter;
  t_delimiter right_delimiter;

} t_cmd;

typedef struct s_params {
  t_cmd *cmd;
  char **env;
  int **pipes;
  int *pids;
  int cmds_list_size;
  int index;
} t_params;

typedef struct s_env_list {
  char *key;
  char *value;
  struct s_env_list *next;

} t_env_list;

#endif
