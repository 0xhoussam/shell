/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:44:43 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/27 12:53:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define MAX_BUFF_SIZE 4096

static void	print_cwd(char *cwd, int std);

void	pwd(t_params *params)
{
	char		*cwd;
	static char	old_pwd[MAX_BUFF_SIZE];
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
	free(params->cwd);
	params->cwd = cwd;
}

static void	print_cwd(char *cwd, int std)
{
	write(std, cwd, ft_strlen(cwd));
	write(std, "\n", 1);
	g_exit_code = 0;
}
