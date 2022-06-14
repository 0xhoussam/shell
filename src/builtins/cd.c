/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:37:39 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/14 17:57:19 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd(t_params *params)
{
	char	**dir_name;
	DIR		*dir;

	dir_name = join_args(params->cmd);
	if (!dir_name)
		return ;
	dir = opendir(*dir_name);
	if (!dir)
	{
		write(2, PROGRAM_NAME, ft_strlen(PROGRAM_NAME));
		write(2, ": cd: ", ft_strlen(": cd: "));
		perror(*dir_name);
		return ;
	}
	chdir(*dir_name);
	closedir(dir);
}
