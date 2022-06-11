/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get-args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <habouiba@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:37:21 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/11 09:37:23 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.c"

size_t	get_args(t_cmd *cmd, const char *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!cmd->cmd_name)
		return (0);
	if (s[0] == '<' || s[0] == '>' || s[0] == '&' || s[0] == '|' || s[0] == '*')
		return (0);
	j = i;
	while (!ft_isspace(s[j]))
		j++;
	ft_lstadd_back(&cmd->args, ft_lstnew(ft_substr(s, i, j - i)));
	return (j);
}
