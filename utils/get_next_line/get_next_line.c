/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:52:00 by aoumouss          #+#    #+#             */
/*   Updated: 2022/02/21 21:46:48 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	rest[BUFFER_SIZE + 2];

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (rest[0])
		return (read_from_rest(fd, buffer, rest, BUFFER_SIZE));
	return (read_from_file(fd, buffer, rest, BUFFER_SIZE));
}

char	*read_from_file(int fd, char *buffer, char *rest, int buffer_size)
{
	int		ret;
	int		size;

	ret = 1;
	size = ft_strlen_(buffer);
	while (ret)
	{	
		buffer = ft_realloc(buffer, size + buffer_size);
		ret = read(fd, buffer + size, buffer_size);
		if (ret < 0)
		{
			free(buffer);
			return (NULL);
		}
		if (ret == 0 && !ft_strlen_(buffer))
		{	
			free(buffer);
			return (NULL);
		}
		size += buffer_size;
		buffer[size] = '\0';
		if (ft_strchr_(buffer, '\n') >= 0)
			break ;
	}
	return (get_line(buffer, rest, size));
}

char	*read_from_rest(int fd, char *buffer, char *rest, int buffer_size)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i < buffer_size + 2)
	{
		if (rest[i])
		{
			buffer[j] = rest[i];
			rest[i] = 0;
			if (buffer[j] == '\n')
				return (get_line(buffer, rest, buffer_size));
			j++;
			buffer[j] = 0;
		}
		i++;
		if (i == buffer_size)
			rest[0] = 0;
	}
	return (read_from_file(fd, buffer, rest, buffer_size));
}

char	*get_line(char *buffer, char *rest, int size)
{
	char	*line;
	int		i;

	line = ft_calloc(sizeof(char), size + 1);
	i = 0;
	while (buffer[i])
	{
		line[i] = buffer[i];
		if (line[i] == '\n')
			break ;
		i++;
	}
	i = ft_strchr_(buffer, '\n') + 1;
	if (i > 0)
		save_the_rest(buffer + i, rest);
	free(buffer);
	return (line);
}
