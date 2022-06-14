/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-double-quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <habouiba@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 06:57:25 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/14 08:33:38 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"

char *join_3_strings(char *s1, char *s2, char *s3) {
  char *tmp;
  char *str;

  str = ft_strjoin(s1, s2);
  tmp = str;
  str = ft_strjoin(str, s3);
  free(tmp);
  return (str);
}

size_t count_char(const char *s, size_t len, char c) {
  size_t i;
  size_t count;

  i = 0;
  count = 0;
  while (s[i] && i < len) {
    if (s[i] == c)
      count++;
    i++;
  }
  return (count);
}

char *expande_string(char *s, t_env_list *env) {
  size_t l_idx;
  size_t r_idx;
  char *l_str;
  char *r_str;
  char *key;
  char *value;

  if (!ft_strnstr(s, "${", ft_strlen(s)))
    return NULL;
  l_idx = ft_strnstr(s, "${", ft_strlen(s)) - s;
  if (!ft_strnstr(&s[l_idx], "}", ft_strlen(&s[l_idx])))
    return NULL;
  if (count_char(s, l_idx, 'c') % 2 != 0)
    return (NULL);
  r_idx = ft_strnstr(&s[l_idx], "}", ft_strlen(&s[l_idx])) - s;
  l_str = ft_substr(s, 0, l_idx);
  r_str = ft_substr(s, r_idx + 1, -1);
  key = ft_substr(s, l_idx + 2, r_idx - l_idx - 2);
  value = env_list_get(env, key);
  return (join_3_strings(l_str, value, r_str));
}

char *parse_double_quotes(char *s, t_env_list *lst) {
  size_t i;
  char *tmp;
  char *ret;
  char *buff;

  if (*s != '"')
    return (s);
  i = 1;
  while (s[i]) {
    if (s[i] == '"')
      break;
    i++;
  }
  tmp = ft_substr(s, 1, i);
  while ((buff = expande_string(tmp, lst)) != NULL) {
    free(tmp);
    tmp = buff;
    ret = buff;
  }
  free(tmp);
  printf("%s\n", ret);
  return (ret);
}
