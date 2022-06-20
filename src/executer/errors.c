/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:26:15 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/20 18:04:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*generate_error_string(const char *cmd, char *error);

void	print_error(const char *cmd, char *error)
{
	char	*error_str;

	error_str = generate_error_string(cmd, error);
	if (!ft_strcmp(error, USE_ERRNO))
	{
		perror(error_str);
		if (errno == 13)
			exit(PERMISSION_DENIED_ERRNO);
		exit(1);
	}
	else
		ft_putendl_fd(error_str, 2);
	if (!ft_strcmp(error, CMD_NOT_FOUND))
		exit(CMD_NOT_FOUND_ERRNO);
	free(error_str);
	exit (0);
}

char	*generate_error_string(const char *cmd, char *error)
{
	char	*error_str;
	char	*tmp;

	tmp = ft_strjoin(PROGRAM_NAME, ": ");
	error_str = ft_strjoin(tmp, cmd);
	free(tmp);
	if (*error)
	{
		tmp = ft_strjoin(error_str, ": ");
		free(error_str);
		error_str = ft_strjoin(tmp, error);
	}
	return (error_str);
}
