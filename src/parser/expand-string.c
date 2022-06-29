/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand-string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:46:44 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/26 06:46:22 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "types.h"
#include "utils.h"

void evaluate_str_and_var(t_list *cmds, t_env_list *env)
{
    t_cmd  *cmd;
    t_list *var;
    char   *tmp;

    while (cmds)
    {
        cmd = cmds->content;
        tmp = cmd->cmd_name;
        cmd->cmd_name = expand(cmd->cmd_name, env);
        free(tmp);
        var = cmd->args;
        while (var)
        {
            tmp = var->content;
            var->content = expand(var->content, env);
            free(tmp);
            var = var->next;
        }
        tmp = cmd->in;
        cmd->in = expand(cmd->in, env);
        free(tmp);
        tmp = cmd->out;
        cmd->out = expand(cmd->out, env);
        free(tmp);
        var = cmd->heredoc_del;
        while (var)
        {
            tmp = var->content;
            var->content = expand(var->content, env);
            free(tmp);
            var = var->next;
        }
        cmds = cmds->next;
    }
}

char *joined_linked_list_of_strings(t_list *lst)
{
    char   *joined;
    char   *tmp;
    t_list *curr;

    curr = lst;
    joined = ft_strdup("");
    while (curr)
    {
        tmp = ft_strjoin(joined, curr->content);
        free(joined);
        joined = tmp;
        curr = curr->next;
    }
    return (joined);
}

char *expand_string(char *s, t_env_list *env)
{
    char   *key;
    char   *joined;
    size_t  i;
    t_list *lst;

    i = 0;
    lst = NULL;
    while (s[i])
    {
        if (s[i] == '$')
        {
            key = get_var_key(&s[i + 1]);
            if (env_list_get(env, key))
            {
                ft_lstadd_back(&lst,
                               ft_lstnew(ft_strdup(env_list_get(env, key))));
            }
            i += ft_strlen(key) + 1;
            free(key);
        }
        else
        {
            ft_lstadd_back(&lst, ft_lstnew(ft_chardup(s[i])));
            i++;
        }
    }
    joined = joined_linked_list_of_strings(lst);
    ft_lstclear(&lst, free);
    return (joined);
}

char *get_var_key(char *s)
{
    size_t i;
    char  *key;

    i = 0;
    while (s[i] && !ft_includes("\"'$", s[i]) && !ft_isspace(s[i]))
        i++;
    key = ft_substr(s, 0, i);
    return (key);
}

char *get_double_quotes(char *s, t_env_list *env)
{
    size_t i;
    char  *word;
    char  *expanded;

    i = 0;
    while (s[i] && s[i] != '"')
        i++;
    word = ft_substr(s, 0, i);
    expanded = expand_string(word, env);
    free(word);
    return (expanded);
}

char *get_single_quotes(char *s)
{
    size_t i;

    i = 0;
    while (s[i] && s[i] != '\'')
        i++;
    return (ft_substr(s, 0, i));
}
char *expand(char *s, t_env_list *env)
{
    size_t  i;
    char   *expanded;
    char   *key;
    char   *tmp;
    t_list *splits;

    i = 0;
    // expanded = ft_strdup("");
    if (!s)
        return (NULL);
    splits = NULL;
    while (s[i])
    {
        if (s[i] == '$')
        {
            key = get_var_key(&s[i + 1]);
            if (env_list_get(env, key))
            {
                ft_lstadd_back(&splits,
                               ft_lstnew(ft_strdup(env_list_get(env, key))));
            }
            free(key);
            i += ft_strlen(key);
        }
        else if (s[i] == '"')
        {
            ft_lstadd_back(&splits,
                           ft_lstnew(get_double_quotes(&s[i + 1], env)));
            i++;
            while (s[i] && s[i] != '"')
                i++;
            if (s[i] == '"')
                i++;
        }
        else if (s[i] == '\'')
        {
            ft_lstadd_back(&splits, ft_lstnew(get_single_quotes(&s[i + 1])));
            i++;
            while (s[i] && s[i] != '\'')
                i++;
            if (s[i] == '\'')
                i++;
            printf("'%c'\n", s[i]);
        }
        else
        {
            ft_lstadd_back(&splits, ft_lstnew(ft_chardup(s[i])));
            i++;
        }
    }
    expanded = joined_linked_list_of_strings(splits);
    return (expanded);
}
