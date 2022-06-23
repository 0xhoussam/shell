/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_array_to_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:33:41 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/23 22:41:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env_list *new_node();
t_env_list *add_node(t_env_list **head, char *str);

t_env_list *env_array_to_list(char **env)
{
	int i;
	t_env_list *list;

	list = NULL;
	i = 0;
	while (env[i])
	{
		add_node(&list, env[i]);
		i++;
	}
	return (list);
}

t_env_list *new_node()
{
	t_env_list *new;

	new = malloc(sizeof(t_env_list));
	new->next = NULL;
	return (new);
}

t_env_list *add_node(t_env_list **head, char *str)
{
	t_env_list	*new;
	char		**key_value;

	new = new_node();
	key_value = ft_split(str, '=');
	new->key = key_value[0];
	if (!key_value[1])
		new->value = ft_strdup("");
	else
		new->value = key_value[1];
	free(key_value);
	new->next = *head;
	*head = new;
	return (new);
}