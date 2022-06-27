/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:44:43 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/27 22:50:51 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_cwd(char *cwd, int std);

void	pwd(t_params *params)
{
	char		*cwd;
	int			fd;

	fd = get_redir_fd(params);
	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		if (!params->cwd)
			return (print_error_no_exit("pwd", USE_ERRNO));
		else
			return (print_cwd(params->cwd, fd));
	}
	print_cwd(cwd, fd);
	free(cwd);
}

static void	print_cwd(char *cwd, int std)
{
	write(std, cwd, ft_strlen(cwd));
	write(std, "\n", 1);
	g_exit_code = 0;
}
