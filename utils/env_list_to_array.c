/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_to_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:20:02 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/11 18:22:51 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    **env_list_to_array(t_env_list *list)
{
    char    **env;
    char    *helper;
    int     i;

    env = malloc(sizeof(char *) * ft_lstsize(list) + 1);
    i = 0;
    while (list)
    {
        helper = ft_strjoin(list->key, "=");
        env[i] = ft_strjoin(helper, list->value);
        free(helper);
        i++;
        list = list->next;
    }
    env[i] = NULL;
    return (env);
}
