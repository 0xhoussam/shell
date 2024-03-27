/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:57:54 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/30 15:30:10 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token	*create_token(t_token_type type, char *value)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	token->type = type;
	token->value = value;
	return (token);
}

void	free_token(void *token)
{
	t_token	*t;

	t = (t_token *)token;
	free(t->value);
	free(t);
}
