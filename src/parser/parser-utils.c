/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser-utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 11:20:49 by habouiba          #+#    #+#             */
/*   Updated: 2022/07/04 18:40:03 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parser.h"

char	*handle_no_quotes(const char *s, int j, size_t *k)
{
	size_t	i;

	i = j;
	while (s[j] && !ft_isspace(s[j]))
	{
		if (s[j] == '"')
			while (s[++j] && s[j] != '"')
				;
		if (s[j] == '\'')
			while (s[++j] && s[j] != '\'')
				;
		j++;
	}
	if (s[j])
		*k = j + 1;
	else
		*k = j;
	return (ft_substr(s, i, j - i));
}

// char	*extract_word(const char *s, size_t *k, int start)
// {
// 	size_t	j;
// 	size_t	i;
// 	char	c;

// 	j = start;
// 	while (s[j] && ft_isspace(s[j]))
// 		j++;
// 	i = j;
// 	if (s[j] == '"')
// 		c = '"';
// 	else if (s[j] == '\'')
// 		c = '\'';
// 	else
// 		return (handle_no_quotes(s, j, k));
// 	j++;
// 	while (s[j] && s[j] != c)
// 		j++;
// 	while (s[j] && !ft_isspace(s[j]))
// 		j++;
// 	if (s[j])
// 		*k = j + 1;
// 	else
// 		*k = j;
// 	return (ft_substr(s, i, j - i));
// }

char	*extract_word(const char *s, size_t *k, int start)
{
	size_t	j;
	size_t	i;

	j = start;
	while (s[j] && ft_isspace(s[j]))
		j++;
	i = j;
	while (s[j] && !is_special(s[j]) && !ft_isspace(s[j]))
	{
		if (s[j] == '"')
			while (s[++j] && s[j] != '"')
				;
		if (s[j] == '\'')
			while (s[++j] && s[j] != '\'')
				;
		j++;
	}
	*k = j;
	return (ft_substr(s, i, j - i));
}

int	is_matched_ret(char **matrix, char *pattern, char *filename)
{
	int	i;

	i = matrix[ft_strlen(filename)][ft_strlen(pattern)];
	remove_matrix(matrix, ft_strlen(filename) + 1);
	free(pattern);
	return (i);
}

int	is_matched(char *_pattern, char *filename)
{
	char	*pattern;
	char	**matrix;
	int		i;
	int		j;

	pattern = remove_consecutive_asterisks(_pattern);
	matrix = create_matching_matrix(ft_strlen(pattern), ft_strlen(filename));
	setup_matrix(matrix, pattern, &i);
	while (filename[++i])
	{
		j = -1;
		while (pattern[++j])
		{
			if (pattern[j] == filename[i] || pattern[j] == '?')
				matrix[i + 1][j + 1] = matrix[i][j];
			else if (pattern[j] == '*')
			{
				if (matrix[i][j + 1] || matrix[i + 1][j])
					matrix[i + 1][j + 1] = 1;
				else
					matrix[i + 1][j + 1] = 0;
			}
		}
	}
	return (is_matched_ret(matrix, pattern, filename));
}
