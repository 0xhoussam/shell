/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:00:38 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/20 20:01:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    print_2d_array(char **str);

void    echo(t_params *params)
{
    char    **str;
    t_cmd   *cmd;
    t_list  *args;
    int     i;

    cmd = params->cmd;

    args = cmd->args->next;
    str = join_args(args);
    g_exit_code = 0;
    if (args && !ft_strcmp(args->content, "-n"))
    {
        args = args->next;
        str = join_args(args);
        print_2d_array(str);
        free_2d_array(str);
        return ;
    }
    print_2d_array(str);
    printf("\n");
    free_2d_array(str);
}

void    print_2d_array(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        printf("%s", str[i]);
        i++;
        if (str[i])
            printf(" ");
    }
}