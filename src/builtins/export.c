/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:50:05 by aoumouss          #+#    #+#             */
/*   Updated: 2022/05/31 15:25:05 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    print_env_list(t_env_list *list);

void    export(t_env_list **list, char *key, char *value)
{
    if (!key && !value)
    {
        print_env_list(*list);
        return ;
    }
    env_list_insert(list, key, value);
}

void    print_env_list(t_env_list *list)
{
    char    **env;
    int     i;

    env = env_list_to_array(list);
    sort_strs(env);
    i = 0;
    while (env[i])
    {
        printf("%s\n", env[i]);
        i++;
    }

}