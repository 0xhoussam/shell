/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_delete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:02:36 by habouiba          #+#    #+#             */
/*   Updated: 2022/05/31 17:16:37 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_env_list_node(t_env_list *node);

void    env_list_delete(t_env_list **list, char *key)
{
	t_env_list  *temp;
	t_env_list  *prev;
	size_t		max_key_len;

	if (!list || !*list || !key)
		return ;
	temp = *list;
	prev = NULL;
	max_key_len = max_strs_len(key, temp->key);
	while (temp)
	{
		if (!ft_strncmp(temp->key, key, max_key_len))
		{
			if (!prev)
				*list = temp->next;
			else
				prev->next = temp->next;
			temp->next = NULL;
			free_env_list_node(temp);
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
	size_t	l1, l2;

	if (!s2 || !s2)
		return (0);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (l2 > l1)
		return (l2);
	return (l1);
}