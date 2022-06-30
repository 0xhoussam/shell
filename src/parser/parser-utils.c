#include "parser.h"
#include "utils.h"

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
    while (s[j] && !ft_isspace(s[j]))
        j++;
    if (s[j])
        *k = j + 1;
    else
        *k = j;
    return (ft_substr(s, i, j - i));
}

int is_matched(char *_pattern, char *filename)
{
    char  *pattern;
    char **matrix;
    size_t i;
    size_t j;

    pattern = remove_consecutive_asterisks(_pattern);
    matrix = create_matching_matrix(ft_strlen(pattern), ft_strlen(filename));
    setup_matrix(matrix, pattern, filename);
    i = 0;
    while (filename[i])
    {
        j = 0;
        while (pattern[j])
        {
            if (pattern[j] == filename[i] || pattern[j] == '?')
                matrix[i + 1][j + 1] = matrix[i][j];
            else if (pattern[j] == '*')
            {
                if (matrix[i][j + 1] || matrix[i + 1][j])
                    matrix[i + 1][j + 1] = 1;
                else
                    matrix[i + 1][j + 1] = 0;
            }
            j++;
        }
        i++;
    }
    i = matrix[ft_strlen(filename)][ft_strlen(pattern)];
    remove_matrix(matrix, ft_strlen(filename) + 1);
    free(pattern);
    return (i);
}

void setup_matrix(char **matrix, char *pattern, char *filename)
{
    if (!matrix)
        return;
    matrix[0][0] = 1;
    if (pattern[0] == '*')
        matrix[0][1] = 1;
    else
        matrix[0][1] = 0;
}

char *remove_consecutive_asterisks(char *pattern)
{
    t_list *lst;
    char   *str;
    int     i;

    i = 0;
    lst = 0;
    while (pattern[i])
    {
        if (pattern[i] == '*')
        {
            ft_lstadd_back(&lst, ft_lstnew(ft_chardup(pattern[i])));
            while (pattern[i] == '*')
                i++;
        }
        else
        {
            ft_lstadd_back(&lst, ft_lstnew(ft_chardup(pattern[i])));
            i++;
        }
    }
    str = joined_linked_list_of_strings(lst);
    ft_lstclear(&lst, free);
    return (str);
}

char **create_matching_matrix(size_t pattern_len, size_t filename_len)
{
    char **matrix;
    size_t i;

    matrix = ft_calloc(filename_len + 1, sizeof(char *));
    if (!matrix)
        return (NULL);
    i = 0;
    while (i < filename_len + 1)
    {
        matrix[i] = ft_calloc(pattern_len + 1, sizeof(char));
        i++;
    }
    return (matrix); // todo:: handle null returned
}

void remove_matrix(char **matrix, size_t height)
{
    size_t i;

    i = 0;
    while (i < height)
    {
        free(matrix[i]);
        i++;
    }
    free(matrix);
}
