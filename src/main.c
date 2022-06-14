/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:51:26 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/14 11:01:16 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "tests.h"

// const char *__asan_default_options() { return "detect_leaks=0"; }

void print_cmds(t_list *cmds);
int main(int ac, char **av, char **env) {

  ac = (int)ac;
  av = (char **)av;
  env = (char **)env;
  t_env_list lst;

  t_list *commands = generator();
  t_list *tmp = commands;
  lst.key = "name";
  lst.value = "houssam";
  lst.next = NULL;
  t_list *cmds;

  cmds = parser("$name >tmp hello || ls .", &lst);
  print_cmds(cmds);
}
void print_cmds(t_list *cmds) {
  char *a[] = {"none", "and", "or", "semicolon", "pipe"};
  char *b[] = {"nil", "single", "double", "heredoc"};
  for (t_list *node = cmds; node; node = node->next) {
    printf("--------------------------------------------------\n");
    printf("cmd name: %s\n", ((t_cmd *)node->content)->cmd_name);
    printf("args:  ");
    for (t_list *arg = ((t_cmd *)node->content)->args; arg; arg = arg->next) {
      printf("%s  ", (char *)arg->content);
    }
    printf("\n");
    printf("left prio %s\n", a[((t_cmd *)node->content)->left_delimiter]);
    printf("right prio %s\n", a[((t_cmd *)node->content)->right_delimiter]);
    printf("in %s type %s\n", ((t_cmd *)node->content)->in,
           b[((t_cmd *)node->content)->in_redir]);
    printf("out %s type %s\n", ((t_cmd *)node->content)->out,
           b[((t_cmd *)node->content)->out_redir]);
    printf("heredoc: %s\n", ((t_cmd *)node->content)->heredoc_del);
  }
}

// TODO ; is not working noting printing
