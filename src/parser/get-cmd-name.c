/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get-cmd-name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 07:08:42 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/12 11:25:51 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

size_t get_cmd_name(t_cmd *cmd, char const *s) {
  size_t i;

  if (!cmd || cmd->cmd_name || !s || !*s)
    return (0);
  i = 0;
  while (ft_isalpha(s[i]))
    i++;
  cmd->cmd_name = ft_substr(s, 0, i);
  return (i);
}

/*	TESTS		*/

void get_cmd_name_test1() {
  t_cmd cmd;
  get_cmd_name(NULL, NULL);
  get_cmd_name(&cmd, NULL);
  get_cmd_name(NULL, "ls ~/Documents");
  printf("TEST1: ok\n");
}

void get_cmd_name_test2() {
  t_cmd cmd;

  cmd.cmd_name = NULL;
  size_t i = get_cmd_name(&cmd, "grep file.c hello");
  if (i == 4 && !ft_strncmp("grep\0", cmd.cmd_name, 5)) {
    printf("TEST2: ok");
  } else
    printf("TEST2: failed");
  printf("\n");
}

void get_cmd_name_test3() {
  t_cmd cmd;

  cmd.cmd_name = "ls";

  size_t i = get_cmd_name(&cmd, "echo hi");
  if (i == 0 && !ft_strncmp("ls\0", cmd.cmd_name, 3))
    printf("TEST3: ok");
  else
    printf("TEST3: failed");

  printf("\n");
}

void get_cmd_name_test() {
  get_cmd_name_test1();
  get_cmd_name_test2();
  get_cmd_name_test3();
}
