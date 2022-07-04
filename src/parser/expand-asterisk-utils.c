/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand-asterisk-utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 10:55:05 by habouiba          #+#    #+#             */
/*   Updated: 2022/07/03 10:55:08 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parser.h"
#include "utils.h"

int	check_if_expandable(t_list *curr)
{
	if ((ft_includes(curr->content, '*'))
		&& !ft_includes(curr->content, '"')
		&& !ft_includes(curr->content, '\''))
		return (1);
	else
		return (0);
}

void	insert_at_front(t_list *expanded_arg, t_list *curr, t_cmd *cmd)
{
	ft_lstlast(expanded_arg)->next = curr->next;
	cmd->args = expanded_arg;
	free(curr->content);
	free(curr);
}

void	insert_at_any(t_list *prev, t_list *expanded_arg, t_list *curr)
{
	prev->next = expanded_arg;
	if (curr->next)
		expanded_arg->next = ft_lstlast(curr);
	free(curr->content);
	free(curr);
}

void	_expand_asterisk_init(t_cmd **cmd, void **_cmd,
	t_list **curr, t_list **prev)
{
	*cmd = (t_cmd *)*_cmd;
	*prev = NULL;
	*curr = (*cmd)->args;
}
