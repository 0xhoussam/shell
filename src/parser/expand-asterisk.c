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
#include "utils.h"

// int expand_asterisk(t_list **cmds, t_cmd *cmd, char *s, t_env_list *lst)
// {
//     DIR           *d;
//     struct dirent *dir;

//     if (!s || *s != '*')
//         return (0);
//     d = opendir(".");
//     if (!d)
//         return (0);
//     while ((dir = readdir(d)) != NULL)
//     {
//         if (dir->d_type == DT_REG)
//             ft_lstadd_back(&cmd->args, ft_lstnew(ft_strdup(dir->d_name)));
//     }
//     closedir(d);
//     recursive_parser(cmds, cmd, &s[1], lst);
//     return (1);
// }

t_list *read_dir_and_match_name(char *pattern)
{
    t_list        *filenames;
    DIR           *d;
    struct dirent *dir;

    d = opendir(".");
    filenames = NULL;
    if (!d)
        return (NULL);
    while ((dir = readdir(d)) != NULL)
        if (dir->d_type == DT_REG && is_matched(pattern, dir->d_name))
            ft_lstadd_back(&filenames, ft_lstnew(ft_strdup(dir->d_name)));
    return (filenames);
}

void _expand_asterisk(void *_cmd)
{
    t_list *expanded_arg;
    t_list *curr;
    t_list *prev;
    t_cmd  *cmd;

    cmd = (t_cmd *)_cmd;
    expanded_arg = NULL;
    prev = NULL;
    curr = cmd->args;
    while (curr)
    {
        if (ft_includes(curr->content, '*') &&
            !ft_includes(curr->content, '"') &&
            !ft_includes(curr->content, '\''))
        {
            expanded_arg = read_dir_and_match_name(curr->content);
            if (!expanded_arg)
            {
                curr = curr->next;
                continue;
            }
            if (!prev)
            {
                ft_lstlast(expanded_arg)->next = curr->next;
                cmd->args = expanded_arg;
                free(curr->content);
                free(curr);
            }
            else
            {
                prev->next = expanded_arg;
                if (curr->next)
                    expanded_arg->next = ft_lstlast(curr);
                free(curr->content);
                free(curr);
            }
            prev = expanded_arg;
            curr = expanded_arg->next;
            continue;
        }
        prev = curr;
        curr = curr->next;
    }
}

void expand_asterisk(t_list *cmds, t_env_list *lst)
{
    ft_lstiter(cmds, _expand_asterisk);
}
