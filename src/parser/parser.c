/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <habouiba@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:34:33 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/11 18:15:20 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "utils.h"

// char	*join_3_strings(char *s1, char *s2, char *s3)
// {
// 	char	*tmp;
// 	char	*str;

// 	str = ft_strjoin(s1, s2);
// 	tmp = str;
// 	str = ft_strjoin(str, s3);
// 	free(tmp);
// 	return (str);
// }

// char	*expande_string(char *s, t_env_list *env)
// {
// 	size_t	l_idx;
// 	size_t	r_idx;
// 	char		*l_str;
// 	char		*r_str;
// 	char		*key;
// 	char		*value;

// 	if (!ft_strnstr(s, "${", ft_strlen(s)))
// 		return NULL;
// 	l_idx = ft_strnstr(s, "${", ft_strlen(s)) - s;
// 	if (!ft_strnstr(&s[l_idx], "}", ft_strlen(&s[l_idx])))
// 		return NULL;
// 	r_idx = ft_strnstr(&s[l_idx], "}", ft_strlen(&s[l_idx])) - s;
// 	l_str = ft_substr(s, 0, l_idx);
// 	r_str = ft_substr(s, r_idx + 1, -1);
// 	key = ft_substr(s, l_idx + 2, r_idx - l_idx - 2);
// 	value = env_list_get(env, key);
// 	return (join_3_strings(l_str, value, r_str));
// }

void recursive_parser(t_list **cmds, t_cmd *cmd, char *s) {
  size_t i;

  if (!s)
    return;
  if (!*s) {
    if (cmd->cmd_name)
      ft_lstadd_back(cmds, ft_lstnew(cmd));
    return;
  }
  while (ft_isspace(*s))
    s++;
  printf("cmd: '%s'\n", s);
  if (!cmd) {
    cmd = malloc(sizeof(t_cmd));
    ft_bzero(cmd, sizeof(t_cmd));
  }
  i = get_cmd_name(cmd, s);
  if (i > 0)
    recursive_parser(cmds, cmd, &s[i]);
  i = get_input_redir(cmd, s);
  if (i > 0)
    recursive_parser(cmds, cmd, &s[i]);
  i = get_output_redir(cmd, s);
  if (i > 0)
    recursive_parser(cmds, cmd, &s[i]);
  i = get_args(cmd, s);
  if (i > 0)
    recursive_parser(cmds, cmd, &s[i]);
  // TODO: make a one function run at a time;
}

t_list *parser(char *line) {
  t_list *cmds;

  cmds = malloc(sizeof(t_list));
  cmds = NULL;
  recursive_parser(&cmds, NULL, line);
  return (cmds);
}
