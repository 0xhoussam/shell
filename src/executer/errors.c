/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:26:15 by aoumouss          #+#    #+#             */
/*   Updated: 2022/07/02 16:21:52 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "utils.h"
#include "defs.h"
#include <errno.h>

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
		ft_putendl_fd(error_str, STDERR_FILENO);
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
		ft_putendl_fd(error_str, STDERR_FILENO);
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

void	print_export_error(char *key, char *arg)
{
	ft_putstr_fd(PROGRAM_NAME, STDERR_FILENO);
	ft_putstr_fd(": export: ", STDERR_FILENO);
	ft_putstr_fd("`", STDERR_FILENO);
	if (!*key)
		ft_putstr_fd(arg, STDERR_FILENO);
	else
		ft_putstr_fd(key, STDERR_FILENO);
	ft_putstr_fd("': is not a valid identifier\n", STDERR_FILENO);
}
