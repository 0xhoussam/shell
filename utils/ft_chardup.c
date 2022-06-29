#include "utils.h"

char *ft_chardup(char c)
{
    char *str;

    str = ft_calloc(2, sizeof(char));
    str[0] = c;
    str[1] = '\0';
    return (str);
}
