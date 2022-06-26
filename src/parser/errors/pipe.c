/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <habouiba@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:17:41 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/23 16:37:58 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int check_pipe(char *s)
{
    size_t len;

    len = ft_strlen(s);
    if (s[0] == '|' || s[len - 1] == '|')
    {
        perror("Error: Unclosed pipeline\n");
        return (1);
    }
    return (0);
}
