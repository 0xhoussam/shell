/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <habouiba@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:31:07 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/13 10:50:24 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

size_t parse_pipe(t_list **cmds, t_cmd **cmd, const char *s) {
  if (*s != '|')
    return (0);
  if (*cmd) {
    (*cmd)->right_priority = PIPE;
    ft_lstadd_back(cmds, ft_lstnew(cmd));
    *cmd = NULL;
    return (1);
  } else {
    *cmd = malloc(sizeof(t_cmd));
    init_cmd(*cmd);
    (*cmd)->left_priority = PIPE;
    return (1);
  }
}
