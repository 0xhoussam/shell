/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:26:15 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/25 13:37:03 by aoumouss         ###   ########.fr       */
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
	exit (1);
}

void	print_error_no_exit(const char *cmd, char *error)
{
	char	*error_str;

	error_str = generate_error_string(cmd, error);
	if (!ft_strcmp(error, USE_ERRNO))
	{
		perror(error_str);
		if (errno == 13)
			g_exit_code = PERMISSION_DENIED_ERRNO;
		g_exit_code = 1;
	}
	else
		ft_putendl_fd(error_str, 2);
	if (!ft_strcmp(error, CMD_NOT_FOUND))
		g_exit_code = CMD_NOT_FOUND_ERRNO;
	free(error_str);
	g_exit_code = 1;
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
		free(tmp);
	}
	return (error_str);
}
