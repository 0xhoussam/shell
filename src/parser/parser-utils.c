#include "parser.h"

char *extract_word(const char *s, size_t *k, int start)
{
    size_t j;
    size_t i;
    char   c;

    j = start;
    while (s[j] && ft_isspace(s[j]))
        j++;
    i = j;
    if (s[j] == '"')
        c = '"';
    else if (s[j] == '\'')
        c = '\'';
    else
    {
        while (s[j] && !ft_isspace(s[j]))
            j++;
        if (s[j])
            *k = j + 1;
        else
            *k = j;
        return (ft_substr(s, i, j - i));
    }
    j++;
    while (s[j] && s[j] != c)
        j++;
    if (s[j])
        *k = j + 1;
    else
        *k = j;
    return (ft_substr(s, i, j - i + 1));
}

int is_matched(char *s_wildcard, char *filename)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (s_wildcard[i] && filename[j])
    {
        if (s_wildcard[i] == '*')
        {
            i++;
            while (filename[j] && filename[j] != s_wildcard[i])
                j++;
        }
        if (s_wildcard[i] != filename[j])
            break;
        i++;
        j++;
    }
    if (s_wildcard[i] == filename[j])
        return (1);
    return (0);
}
