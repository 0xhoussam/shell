/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser-utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 11:41:59 by habouiba          #+#    #+#             */
/*   Updated: 2022/07/03 11:42:01 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parser.h"
#include "utils.h"

void	setup_matrix(char **matrix, char *pattern, char *filename, int *i)
{
	if (!matrix)
		return ;
	matrix[0][0] = 1;
	if (pattern[0] == '*')
		matrix[0][1] = 1;
	else
		matrix[0][1] = 0;
	*i = -1;
}

char	*remove_consecutive_asterisks(char *pattern)
{
	t_list	*lst;
	char	*str;
	int		i;

	i = 0;
	lst = 0;
	while (pattern[i])
	{
		if (pattern[i] == '*')
		{
			ft_lstadd_back(&lst, ft_lstnew(ft_chardup(pattern[i])));
			while (pattern[i] == '*')
				i++;
		}
		else
		{
			ft_lstadd_back(&lst, ft_lstnew(ft_chardup(pattern[i])));
			i++;
		}
	}
	str = joined_linked_list_of_strings(lst);
	ft_lstclear(&lst, free);
	return (str);
}

char	**create_matching_matrix(size_t pattern_len, size_t filename_len)
{
	char	**matrix;
	size_t	i;

	matrix = ft_calloc(filename_len + 1, sizeof(char *));
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < filename_len + 1)
	{
		matrix[i] = ft_calloc(pattern_len + 1, sizeof(char));
		i++;
	}
	return (matrix);
}

void	remove_matrix(char **matrix, size_t height)
{
	size_t	i;

	i = 0;
	while (i < height)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
