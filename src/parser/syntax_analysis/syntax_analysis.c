/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:33:20 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/30 16:09:42 by aoumouss         ###   ########.fr       */
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
	int		open_parentheses;

	prev_token = NULL;
	open_parentheses = 0;
	while (tokens)
	{
		token = (t_token *)tokens->content;
		if (token->type == OPEN_PARENTHESIS)
			open_parentheses++;
		else if (token->type == CLOSE_PARENTHESIS && !open_parentheses)
		{
			syntax_logger(token->value);
			return (0);
		}
		else if (token->type == CLOSE_PARENTHESIS)
			open_parentheses--;
		if (!valid_token(prev_token, tokens))
			return (0);
		prev_token = tokens;
		tokens = tokens->next;
	}
	if (open_parentheses)
	{
		syntax_logger("newline");
		return (0);
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
	if (!ret)
	{
		if (!prev_node)
			token = node->content;
		else if (node->next)
			token = node->next->content;
		if (!node->next)
			syntax_logger("newline");
		else
			syntax_logger(token->value);
	}
	return (ret);
}

static int	check_binary_operators(t_list *prev_node, t_list *node)
{
	t_token	*next_token;
	t_token	*prev_token;

	if (!node->next)
		return (0);
	if (!prev_node)
		return (0);
	next_token = node->next->content;
	prev_token = prev_node->content;
	if (prev_token->type != LEX_PIPE || prev_token->type != LEX_AND
		|| prev_token->type != LEX_OR)
		return (0);
	if (next_token->type != LEX_PIPE || next_token->type != LEX_AND
		|| next_token->type != LEX_OR)
		return (0);
	return (1);
}

static int	check_unary_operators(t_list *node)
{
	t_token	*next_token;

	if (!node->next)
		return (0);
	next_token = node->next->content;
	if (next_token->type != LEX_WORD)
		return (0);
	return (1);
}

static int	check_parentheses_syntax(t_list *prev_node, t_list *node)
{
	t_token	*next_token;
	t_token	*prev_token;
	t_token	*token;

	token = node->content;
	if (token->type == OPEN_PARENTHESIS)
	{
		if (!node->next)
			return (0);
		next_token = node->next->content;
		if (next_token->type == LEX_PIPE || next_token->type == LEX_AND
			|| next_token->type == LEX_OR)
			return (0);
		return (1);
	}
	prev_token = prev_node->content;
	if (!prev_node && token->type == CLOSE_PARENTHESIS)
		return (0);
	return (1);
}
