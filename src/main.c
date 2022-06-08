/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:51:26 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/07 15:35:43 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "minishell.h"

const char *__asan_default_options() { return "detect_leaks=0"; }

int main(int ac, char **av, char **env)
{

  ac = (int)ac;
  av = (char **)av;
  env = (char **)env;
  t_list *cmds;
  t_list *tmp;

  cmds = parser("ls . | echo -n \"hello world\" | grep file.c \"main\"");
  tmp = cmds;
  printf("Hello World");
  while (tmp)
  {
    printf("COMMAND NAME: %s \t", ((t_cmd *)tmp->content)->cmd_name);
    for (t_list *i = ((t_cmd *)tmp->content)->args; i != NULL; i = i->next)
    {
      printf("'%s'  ", (char *)i->content);
    }
    printf("\n");
    tmp = tmp->next;
  }
}
