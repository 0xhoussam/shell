/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <habouiba@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:23:46 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/02 16:28:37 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*extract_tokens_from_line(const char *line)
{
	t_list	*tokens;
	int		i;

	tokens = 0;
	i = 0;
	while (line[i])
	{
		if_helper(line, &tokens, &i);
	}
}
