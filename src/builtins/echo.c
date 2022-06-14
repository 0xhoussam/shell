/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:00:38 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/14 16:16:30 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t  echo(t_params *params)
{
    char    **str;

    str = join_args(params->cmd);
    printf("%s", *str);
    return (ft_strlen(*str));
}