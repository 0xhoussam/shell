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
    return (ft_substr(s, i, j - i));
}
