/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <habouiba@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:05:34 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/24 15:30:54 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int check_redirection(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] == '"')
        {
            i++;
            while (s[i] != '"')
                i++;
        }
        if (s[i] == '\'')
        {
            i++;
            while (s[i] != '\'')
                i++;
        }
        if (s[i] == '<' || s[i] == '>')
        {
            i++;
            if (s[i] == '<' || s[i] == '>')
                i++;
            while (ft_isspace(s[i]))
                i++;
            if (!ft_isalpha(s[i]))
            {
                perror("error: unexpected token");
                return (1);
            }
        }
        i++;
    }
    return (0);
}
