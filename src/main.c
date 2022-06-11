/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:51:26 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/11 17:38:58 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "tests.h"

// const char *__asan_default_options() { return "detect_leaks=0"; }

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

  cmds = parser(ft_strdup("ls ../ > log"));
  // printf("%p", cmds);
  // printf("%s\n", ((t_cmd *)cmds->content)->cmd_name);
  // printf("%s", ((t_cmd *)cmds->content)->out);
  // printf("%i", ((t_cmd *)cmds->content)->out_redir);
}
