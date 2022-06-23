/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:44:43 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/23 17:00:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_cwd(char *cwd, int std);

void pwd(t_params *params, int print)
{
	char		*cwd;
	static char	*old_pwd = NULL;
	int			write_end;

	write_end = get_redir_fd(params);
	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		if (print)
		{
			if (!old_pwd)
				return (print_error_no_exit("pwd", "no such file or directory"));
			else
				print_cwd(old_pwd, write_end);
		}
	}
	else {
		old_pwd = ft_strdup(cwd);
		if (print)
			print_cwd(cwd, write_end);
	}
}

void print_cwd(char *cwd, int std)
{
	write(std, cwd, ft_strlen(cwd));
	write(std, "\n", 1);
}
