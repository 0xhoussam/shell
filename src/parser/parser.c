/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <habouiba@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:34:33 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/09 07:16:04 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"
#include "utils.h"

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

char	*join_3_strings(char *s1, char *s2, char *s3)
{
	char	*tmp;
	char	*str;

	str = ft_strjoin(s1, s2);
	tmp = str;
	str = ft_strjoin(str, s3);
	free(tmp);
	return (str);
}

char	*expande_string(char *s, t_env_list *env)
{
	size_t	l_idx;
	size_t	r_idx;
	char		*l_str;
	char		*r_str;
	char		*key;
	char		*value;

	if (!ft_strnstr(s, "${", ft_strlen(s)))
		return NULL;
	l_idx = ft_strnstr(s, "${", ft_strlen(s)) - s;
	if (!ft_strnstr(&s[l_idx], "}", ft_strlen(&s[l_idx])))
		return NULL;
	r_idx = ft_strnstr(&s[l_idx], "}", ft_strlen(&s[l_idx])) - s;
	l_str = ft_substr(s, 0, l_idx);
	r_str = ft_substr(s, r_idx + 1, -1);
	key = ft_substr(s, l_idx + 2, r_idx - l_idx - 2);
	value = env_list_get(env, key);
	return (join_3_strings(l_str, value, r_str));
}

size_t get_first_arg(const char *s, char **subs)
{
  size_t i;
  size_t j;
  char  *tmp;

  i = 0;
  *subs = 0;
  if (!s[i])
    return (0);
  if (s[i] == '\'' || s[i] == '"')
    i++;
  j = 0;
  while (s[i + j] && s[i + j] != '"' && s[i + j] != '\'')
    j++;
  tmp = ft_substr(s, i, j);
  *subs = ft_strtrim(tmp, "\"");
  free(tmp);
  return (i + j);
}

t_list *get_cmd_args(const char *cmd)
{
  t_list *args;
  size_t  i;
  char   *arg;
  char   *tmp;

  args = NULL;
  arg = NULL;
  i = 0;
  tmp = ft_strtrim(cmd, " ");
  while (tmp[i])
  {
    i += get_first_arg(&tmp[i], &arg);
    if (ft_strlen(arg) != 0)
      ft_lstadd_back(&args, ft_lstnew((void *)arg));
    else
    {
      free(arg);
      arg = NULL;
    }
  }
  free(tmp);
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
  cmds = NULL;
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
  array_2d_free(line_tokens);
  return (cmds);
}
