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

// t_list *parser(const char *line)
// {
//   char  **line_tokens;
//   t_list *cmds;
//   char   *tmp;
//   int     i;

//   if (!line || ft_strlen(line) == 0)
//     return NULL;
//   cmds = NULL;
//   line_tokens = ft_split(line, '|');
//   if (!line_tokens)
//     return (NULL);
//   i = 0;
//   while (line_tokens[i])
//   {
//     tmp = line_tokens[i];
//     line_tokens[i] = ft_strtrim(line_tokens[i], " \n\t\v\f\r");
//     extract_attr(line_tokens[i], &cmds);
//     free(tmp);
//     i++;
//   }
//   array_2d_free(line_tokens);
//   return (cmds);
// }
