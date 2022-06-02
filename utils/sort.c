/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <habouiba@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:59:50 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/01 10:59:50 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	replacing_underscore(char **strs);
static void	replacing_underscore2(char **strs);

void    sort_strs(char **strs)
{
	int		i;
	int		j;
	size_t	len;
	char	*tmp;

	i = 0;
	//replacing_underscore(strs);
	while (strs[i])
	{
		j = i + 1;
		while (strs[j])
		{
			len = max_strs_len(strs[i], strs[j]);
			if (ft_strncmp(strs[i], strs[j], len) > 0)
			{
				tmp = strs[i];
				strs[i] = strs[j];
				strs[j] = tmp;
			}
			j++;
		}
		i++;
	}
	//replacing_underscore2(strs);
}

// static void	replacing_underscore(char **strs)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (strs[i])
// 	{
// 		j = 0;
// 		while (strs[i][j] && strs[i][j] == '_')
// 		{
// 			strs[i][j] = 126;
// 			j++;
// 		}
// 		i++;
// 	}
// }
// static void	replacing_underscore2(char **strs)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (strs[i])
// 	{
// 		j = 0;
// 		while (strs[i][j] && strs[i][j] == 126)
// 		{
// 			strs[i][j] = '_';
// 			j++;
// 		}
// 		i++;
// 	}
// }