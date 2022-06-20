#include "parser.h"

char	*extract_word(const char *s, size_t *k)
{
	size_t	j;
	size_t	i;
	char	c;

	j = 1;
	while (ft_isspace(s[j]))
		j++;
	i = j;
	if (s[j] == '"')
		c = '"';
	else if (s[j] == '\'')
		c = '\'';
	else
	{
		while (!ft_isspace(s[j]))
			j++;
		*k = j + 1;
		return (ft_substr(s, i, j - i + 1));
	}
	j++;
	while (s[j] && s[j] != c)
		j++;
	*k = j + 1;
	return (ft_substr(s, i, j - i + 1));
}
