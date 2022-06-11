/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get-cmd-name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 07:08:42 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/11 07:08:45 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

size_t	get_cmd_name(t_cmd *cmd, char const *s)
{
	size_t	i;

	if (cmd->cmd_name)
		return (0);
	i = 0;
	while (ft_isalpha(s[i]))
		i++;
	cmd->cmd_name = ft_substr(s, 0, i);
	return (i);
}