/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get-input-redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <habouiba@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 07:28:33 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/11 18:17:20 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

size_t get_input_redir(t_cmd *cmd, const char *s) {
  size_t s_len;
  size_t i;
  size_t j;

  s_len = ft_strlen(s);
  if (s_len < 2)
    return (0);
  if (s[0] != '<')
    return (0);
  if (s[1] == '<') {
    cmd->in_redir = DOUBLE;
    i = 2;
  } else {
    cmd->in_redir = SINGLE;
    i = 1;
  }
  while (ft_isspace(s[i]))
    i++;
  j = i;
  while (ft_isalpha(s[j]))
    j++;
  if (cmd->in)
    free(cmd->in);
  printf("%s", &s[j]);
  cmd->in = ft_substr(s, i, j - i);
  return (j);
}
