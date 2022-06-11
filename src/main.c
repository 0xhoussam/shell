/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:51:26 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/09 07:22:32 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "minishell.h"

// const char *__asan_default_options() { return "detect_leaks=0"; }

int main(int ac, char **av, char **env)
{

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
  t_cmd cmd;

  cmd.cmd_name = "ls";
  cmd.args = NULL;
  get_args(&cmd, "file1 file2 file3");
  get_args(&cmd, "file2 file3");
  get_args(&cmd, "file3");
  get_args(&cmd, "-n");
  for (t_list *i = cmd.args; i ; i = i->next)
  {
    printf("%s\n", (char *)i->content);
  }
}
