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

// line: if [] then  eccho -n "dakjbf" fi \n grep "houssam" file.c

int	index_of(char **str, const char *word)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_strncmp(str[i], word, ft_strlen(word)))
			return (i);
		i++;
	}
	return (-1);
}

void	token_detector(t_token *token, const char *word)
{
	char **tokens;

	tokens = ft_split(KEYWORDS, ' ');
	if (ft_strnstr(KEYWORDS, word, ft_strlen(KEYWORDS)))
	{
		token->token_type = KEYWORD;
		token->keyword = index_of(tokens, word);
	}
	if (ft_strnstr(PUNCTUATIONS, word, ft_strlen(PUNCTUATIONS)))
	{
		token->token_type = PUNCTUATION;
		token->punc = index_of(tokens, word);
	}
	if (ft_strnstr(OPERATORS, word, ft_strlen(OPERATORS)))
	{
		token->token_type = OPERATOR;
		token->op = index_of(tokens, word);
	}
	array_2d_free(tokens);
}

void	if_helper(const char *line, t_list **tokens, int *i, const char *word)
{
	size_t	len;
	t_list	*node;
	t_token	*token;

	len = ft_strlen(&line[*i]);
	if (len < ft_strlen(word))
		return ;
	if (ft_strncmp(&line[*i], word, ft_strlen(word)))
		return ;
	// if (!ft_isspace(line[*i + ft_strlen(word) + 1])) // todo: handle spaces
	// 	return ;
	token = malloc(sizeof(t_token));
	if (!token)
	{
		strerror(ENOMEM);
		return ;
	}
	token_detector(token, word);
	node = ft_lstnew(token);
	node->content = token;
	if (!node)
	{
		free(token);
		strerror(ENOMEM);
		return ;
	}
	*i += ft_strlen(word);
	(*i) += 1;
	ft_lstadd_back(tokens, node);
}
