/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:44:43 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/25 16:23:10 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_cwd(char *cwd, int std);

void	pwd(t_params *params, int print)
{
	char		*cwd;
	static char	*old_pwd = NULL;
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
	}
	else if (cwd && print)
	{
		print_cwd(cwd, fd);
		g_exit_code = 0;
	}
	old_pwd = ft_strdup(cwd);
	free(cwd);
}

void	print_cwd(char *cwd, int std)
{
	write(std, cwd, ft_strlen(cwd));
	write(std, "\n", 1);
}
