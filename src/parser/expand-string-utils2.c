/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand-string-utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:26:04 by habouiba          #+#    #+#             */
/*   Updated: 2022/07/03 16:27:26 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parser.h"

char	*get_single_quotes(char *s)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (s[i] && s[i] != '\'')
		i++;
	tmp = ft_substr(s, 0, i);
	return (tmp);
}

void	expand_if_single(char *s, t_list **splits, size_t *i)
{
	ft_lstadd_back(splits, ft_lstnew(get_single_quotes(&s[*i + 1])));
	(*i)++;
	while (s[*i] && s[*i] != '\'')
		(*i)++;
	if (s[*i] == '\'')
		(*i)++;
}

void	expand_if_double(char *s, t_list **splits, size_t *i, t_env_list *env)
{
	ft_lstadd_back(splits,
		ft_lstnew(get_double_quotes(&s[*i + 1], env)));
	(*i)++;
	while (s[*i] && s[*i] != '"')
		(*i)++;
	if (s[*i] == '"')
		(*i)++;
}

void	expand_if_dollar(char *s, t_list **splits, t_env_list *env, size_t *i)
{
	char	*key;

	key = get_var_key(&s[*i + 1]);
	add_appropriate_val_v2(key, env, splits);
	*i = *i + ft_strlen(key) + 1;
	free(key);
}

char	*expand_ret(t_list **splits)
{
	char	*expanded;

	expanded = joined_linked_list_of_strings(*splits);
	ft_lstclear(splits, free);
	return (expanded);
}
