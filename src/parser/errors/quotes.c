/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <habouiba@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:11:15 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/23 16:35:55 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int check_quotes(char *s)
{
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0;
    while (s[i])
    {
        if (s[i] == '\'')
            j++;
        else if (s[i] == '"')
            k++;
        i++;
    }
    if (j % 2 != 0 || k % 2 != 0)
    {
        perror("unclosed quotes");
        return (1);
    }
    return (0);
}
