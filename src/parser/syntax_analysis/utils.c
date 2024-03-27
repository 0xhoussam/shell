/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:17:41 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/30 18:52:48 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "minishell.h"
#include "defs.h"

int	syntax_error_logger(char *token)
{
	ft_putstr_fd(PROGRAM_NAME, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd("syntax error near unexpected token `", STDERR_FILENO);
	ft_putstr_fd(token, STDERR_FILENO);
	ft_putstr_fd("'\n", STDERR_FILENO);
	g_exit_code = 2;
	return (0);
}

int	is_binary_operator(t_token *token)
{
	if (token->type == LEX_AND || token->type == LEX_OR
		|| token->type == LEX_PIPE)
		return (1);
	return (0);
}
