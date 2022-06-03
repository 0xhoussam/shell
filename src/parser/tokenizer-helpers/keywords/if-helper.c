/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if-helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <habouiba@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:34:40 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/03 19:07:23 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// line: if [] then fi

void	echo_helper(const char *line, t_list **tokens, int *i)
{
	size_t	len;
	t_list	*node;
	t_token	*token;

	len = ft_strlen(&line[*i]);
	if (len < ft_strlen("if "))
		return ;
	if (ft_strncmp(&line[*i], "if", ft_strlen("if")))
		return ;
	if (!ft_isspace(line[*i + 2]))
		return ;
	token = malloc(sizeof(t_token));
	if (!token)
	{
		strerror(ENOMEM);
		return ;
	}
	token->token_type = KEYWORD;
	token->keyword = IF;
	node = ft_lstnew(token);
	if (!node)
	{
		free(token);
		strerror(ENOMEM);
		return ;
	}
	ft_lstadd_back(tokens, node);
}
