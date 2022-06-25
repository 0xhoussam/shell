/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:14:57 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/25 21:00:00 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_list_insert(t_env_list **head, char *key, char *value)
{
	t_env_list	*new;
	t_env_list	*tmp;

	tmp = env_list_get_node(*head, key);
	if (tmp)
	{
		if (value)
			tmp->value = value;
		return ;
	}
	new = malloc(sizeof(t_env_list));
	new->key = key;
	new->value = value;
	new->next = *head;
	*head = new;
}
