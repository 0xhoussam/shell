/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand-string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:46:44 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/18 17:50:24 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "types.h"
#include "utils.h"
#include <stdio.h>

// ""
// ''
// $

static char *ft_chardump(int c)
{
    char *str;

    str = malloc(sizeof(char) * 2);
    if (!str)
        return (NULL);
    str[0] = c;
    str[1] = '\0';
    return (str);
}

char *expand(const char **str, t_env_list *env)
{
    int i;

    i = 0;
    while (str[i])
    {
    }
    return (NULL);
}

char *join_3_strings(char *s1, char *s2, char *s3)
{
    size_t len;
    size_t i;
    size_t j;
    char  *str;

    len = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
    str = malloc(len + 1);
    if (!str)
        return (NULL);
    i = 0;
    j = 0;
    while (s1[j])
    {
        str[i] = s1[j];
        i++;
        j++;
    }
    j = 0;
    while (s2[j])
    {
        str[i] = s2[j];
        i++;
        j++;
    }
    j = 0;
    while (s3[j])
    {
        str[i] = s3[j];
        j++;
        i++;
    }
    str[i] = '\0';
    free(s1);
    free(s3);
    return (str);
}

char *_expand(const char *s, t_env_list *env)
{
    size_t i;
    size_t j;
    char  *key;
    char  *joined;
    char  *tmp;

    if (!s || *s != '"')
        return (NULL);
    i = 0;
    joined = ft_strdup(s);
    while (joined[i])
    {
        if (joined[i] != '$')
        {
            i++;
            continue;
        }
        j = 0;
        while (joined[i + j] && !ft_isspace(joined[i + j]) &&
               joined[i + j] != '"')
            j++;
        key = ft_substr(joined, i + 1, j - 1);
        tmp = join_3_strings(ft_substr(joined, 0, i), env_list_get(env, key),
                             ft_substr(joined, i + j, -1));
        free(joined);
        free(key);
        joined = tmp;
        i = 0;
    }
    return (joined);
}
