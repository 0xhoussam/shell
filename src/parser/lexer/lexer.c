/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:54:05 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/30 15:44:18 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*lexer(char *line)
{
	t_list	*tokens;
	int		i;

	i = 0;
	tokens = NULL;
	while (line[i])
	{
		check_pipe(&tokens, line, &i);
		check_redir(&tokens, line, &i);
		check_word(&tokens, line, &i);
		check_and_or(&tokens, line, &i);
		check_parentheses(&tokens, line, &i);
		while (line[i] && ft_isspace(line[i]))
			i++;
	}
	return (tokens);
}
