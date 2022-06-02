/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:14:57 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/01 12:15:03 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env_list *env_list_insert(t_env_list **head, char *key, char *value)
{
    t_env_list  *new;
    
    new = malloc(sizeof(t_env_list));;
    new->key = key;
    new->value = value;
    new->next = *head;
    *head = new;
    return (new);
}