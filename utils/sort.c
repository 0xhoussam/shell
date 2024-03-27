/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:59:50 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/27 15:37:12 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	sort_strs(char **strs)
{
	int		i;
	int		j;
	size_t	len;
	char	*tmp;

	i = 0;
	while (strs[i])
	{
		j = i + 1;
		while (strs[j])
		{
			len = max_strs_len(strs[i], strs[j]);
			if (ft_strncmp(strs[i], strs[j], len) < 0)
			{
				tmp = strs[i];
				strs[i] = strs[j];
				strs[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
