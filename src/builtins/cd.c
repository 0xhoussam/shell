/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:37:39 by habouiba          #+#    #+#             */
/*   Updated: 2022/05/31 16:50:41 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    cd(const char *dir_name)
{
	DIR *dir;

	if (!dir_name)
		return ;
	dir = opendir(dir_name);
	if (!dir)
	{
		write(2, PROGRAM_NAME, ft_strlen(PROGRAM_NAME));
		write(2, ": cd: ", strlen(": cd: "));
		perror(dir_name); // TODO: message printing twice
		return ;
	}
	chdir(dir_name);
	closedir(dir);
}