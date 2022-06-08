/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <habouiba@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:34:33 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/07 15:25:47 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"

const char *get_cmd_name(const char *cmd)
{
  int         i;
  const char *s;

  i = 0;
  while (cmd[i] && !ft_isspace(cmd[i]))
    i++;
  s = ft_substr(cmd, 0, i);
  return (s);
}

t_list *get_cmd_args(const char *cmd, size_t cmd_name_len)
{
  int     i;
  int     j;
  t_list *args;
  t_list *new_node;
  char   *arg;

  args = NULL;
  i = cmd_name_len;
  args = ft_lstnew(NULL);
  while (cmd[i])
  {
    j = 0;
    while (cmd[i] && ft_isspace(cmd[i]))
      i++;
    while (cmd[i + j] && !ft_isspace(cmd[i + j]))
      j++;
    arg = ft_substr(cmd, i, j);
    new_node = ft_lstnew(arg);
    ft_lstadd_back(&args, new_node);
    i += j;
  }
  return (args);
}

// echo -n "hello world"
void extract_attr(const char *str, t_list **cmds)
{
  t_cmd *cmd;
  // char **tmp;

  cmd = malloc(sizeof(t_cmd));
  if (!cmd)
    return;
  cmd->cmd_name = get_cmd_name(str);
  cmd->args = get_cmd_args(str, ft_strlen(cmd->cmd_name));
  ft_lstadd_back(cmds, ft_lstnew(cmd));
}

t_list *parser(const char *line)
{
  char  **line_tokens;
  t_list *cmds;
  char   *tmp;
  int     i;

  if (!line || ft_strlen(line) == 0)
    return NULL;
  line_tokens = ft_split(line, '|');
  if (!line_tokens)
    return (NULL);
  i = 0;
  while (line_tokens[i])
  {
    tmp = line_tokens[i];
    line_tokens[i] = ft_strtrim(line_tokens[i], " \n\t\v\f\r");
    extract_attr(line_tokens[i], &cmds);
    free(tmp);
    i++;
  }
  return (cmds);
}
