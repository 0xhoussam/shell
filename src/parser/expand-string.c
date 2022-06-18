/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand-string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:46:44 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/18 16:11:57 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "types.h"
#include "utils.h"

// ""
// ''
// $

static char *ft_chardump(int c)
{
  char *str;

  str = malloc(sizeof(char) * 2);
  if (!str)
    return (NULL);
  str[0] = c;
  str[1] = '\0';
  return (str);
}

char *expand(const char *str, t_env_list *env)
{
  int i;

  i = 0;
  while (str[i])
  {
  }
  return (NULL);
}
