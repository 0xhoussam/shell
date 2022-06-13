/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:16:20 by aoumouss          #+#    #+#             */
/*   Updated: 2022/02/21 21:46:28 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 100

void	*ft_calloc(size_t count, size_t size);
int		ft_strlen_(char *str);
char	*ft_realloc(char *buffer, size_t buffer_size);
int		ft_strchr_(char *s, int c);
void	save_the_rest(char *src, char *holder);
char	*read_from_file(int fd, char *buffer, char *rest, int buffer_size);
char	*read_from_rest(int fd, char *buffer, char *rest, int buffer_size);
char	*get_line(char *buffer, char *rest, int size);
char	*get_next_line(int fd);
#endif
