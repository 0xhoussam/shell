/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:51:26 by habouiba          #+#    #+#             */
/*   Updated: 2022/05/31 17:17:10 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **env) {

  ac = (int)ac;
  av = (char **)av;
  env = (char **)env;

  t_env_list *list = env_array_to_list(env);
  export(&list, "AYOUB", "");
  // export(&list, NULL, NULL);
  char **env_ = env_list_to_array(list);
  int i = 0;
  while (env_[i])
  {
    printf("%s\n", env_[i]);
    i++;
  }  
}
