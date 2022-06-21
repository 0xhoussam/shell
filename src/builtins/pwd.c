/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:44:43 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/21 16:54:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void pwd(t_params *params, int print)
{
	char 		path[MAX_BUF];
	static char	*old_pwd = NULL;

	ft_bzero(path, MAX_BUF);
	if (!getcwd(path, MAX_BUF))
	{
		if (print)
		{
			if (!old_pwd)
				return (print_error_no_exit("pwd", "no such file or directory"));
			else if (print)
				printf("%s\n", old_pwd);
		}
	}
	else {
		old_pwd = ft_strdup(path);
		if (print)
			printf("%s\n", path);
	}
}