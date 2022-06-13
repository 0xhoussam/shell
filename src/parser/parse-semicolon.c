/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-semicolon.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:55:31 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/13 12:35:59 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

size_t parse_semicolon(t_list **cmds, t_cmd **cmd, const char *s) {
  if (ft_strlen(s) > 1)
    return 0;
  if (s[0] != ';')
    return (0);
  if (cmd) {
    (*cmd)->right_delimiter = SEMICOLON;
    ft_lstadd_back(cmds, ft_lstnew(*cmd));
  } else {
    *cmd = malloc(sizeof(t_cmd));
    init_cmd(*cmd);
    (*cmd)->left_delimiter = SEMICOLON;
  }
  return (1);
}
