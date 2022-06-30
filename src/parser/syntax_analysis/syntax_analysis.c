/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:33:20 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/30 19:19:24 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	valid_token(t_list *prev_node, t_list *node);
static int	check_binary_operators(t_list *prev_node, t_list *node);
static int	check_unary_operators(t_list *node);
static int	check_parentheses_syntax(t_list *prev_node, t_list *node);

int	syntax_analysis(t_list *tokens)
{
	t_list	*prev_token;
	t_token	*token;

	prev_token = NULL;
	while (tokens)
	{
		if (!valid_token(prev_token, tokens))
			return (0);
		prev_token = tokens;
		tokens = tokens->next;
	}
	return (1);
}

static int	valid_token(t_list *prev_node, t_list *node)
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
		ret = check_parentheses_syntax(prev_node, node);
	return (ret);
}

static int	check_binary_operators(t_list *prev_node, t_list *node)
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

static int	check_unary_operators(t_list *node)
{
	t_token	*next_token;

	if (!node->next)
		return (syntax_error_logger("newline"));
	next_token = node->next->content;
	if (next_token->type != LEX_WORD)
		return (syntax_error_logger(next_token->value));
	return (1);
}

static int	check_parentheses_syntax(t_list *prev_node, t_list *node)
{
	t_token		*token;
	t_token		*next_token;
	static int	open_parentheses = 0;

	token = node->content;
	if (token->type == OPEN_PARENTHESIS)
	{
		open_parentheses++;
		if (!node->next)
			return (syntax_error_logger("newline"));
		next_token = node->next->content;
		if (is_binary_operator(next_token))
			return (syntax_error_logger(next_token->value));
	}
	if (token->type == CLOSE_PARENTHESIS)
	{
		open_parentheses--;
		if (!prev_node)
			return (syntax_error_logger(token->value));
	}
	if (!node->next && open_parentheses)
		return (syntax_error_logger("newline"));
	if (open_parentheses < 0)
		return (syntax_error_logger(token->value));
	return (1);
}
