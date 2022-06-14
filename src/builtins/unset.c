/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:57:26 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/14 18:03:28 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    unset(t_params *params)
{
    t_env_list  *list;
    char        *key;

    list = env_array_to_list(params->env);
    key =  params->cmd->args->content;
    env_list_delete(&list, key);
}