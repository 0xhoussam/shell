/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:44:43 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/14 17:57:03 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    pwd(t_params *params)
{
    char    path[MAX_BUF];

    ft_bzero(path, MAX_BUF);
    if (!getcwd(path, MAX_BUF))
    {
		write(2, PROGRAM_NAME, ft_strlen(PROGRAM_NAME));
		write(2, " pwd: ", ft_strlen(" pwd: "));
		perror(NULL);
        return ;
    }
    printf("%s\n", path);
}