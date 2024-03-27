/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_clean.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:14:08 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/25 13:41:53 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	env_list_clean(t_env_list **lst)
{
	t_env_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->key);
		free((*lst)->value);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
