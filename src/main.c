/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:51:26 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/14 16:51:33 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "tests.h"

// const char *__asan_default_options() { return "detect_leaks=0"; }

void print_cmds(t_list *cmds);

int main(int ac, char **av, char **env)
{

  ac = (int)ac;
  av = (char **)av;
  env = (char **)env;
  t_env_list lst;

  t_list *commands = generator();
  print_cmds(commands);
  executer(commands, env);
  return (g_exit_code);
}

void print_cmds(t_list *cmds)
{
  while (cmds)
  {
    t_cmd *cmd = (t_cmd *)cmds->content;
    printf("%s ", (char *)cmd->cmd_name);
    t_list *args = cmd->args;
    while (args->next)
    {
      printf("%s ", (char *)args->next->content);
      args = args->next;
    }
    if (cmds->next)
      printf(" | ");
    cmds = cmds->next;
  }
  printf("\n");
}

// TODO ; is not working noting printing
