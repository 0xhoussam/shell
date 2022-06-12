/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get-input-redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <habouiba@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 07:28:33 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/12 14:46:42 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
    cmd->heredoc_del = ft_substr(s, k, i - k);
    return (i);
  } else {
    cmd->in_redir = SINGLE;
    i = 1;
  }
  while (ft_isspace(s[i]))
    i++;
  j = i;
  while (!ft_isspace(s[j]))
    j++;
  if (cmd->in)
    free(cmd->in);
  cmd->in = ft_substr(s, i, j - i);
  return (j);
}

/*	TESTS		*/

void get_input_redir_test1() {
  t_cmd cmd;

  cmd.in = NULL;
  get_input_redir(NULL, NULL);
  get_input_redir(&cmd, NULL);
  get_input_redir(NULL, "< hello ls");
  size_t i = get_input_redir(&cmd, "< hello ls .");
  if (i == 7 && !ft_strncmp("hello\0", cmd.in, 5) && cmd.in_redir == SINGLE) {
    printf("TEST1: ok");
  } else
    printf("TEST1: failed");
  printf("\n");
}

void get_input_redir_test2() {
  t_cmd cmd;

  cmd.in = NULL;
  size_t i = get_input_redir(NULL, "");
  if (i == 0)
    printf("TEST2: ok");
  else
    printf("TEST2: failed");
  printf("\n");
}
void get_input_redir_test3() {
  t_cmd cmd;

  cmd.heredoc_del = NULL;
  cmd.in_redir = NIL;
  size_t i = get_input_redir(&cmd, "<< EOF ls");
  if (i == 6 && !ft_strncmp("EOF\0", cmd.heredoc_del, 4) &&
      cmd.in_redir == HEREDOC)
    printf("TEST2: ok");
  else
    printf("TEST2: failed '%s' %zu %i", cmd.heredoc_del, i, cmd.in_redir);
  printf("\n");
}

void get_input_redir_test() {
  get_input_redir_test1();
  get_input_redir_test2();
  get_input_redir_test3();
}
