/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get-args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:37:21 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/17 12:50:07 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	get_args(t_cmd *cmd, const char *s)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!cmd || !cmd->cmd_name || !s || !*s)
		return (0);
	if (s[0] == '<' || s[0] == '>' || s[0] == '&' || s[0] == '|' || s[0] == '*'
		|| s[0] == ';')
		return (0);
	if (s[0] == '"')
	{
		i++;
		while (s[i] && s[i] != '"')
			i++;
		str = ft_substr(s, 0, i + 1);
		ft_lstadd_back(&cmd->args, ft_lstnew(str));
		printf("DEBUG: '%s'", (char *)ft_lstlast(cmd->args)->content);
		return (i + 1);
	}
	if (s[0] == '\'')
	{
		i++;
		while (s[i] && s[i] != '\'')
			i++;
		str = ft_substr(s, 0, i + 1);
		ft_lstadd_back(&cmd->args, ft_lstnew(str));
		return (i + 1);
	}
	else
	{
		while (s[i] && !ft_isspace(s[i]))
		i++;
	}
	str = ft_substr(s, 0, i);
	ft_lstadd_back(&cmd->args, ft_lstnew(str));
	return (i);
}
