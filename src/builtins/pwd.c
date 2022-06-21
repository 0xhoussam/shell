/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:44:43 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/21 13:11:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void pwd(t_params *params)
{
	char 		path[MAX_BUF];
	static char	*old_pwd;

	ft_bzero(path, MAX_BUF);
	old_pwd = NULL;
	if (!getcwd(path, MAX_BUF))
	{
		if (!old_pwd)
			return (print_error("pwd", "no such file or directory"));
		else
			printf("%s\n", old_pwd);
	}
	old_pwd = path;
	printf("%s\n", path);
}