/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_append.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:17:23 by aoumouss          #+#    #+#             */
/*   Updated: 2022/07/04 18:21:54 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_list_append(t_env_list **head, char *key, char *value)
{
	t_env_list	*new;
	t_env_list	*tmp;
	char		*tmp_value;

	tmp = env_list_get_node(*head, key);
	if (tmp)
	{
		if (value)
		{
			tmp_value = ft_strjoin(tmp->value, value);
			free(tmp->value);
			tmp->value = tmp_value;
		}
		return ;
	}
	else
		env_list_insert_one(head, key, value);
}
