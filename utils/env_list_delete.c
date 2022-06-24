/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_delete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:02:36 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/24 19:14:18 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_env_list_node(t_env_list *node);

void	env_list_delete(t_env_list **list, char *key)
{
	t_env_list	*temp;
	t_env_list	*prev;

	if (!list || !*list || !key)
		return ;
	temp = *list;
	prev = NULL;
	while (temp)
	{
		if (!ft_strncmp(temp->key, key, max_strs_len(key, temp->key)))
		{
			if (!prev)
				*list = temp->next;
			else
			{
				prev->next = temp->next;
				temp->next = NULL;
			}
			free_env_list_node(temp);
			return ;
		}
		prev = temp;
		temp = temp->next;
	}
}

void	free_env_list_node(t_env_list *node)
{
	free(node->key);
	free(node->value);
	free(node);
}

size_t	max_strs_len(char *s1, char *s2)
{
	size_t	l1;
	size_t	l2;

	if (!s2 || !s2)
		return (0);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (l2 > l1)
		return (l2);
	return (l1);
}
