/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <habouiba@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:16:06 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/17 11:18:10 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int is_valid(const char *s, int c) {
  int count;
  int i;

  count = 0;
  i = 0;
  while (s[i]) {
    if (s[i] == c)
      count++;
    i++;
  }
  if (count % 2)
    return (0);
  return (1);
}
