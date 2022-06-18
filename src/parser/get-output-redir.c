/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get-output-redir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 07:50:39 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/18 09:53:05 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t get_output_redir(t_cmd *cmd, const char *s) {
  size_t s_len;
  size_t i;
  size_t j;

  if (!cmd || !s || !*s)
    return (0);
  s_len = ft_strlen(s);
  if (s_len < 2)
    return (0);
  if (s[0] != '>')
    return (0);
  if (s[1] == '>') {
    cmd->out_redir = DOUBLE;
    i = 2;
  } else {
    cmd->out_redir = SINGLE;
    i = 1;
  }
  while (ft_isspace(s[i]))
    i++;
  j = i;
  while (!ft_isspace(s[j]) && !is_spicial(s[j]))
    j++;
  if (cmd->out)
    free(cmd->out);
  cmd->out = ft_substr(s, i, j - i);
  return (j);
}

/*	TESTS		*/

void get_output_redir_test1() {
  t_cmd cmd;

  cmd.out = NULL;
  get_output_redir(NULL, NULL);
  get_output_redir(&cmd, NULL);
  get_output_redir(NULL, "> hello ls");
  size_t i = get_output_redir(&cmd, "> hello ls .");
  if (i == 7 && !ft_strncmp("hello\0", cmd.out, 5) && cmd.out_redir == SINGLE) {
    printf("TEST1: ok");
  } else
    printf("TEST1: failed '%s'", cmd.out);
  printf("\n");
}

void get_output_redir_test2() {
  t_cmd cmd;

  cmd.in = NULL;
  size_t i = get_output_redir(NULL, "");
  if (i == 0)
    printf("TEST2: ok");
  else
    printf("TEST2: failed");
  printf("\n");
}

void get_output_redir_test3() {
  t_cmd cmd;

  cmd.in = NULL;
  size_t i = get_output_redir(&cmd, ">> file ls");
  if (i == 8 && !ft_strnstr("file\0", cmd.out, 5) && cmd.out_redir == DOUBLE)
    printf("TEST2: ok");
  else
    printf("TEST2: failed '%s' %zu %i", cmd.out, i, cmd.out_redir);
  printf("\n");
}

void get_output_redir_test() {
  get_output_redir_test1();
  get_output_redir_test2();
  get_output_redir_test3();
}
