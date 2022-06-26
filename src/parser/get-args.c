/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get-args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:37:21 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/26 09:17:37 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int get_args(t_list **cmds, t_cmd *cmd, char *s, t_env_list *lst)
{
    size_t i;
    char  *str;

    i = 0;
    if (!cmd || !cmd->cmd_name || !s || !*s)
        return (0);
    if (s[0] == '<' || s[0] == '>' || s[0] == '&' || s[0] == '|' ||
        s[0] == '*' || s[0] == ';')
        return (0);
    str = extract_word(s, &i, 0);
    if (!*str)
    {
        free(str);
        return (1);
    }
    else
        ft_lstadd_back(&cmd->args, ft_lstnew(str));
    recursive_parser(cmds, cmd, &s[i], lst);
    return (1);
}
