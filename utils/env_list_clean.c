/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_clean.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:14:08 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/24 19:14:10 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	_env_list_clean(t_env_list *lst)
{
	if (lst->next)
		_env_list_clean(lst->next);
	free(lst->key);
	free(lst->value);
	free(lst);
}

void	env_list_clean(t_env_list **lst)
{
	_env_list_clean(*lst);
	*lst = NULL;
}
