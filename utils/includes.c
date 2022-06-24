/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:11:54 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/24 14:40:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int ft_includes(const char *s, int c)
{
	int i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
			return (1);
	}
	if (s[i] == c)
		return (1);
	return (0);
}

int	ft_includes_str(char *haystack, char *needle)
{
	int 	i;
	char	**strs;

	i = 0;
	if (!haystack || !needle)
		return (0);
	strs = ft_split(haystack, ' ');
	if (!strs)
		return (0);
	while (strs[i])
	{
		if (!ft_strcmp(strs[i], needle))
			return (1);
		i++;
	}
	free_2d_array(strs);
	return (0);
}