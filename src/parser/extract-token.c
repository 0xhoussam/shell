/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if-helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <habouiba@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:34:40 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/06 09:31:11 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
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
	char **key_tokens;
	char **pun_tokens;
	char **op_tokens;

	key_tokens = ft_split(KEYWORDS, ' ');
	pun_tokens = ft_split(PUNCTUATIONS, ' ');
	op_tokens = ft_split(OPERATORS, ' ');
	if (ft_strnstr(KEYWORDS, word, ft_strlen(word)))
	{
		token->token_type = KEYWORD;
		token->keyword = index_of(key_tokens, word);
	}
	if (ft_strnstr(PUNCTUATIONS, word, ft_strlen(word)))
	{
		token->token_type = PUNCTUATION;
		token->punc = index_of(pun_tokens, word);
	}
	if (ft_strnstr(OPERATORS, word, ft_strlen(word)))
	{
		token->token_type = OPERATOR;
		token->op = index_of(op_tokens, word);
	}
	array_2d_free(key_tokens);
	array_2d_free(pun_tokens);
	array_2d_free(op_tokens);
}

void	extract_token(const char *line, t_list **tokens, int *i, const char *word)
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
	ft_lstadd_back(tokens, node);
}
