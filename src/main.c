/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:51:26 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/13 10:58:52 by habouiba         ###   ########.fr       */
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
  // t_list *cmds;
  // t_list *tmp;

  // cmds = parser("echo hello world houssam | grep \"Hell\" world");
  // tmp = cmds;
  // while (tmp)
  // {
  //   printf("COMMAND NAME: %s \t", ((t_cmd *)tmp->content)->cmd_name);
  //   for (t_list *i = ((t_cmd *)tmp->content)->args; i != NULL; i = i->next)
  //   {
  //     printf("'%s'  ", (char *)i->content);
  //   }
  //   ft_lstclear(&((t_cmd *)tmp->content)->args, free);
  //   printf("\n");
  //   free((void *)((t_cmd *)tmp->content)->cmd_name);
  //   tmp = tmp->next;
  // }
  // ft_lstclear(&cmds, free);
  t_list *cmds;

  cmds = NULL;
  cmds = parser(ft_strdup("ls ../ > log | cat tmp"));
  print_cmds(cmds);
}

void print_cmds(t_list *cmds) {
  // char *a[] = {"none", "and", "or", "semicolon", "pipe"};
  // char *b[] = {"nil", "single", "double", "heredoc"};
  t_list *node = cmds;
  printf("'%s'\n", (char *)((t_cmd *)node->content)->args->content);
  // for (t_list *node = cmds; node; node = node->next) {
  // printf("--------------------------------------------------\n");
  // printf("cmd name: %s\n", ((t_cmd *)node->content)->cmd_name);
  // printf("args:  ");
  // printf("'%p'\n", (char *)((t_cmd *)node->content)->args);
  // for (t_list *arg = ((t_cmd *)node->content)->args; arg; arg = arg->next)
  // {
  //   printf("%s  ", (char *)arg->content);
  // }
  // printf("\n");
  // printf("left prio %s\n", a[((t_cmd *)node->content)->left_priority]);
  // printf("right prio %s\n", a[((t_cmd *)node->content)->right_priority]);
  // printf("in %s type %s\n", ((t_cmd *)node->content)->in,
  //        b[((t_cmd *)node->content)->in_redir]);
  // printf("out %s type %s\n", ((t_cmd *)node->content)->out,
  //        b[((t_cmd *)node->content)->out_redir]);
  // printf("heredoc: %s\n", ((t_cmd *)node->content)->heredoc_del);
  // }
}
