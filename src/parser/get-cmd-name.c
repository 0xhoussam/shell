/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get-cmd-name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 07:08:42 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/17 12:53:40 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// echo
// ec"ho"
// ec$ho

// size_t get_cmd_name(t_cmd *cmd, char const *s, t_env_list *lst) {
//   size_t i;
//   char *tmp;

//   if (!cmd || cmd->cmd_name || !s || !*s || *s == '<' || *s == '>' ||
//       *s == ';' || *s == '&' || *s == '|')
//     return (0);
//   i = 0;
//   if (s[0] == '$') {
//     i = 1;
//     while (!ft_isspace(s[i]))
//       i++;
//     tmp = ft_substr(s, 1, i);
//     cmd->cmd_name = env_list_get(lst, tmp);
//     if (!*cmd->cmd_name) {
//       free((void *)cmd->cmd_name);
//       cmd->cmd_name = NULL;
//     }
//     free(tmp);
//   } else {
//     while (ft_isalpha(s[i]))
//       i++;
//     cmd->cmd_name = ft_substr(s, 0, i);
//   }
//   return (i);
// }


size_t get_cmd_name(t_cmd *cmd, char const *s, t_env_list *lst) {
  size_t i;

  if (!cmd || cmd->cmd_name || !s || !*s || *s == '<' || *s == '>' ||
      *s == ';' || *s == '&' || *s == '|')
    return (0);
  i = 0;
  while (!ft_isspace(s[i]))
    i++;
  cmd->cmd_name = ft_substr(s, 0, i);
  return (i);
}
