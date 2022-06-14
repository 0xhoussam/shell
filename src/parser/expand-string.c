/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand-string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:46:44 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/14 17:58:44 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
