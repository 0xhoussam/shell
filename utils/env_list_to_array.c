/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_to_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:20:02 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/25 19:33:44 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	list_length(t_env_list *list);

char	**env_list_to_array(t_env_list *list)
{
	char	**env;
	char	*helper;
	int		i;

	env = malloc(sizeof(char *) * (list_length(list) + 1));
	i = 0;
	while (list)
	{
		helper = ft_strjoin(list->key, "=");
		if (list->value)
			env[i] = ft_strjoin(helper, list->value);
		else
			i--;
		free(helper);
		i++;
		list = list->next;
	}
	env[i] = NULL;
	return (env);
}

int	list_length(t_env_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}
