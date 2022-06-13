/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:26:15 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/12 23:23:03 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
char	*generate_error_string(const char *cmd, char *error);

int print_error(const char *cmd, char *error)
{
	char *error_str;

	error_str = generate_error_string(cmd, error);

	if (!ft_strcmp(error, USE_ERRNO))
		perror(error_str);
	else
		ft_putendl_fd(error_str, 2);
	free(error_str);
	return (1);
}

char	*generate_error_string(const char *cmd, char *error)
{
	char	*error_str;
	char	*tmp;

	tmp = ft_strjoin(PROGRAM_NAME, ": "); // tmp = "minishell: "
	error_str = ft_strjoin(tmp, cmd); // error = "minishell: cmd"
	free(tmp);
	if (*error)
	{
		tmp = ft_strjoin(error_str, ": "); // tmp = "minishell: cmd: "
		free(error_str);
		error_str = ft_strjoin(tmp, error); // error = "minishell: cmd: error_name"
	}
	return (error_str);
}