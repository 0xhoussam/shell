/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <habouiba@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:23:46 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/06 09:27:55 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*extract_tokens_from_line(const char *line)
{
	t_list	*tokens;
	int			i;
	char 		**keywords = ft_split(KEYWORDS, ' ');
	char 		**punctuations = ft_split(PUNCTUATIONS, ' ');
	char 		**operators = ft_split(OPERATORS, ' ');
	int			j;

	tokens = 0;
	i = 0;
	while (line[i])
	{
		j = 0;
		while (keywords[j])
		{
			if_helper(line, &tokens, &i, keywords[j]);
			j++;
		}
		j = 0;
		while (punctuations[j])
		{
			if_helper(line, &tokens, &i, punctuations[j]);
			j++;
		}
		j = 0;
		while (operators[j])
		{
			if_helper(line, &tokens, &i, operators[j]);
			j++;
		}
		while (ft_isspace(line[i]))
			i++;
	}
	array_2d_free(keywords);
	array_2d_free(punctuations);
	array_2d_free(operators);
	return (tokens);
}
