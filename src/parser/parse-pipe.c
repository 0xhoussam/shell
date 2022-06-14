/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:31:07 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/14 06:43:13 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

size_t parse_pipe(t_list **cmds, t_cmd **cmd, const char *s) {
  if (*s != '|')
    return (0);
  if (s[1] == '|')
    return (0);
  if (*cmd) {
    (*cmd)->right_delimiter = PIPE;
    ft_lstadd_back(cmds, ft_lstnew(*cmd));
    return (1);
  } else {
    *cmd = malloc(sizeof(t_cmd));
    init_cmd(*cmd);
    (*cmd)->left_delimiter = PIPE;
    return (1);
  }
}
