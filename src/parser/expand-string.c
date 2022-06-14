/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand-string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <habouiba@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:46:44 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/14 11:07:29 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"

int is_inside_single_quotes(char *s, size_t idx) {
  int i;

  i = 0;
  s = &s[idx];
  while (*s) {
    if (*s == '\'')
      i++;
    s++;
  }
  if (i % 2 == 0)
    return (0);
  return (1);
}

// char *expand_string(char *s, size_t start, size_t end) {
//   char *result;

// 	while (s[start] && start < end)
// 	{
// 			if (s[start] == '$' && !is_inside_single_quotes(s,
// start))
// 			{

// 			}
// 	}
//   return (result);
// }
