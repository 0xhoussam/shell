/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get-args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <habouiba@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:37:21 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/13 16:21:52 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

size_t get_args(t_cmd *cmd, const char *s) {
  size_t i;
  char *str;

  i = 0;
  if (!cmd || !cmd->cmd_name || !s || !*s)
    return (0);
  if (s[0] == '<' || s[0] == '>' || s[0] == '&' || s[0] == '|' || s[0] == '*' ||
      s[0] == ';')
    return (0);
  while (s[i] && !ft_isspace(s[i]))
    i++;
  str = ft_substr(s, 0, i);
  ft_lstadd_back(&cmd->args, ft_lstnew(str));
  return (i);
}

/* TESTES */

void get_args_test1() {
  t_cmd cmd;

  cmd.cmd_name = NULL;
  cmd.args = NULL;
  get_args(&cmd, "file1 file2 file3");
  if (!cmd.args)
    printf("TEST1: OK");
  else
    printf("TEST1: failed");
  printf("\n");
}

void get_args_test2() {
  t_cmd cmd;

  cmd.cmd_name = "ls";
  cmd.args = NULL;
  get_args(&cmd, "file1 file2 file3");
  if (!cmd.args)
    printf("TEST2: failed");
  else if (!ft_strncmp(cmd.args->content, "file1\0", 6) && !cmd.args->next)
    printf("TEST2: ok");
  else
    printf("TEST2: failed");
  printf("\n");
}

void get_args_test3() {
  t_cmd cmd;

  cmd.cmd_name = "ls";
  cmd.args = NULL;
  get_args(&cmd, ">file1 file2 file3");
  if (!cmd.args)
    printf("TEST3: ok");
  else
    printf("TEST3: failed");
  printf("\n");
}

void get_args_test4() {
  t_cmd cmd;

  cmd.cmd_name = "ls";
  cmd.args = NULL;
  get_args(&cmd, "<file1 file2 file3");
  if (!cmd.args)
    printf("TEST4: ok");
  else
    printf("TEST4: failed");
  printf("\n");
}
void get_args_test5() {
  t_cmd cmd;

  cmd.cmd_name = "ls";
  cmd.args = NULL;
  get_args(&cmd, "*file1 file2 file3");
  if (!cmd.args)
    printf("TEST5: ok");
  else
    printf("TEST5: failed");
  printf("\n");
}

void get_args_test6() {
  t_cmd cmd;

  cmd.cmd_name = "ls";
  cmd.args = NULL;
  get_args(&cmd, "<file1 file2 file3");
  if (!cmd.args)
    printf("TEST6: ok");
  else
    printf("TEST6: failed");
  printf("\n");
}

void get_args_test7() {
  t_cmd cmd;

  cmd.cmd_name = "ls";
  cmd.args = NULL;
  get_args(&cmd, "|file1 file2 file3");
  if (!cmd.args)
    printf("TEST7: ok");
  else
    printf("TEST7: failed");
  printf("\n");
}

void get_args_test8() {
  t_cmd cmd;

  cmd.cmd_name = "ls";
  cmd.args = NULL;
  get_args(&cmd, "&file1 file2 file3");
  if (!cmd.args)
    printf("TEST8: ok");
  else
    printf("TEST8: failed");
  printf("\n");
}
void get_args_test9() {
  t_cmd cmd;
  size_t ret;

  cmd.cmd_name = "ls";
  cmd.args = NULL;
  ret = get_args(&cmd, "file1 file2 file3");
  if (ret == 5)
    printf("TEST9: ok");
  else
    printf("TEST9: failed");
  printf("\n");
}

void get_args_test10() {
  t_cmd cmd;

  if (get_args(&cmd, NULL) == 0)
    printf("TEST10: ok");
  else
    printf("TEST10: failed");
  printf("\n");
  if (get_args(NULL, "file1") == 0)
    printf("TEST10: ok");
  else
    printf("TEST10: failed");
  printf("\n");
  if (get_args(NULL, NULL) == 0)
    printf("TEST10: ok");
  else
    printf("TEST10: failed");
  printf("\n");
}

void get_args_test11() {
  t_cmd cmd;
  size_t ret;

  cmd.cmd_name = "ls";
  cmd.args = NULL;
  ret = get_cmd_name(&cmd, "");
  if (ret == 0 && !cmd.args)
    printf("TESST11: ok");
  else
    printf("TEST11: failed");
  printf("\n");
}

void get_args_test() {
  printf("----- GET ARGS TESTS -----\n");
  get_args_test1();
  get_args_test2();
  get_args_test3();
  get_args_test4();
  get_args_test5();
  get_args_test6();
  get_args_test7();
  get_args_test8();
  get_args_test9();
  get_args_test10();
}
