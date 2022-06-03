/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset-helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <habouiba@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:54:02 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/03 18:55:20 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	echo_helper(const char *line, t_list **tokens, int *i)
{
	size_t	len;
	t_list	*node;
	t_token	*token;

	len = ft_strlen(&line[*i]);
	if (len < 5)
		return ;
	if (ft_strncmp(&line[*i], "unset ", ft_strlen("unset ")))
		return ;
	token = malloc(sizeof(t_token));
	if (!token)
	{
		strerror(ENOMEM);
		return ;
	}
	token->token_type = KEYWORD;
	token->keyword = UNSET;
	node = ft_lstnew(token);
	if (!node)
	{
		free(token);
		strerror(ENOMEM);
		return ;
	}
	ft_lstadd_back(tokens, node);
}
