/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <habouiba@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 06:48:42 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/09 06:59:08 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char				*env_list_get(t_env_list *list, const char *key)
{
	t_env_list *current;

	current = list;
	while (current)
	{
			if (!ft_strncmp(current->key, key, ft_strlen(current->key))
					&& !ft_strncmp(current->key, key, ft_strlen(key)))
				return (current->value);
			current = current->next;
	}
	return (ft_strdup(""));
}
