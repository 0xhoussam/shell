/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:44:43 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/26 21:35:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define MAX_BUFF_SIZE 4096

static void	print_cwd(char *cwd, int std);

void	pwd(t_params *params, int print)
{
	char		*cwd;
	static char	old_pwd[MAX_BUFF_SIZE];
	int			fd;

	fd = get_redir_fd(params);
	cwd = getcwd(NULL, 0);
	if (!cwd && print)
	{
		if (!old_pwd)
		{
			print_error_no_exit("pwd", "no such file or directory");
			return (free(cwd));
		}
		else
			print_cwd(old_pwd, fd);
		return ;
	}
	else if (cwd && print)
	{
		print_cwd(cwd, fd);
		g_exit_code = 0;
	}
	ft_strlcpy(old_pwd, cwd, MAX_BUFF_SIZE);
	free(cwd);
}

static void	print_cwd(char *cwd, int std)
{
	write(std, cwd, ft_strlen(cwd));
	write(std, "\n", 1);
}
