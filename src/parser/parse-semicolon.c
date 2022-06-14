/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-semicolon.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:55:31 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/14 17:59:38 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t parse_semicolon(t_list **cmds, t_cmd **cmd, const char *s) {
  if (*s != ';')
    return (0);
  if (*cmd) {
    (*cmd)->right_delimiter = SEMICOLON;
    ft_lstadd_back(cmds, ft_lstnew(*cmd));
    return (1);
  } else {
    *cmd = malloc(sizeof(t_cmd));
    init_cmd(*cmd);
    (*cmd)->left_delimiter = SEMICOLON;
    return (1);
  }
}
