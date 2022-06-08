/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <habouiba@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:34:33 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/08 08:39:46 by habouiba         ###   ########.fr       */
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

// echo  "hello " hi "world"

size_t	get_first_arg(const char *s, const char **subs)
{
	size_t		i;
	size_t		j;

	i = 0;
	subs = 0;
	if (!s[i])
			return (0);
	if (s[i] == '\'' || s[i] == '"')
		i++;
	j = i;
	while (s[j] && s[j] != '"' && s[j] != '\'')
	 j++;
	*subs = ft_substr(s, i, j);
	return (i + j);
}

t_list *get_cmd_args(const char *cmd)
{
	t_list	*args;
	size_t	i;
	const char	*arg;

	args = NULL;
	i = 0;
	while (cmd[i])
	{
		i += get_first_arg(&cmd[i], &arg);
		ft_lstadd_back(&args, ft_lstnew((void *)arg));
	}
	return (args);
}

void extract_attr(const char *str, t_list **cmds)
{
  t_cmd *cmd;

  cmd = malloc(sizeof(t_cmd));
  if (!cmd)
    return;
  cmd->cmd_name = get_cmd_name(str);
  cmd->args = get_cmd_args(&str[ft_strlen(cmd->cmd_name)]);
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
