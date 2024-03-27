/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:33:20 by aoumouss          #+#    #+#             */
/*   Updated: 2022/07/04 18:41:55 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	valid_token(t_list *prev_node, t_list *node, t_analysis *an);

int	syntax_analysis(t_list *tokens)
{
	t_list				*prev_token;
	t_analysis			analysis;

	analysis.open_parentheses = 0;
	analysis.s_quotes = 0;
	analysis.d_quotes = 0;
	prev_token = NULL;
	while (tokens)
	{
		if (!valid_token(prev_token, tokens, &analysis))
			return (0);
		prev_token = tokens;
		tokens = tokens->next;
	}
	return (1);
}

static int	valid_token(t_list *prev_node, t_list *node, t_analysis *an)
{
	int		ret;
	t_token	*token;

	ret = 1;
	token = node->content;
	if (token->type == LEX_PIPE || token->type == LEX_AND
		|| token->type == LEX_OR)
		ret = check_binary_operators(prev_node, node);
	if (token->type == LEX_REDIR)
		ret = check_unary_operators(node);
	if (token->type == CLOSE_PARENTHESIS || token->type == OPEN_PARENTHESIS)
		ret = check_parentheses_syntax(prev_node, node, an);
	if (token->type == LEX_WORD)
		ret = check_word_syntax(node, an);
	return (ret);
}
