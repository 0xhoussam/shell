/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 06:48:42 by habouiba          #+#    #+#             */
/*   Updated: 2022/07/01 11:57:47 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*env_list_get(t_env_list *list, const char *key)
{
	t_env_list	*current;

	current = list;
	while (current)
	{
		if (!ft_strncmp(current->key, key, ft_strlen(current->key))
			&& !ft_strncmp(current->key, key, ft_strlen(key)))
			return (current->value);
		current = current->next;
	}
	return (NULL);
}

t_env_list	*env_list_get_node(t_env_list *list, char *key)
{
	t_env_list	*current;

	if (!key)
		return (NULL);
	current = list;
	while (current)
	{
		if (!ft_strcmp(current->key, key))
			return (current);
		current = current->next;
	}
	return (NULL);
}
