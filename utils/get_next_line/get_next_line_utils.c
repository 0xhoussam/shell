/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 20:41:36 by aoumouss          #+#    #+#             */
/*   Updated: 2022/02/22 00:47:17 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

int	ft_strchr_(char *s, int c)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen_(s);
	while (i <= len)
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}

void	save_the_rest(char *src, char *holder)
{
	int	i;
	int	j;

	if (!src)
		return ;
	i = 1;
	j = 0;
	if (src[j])
		holder[0] = 'T';
	while (src[j] != '\0')
	{
		holder[i] = src[j];
		i++;
		j++;
	}
	holder[i] = src[j];
}

char	*ft_realloc(char *buffer, size_t buffer_size)
{	
	char	*new_buffer;
	int		i;

	new_buffer = ft_calloc(sizeof(char), buffer_size + 1);
	i = 0;
	while (buffer[i])
	{
		new_buffer[i] = buffer[i];
		i++;
	}
	new_buffer[i] = '\0';
	free(buffer);
	return (new_buffer);
}
