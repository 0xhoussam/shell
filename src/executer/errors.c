/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:26:15 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/11 18:39:42 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int print_error(char *cmd, char *error)
{
	char *error_str;

	error_str = generate_error_string(cmd, error);

	if (!ft_strcmp(error, USE_ERRNO))
		perror(error_str);
	else
		ft_putendl_fd(error_str, 2);
	return (1);
}

char	*generate_error_string(char *cmd, char *error)
{
	char	*error;
	char	*tmp;

	tmp = ft_strjoin(PROGRAM_NAME, ": "); // tmp = "minishell: "
	error = ft_strjoin(tmp, cmd); // error = "minishell: cmd"
	free(tmp);
	tmp = ft_strjoin(error, ": "); // tmp = "minishell: cmd: "
	free(error);
	error = ft_strjoin(tmp, error); // error = "minishell: cmd: error"
	free(tmp);
	return (error);
}