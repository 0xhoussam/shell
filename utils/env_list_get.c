/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 06:48:42 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/24 19:14:22 by aoumouss         ###   ########.fr       */
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
	return (ft_strdup(""));
}

char	*get_env_variable(char **env, char *key)
{
	int	i;
	int	key_len;

	key_len = ft_strlen(key);
	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], key, key_len))
			return (env[i] + key_len + 1);
		i++;
	}
	return (NULL);
}
