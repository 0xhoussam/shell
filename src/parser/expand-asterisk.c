/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand-asterisk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <habouiba@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 07:37:48 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/26 09:21:35 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int expand_asterisk(t_list **cmds, t_cmd *cmd, char *s, t_env_list *lst)
{
    DIR           *d;
    struct dirent *dir;

    if (!s || *s != '*')
        return (0);
    d = opendir(".");
    if (!d)
        return (0);
    while ((dir = readdir(d)) != NULL)
    {
        if (dir->d_type == DT_REG)
            ft_lstadd_back(&cmd->args, ft_lstnew(ft_strdup(dir->d_name)));
    }
    closedir(d);
    recursive_parser(cmds, cmd, &s[1], lst);
    return (1);
}
