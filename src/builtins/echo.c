/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:00:38 by habouiba          #+#    #+#             */
/*   Updated: 2022/05/31 15:25:56 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t  echo(const char *str, int flags)
{
    printf("%s", str);
    if (!(flags & ECHO_N_FLAG))
        printf("\n");
    return (ft_strlen(str));
}