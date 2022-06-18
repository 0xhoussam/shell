/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand-asterisk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <habouiba@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 07:37:48 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/18 08:59:50 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

size_t	expand_asterisk(t_cmd *cmd, const char *s)
{
	DIR	*d;
	struct dirent *dir;

	if (!s || *s != '*')
		return (0);
	d = opendir(".");
	if (!d)
		return (0);
	while ((dir = readdir(d)) != NULL)
	{
		if (dir->d_type  == DT_REG)
			ft_lstadd_back(&cmd->args, ft_lstnew(ft_strdup(dir->d_name)));
	}
	closedir(d);
	return (1);
}
