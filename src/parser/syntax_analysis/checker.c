/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:21:51 by aoumouss          #+#    #+#             */
/*   Updated: 2022/07/02 20:33:19 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_binary_operators(t_list *prev_node, t_list *node)
{
	t_token	*next_token;
	t_token	*prev_token;
	t_token	*token;

	token = node->content;
	if (!prev_node)
		return (syntax_error_logger(token->value));
	if (!node->next)
		return (syntax_error_logger("newline"));
	next_token = node->next->content;
	prev_token = prev_node->content;
	if (prev_token->type == LEX_PIPE || prev_token->type == LEX_AND
		|| prev_token->type == LEX_OR)
		return (syntax_error_logger(token->value));
	if (next_token->type == LEX_PIPE || next_token->type == LEX_AND
		|| next_token->type == LEX_OR)
		return (syntax_error_logger(next_token->value));
	return (1);
}

int	check_unary_operators(t_list *node)
{
	t_token	*next_token;

	if (!node->next)
		return (syntax_error_logger("newline"));
	next_token = node->next->content;
	if (next_token->type != LEX_WORD)
		return (syntax_error_logger(next_token->value));
	return (1);
}

int	check_parentheses_syntax(t_list *prev_node, t_list *node, t_analysis *an)
{
	t_token		*token;
	t_token		*next_token;

	token = node->content;
	if (token->type == OPEN_PARENTHESIS)
	{
		(an->open_parentheses)++;
		if (!node->next)
			return (syntax_error_logger("newline"));
		next_token = node->next->content;
		if (is_binary_operator(next_token))
			return (syntax_error_logger(next_token->value));
	}
	if (token->type == CLOSE_PARENTHESIS)
	{
		(an->open_parentheses)--;
		if (!prev_node)
			return (syntax_error_logger(token->value));
	}
	if (!node->next && (an->open_parentheses) != 0)
		return (syntax_error_logger("newline"));
	return (1);
}

int	check_word_syntax(t_list *node, t_analysis *an)
{
	t_token		*token;
	int			i;

	token = node->content;
	i = -1;
	while (token->value[++i])
	{
		if (token->value[i] == '\'')
			(an->s_quotes)++;
		if (token->value[i] == '"')
			(an->d_quotes)++;
	}
	if (!node->next)
	{
		if ((an->s_quotes) % 2 != 0 || (an->d_quotes) % 2 != 0)
			return (syntax_error_logger("newline"));
	}
	return (1);
}
