/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get-output-redir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 07:50:39 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/18 09:53:05 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*extract_word(const char *s, size_t *k)
{
	size_t	j;
	size_t	i;
	char	c;

	j = 1;
	while (ft_isspace(s[j]))
		j++;
	i = j;
	if (s[j] == '"')
		c = '"';
	else if (s[j] == '\'')
		c = '\'';
	else
	{
		while (!ft_isspace(s[j]))
			j++;
		*k = j + 1;
		return (ft_substr(s, i, j - i + 1));
	}
	j++;
	while (s[j] && s[j] != c)
		j++;
	*k = j + 1;
	return (ft_substr(s, i, j - i + 1));
}

size_t	get_output_redir(t_cmd *cmd, const char *s)
{
	size_t	s_len;
	size_t	i;
	size_t	j;

	if (!cmd || !s || !*s)
		return (0);
	s_len = ft_strlen(s);
	if (s_len < 2)
		return (0);
	if (s[0] != '>')
		return (0);
	if (s[1] == '>')
	{
		cmd->out_redir = DOUBLE;
		i = 2;
	}
	else
	{
		cmd->out_redir = SINGLE;
		i = 1;
	}
	// while (ft_isspace(s[i]))
	// 	i++;
	// j = i;
	// while (!ft_isspace(s[j]) && !is_spicial(s[j]))
	// 	j++;
	// if (cmd->out)
	// 	free(cmd->out);
	cmd->out = extract_word(s, &j);
	//cmd->out = ft_substr(s, i, j - i);
	return (j);
}
