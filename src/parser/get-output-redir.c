/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get-output-redir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <habouiba@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 07:50:39 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/11 15:53:19 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.c"

size_t get_output_dir(t_cmd *cmd, const char *s)
{
  size_t s_len;
  size_t i;
  size_t j;
  size_t k;

  s_len = ft_strlen(s);
  if (s_len < 2)
    return (0);
  if (s[0] != '<')
    return (0);
  if (s[1] == '<')
  {
    cmd->out_redir = HEREDOC;
    k = 2;
    while (ft_isspace(s[k]))
      k++;
    i = k;
    while (!ft_isspace(s[i]))
      i++;
    cmd->heredoc_del = ft_substr(s, k, i - k);
  }
  else
  {
    cmd->out_redir = SINGLE;
    i = 1;
  }
  while (ft_isspace(s[i]))
    i++;
  j = i;
  while (ft_isalpha(s[j]))
    j++;
  if (cmd->out)
    free(cmd->out);
  cmd->out = ft_substr(s, i, j);
  return (j);
}
