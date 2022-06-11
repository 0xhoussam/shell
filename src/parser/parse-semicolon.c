/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-semicolon.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <habouiba@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:55:31 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/11 16:00:59 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

size_t parse_semicolon(t_cmd *cmd, const char *s)
{
  size_t i;

  if (ft_strlen(s) > 1)
    return 0;
  if (s[0] != ';')
    return (0);
  cmd->right_priority = SEMICOLON;
  return (1);
}
