/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-semicolon.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:55:31 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/12 21:09:47 by aoumouss         ###   ########.fr       */
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
  cmd->right_delimiter = SEMICOLON;
  return (1);
}
