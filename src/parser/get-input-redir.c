/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get-input-redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 07:28:33 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/18 16:23:54 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t get_input_redir(t_cmd *cmd, const char *s) {
  size_t s_len;
  size_t i;
  size_t j;
  size_t k;

  if (!cmd || !s || !*s)
    return (0);
  s_len = ft_strlen(s);
  if (s_len < 2)
    return (0);
  if (s[0] != '<')
    return (0);
  if (s[1] == '<') {
    cmd->in_redir = HEREDOC;
    k = 2;
    while (ft_isspace(s[k]))
      k++;
    i = k;
    while (!ft_isspace(s[i]))
      i++;
    ft_lstadd_back(&cmd->heredoc_del, ft_lstnew(ft_substr(s, k, i - k)));
    return (i);
  } else {
    cmd->in_redir = SINGLE;
    i = 1;
  }
  while (ft_isspace(s[i]))
    i++;
  j = i;
  while (!ft_isspace(s[j]) && !is_spicial(s[j]))
    j++;
  if (cmd->in)
    free(cmd->in);
  cmd->in = ft_substr(s, i, j - i);
  return (j);
}
