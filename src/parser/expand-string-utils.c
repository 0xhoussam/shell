/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand-string-utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 12:49:21 by habouiba          #+#    #+#             */
/*   Updated: 2022/07/04 18:41:40 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parser.h"

char	*joined_linked_list_of_strings(t_list *lst)
{
	char	*joined;
	char	*tmp;
	t_list	*curr;

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

char	*expand_string(char *s, t_env_list *env)
{
	char	*key;
	char	*joined;
	size_t	i;
	t_list	*lst;

	i = 0;
	lst = NULL;
	while (s[i])
	{
		if (s[i] == '$')
		{
			key = get_var_key(&s[i + 1]);
			add_appropriate_val_v2(key, env, &lst);
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

char	*get_var_key(char *s)
{
	size_t	i;
	char	*key;

	i = 0;
	while (s[i] && !ft_includes("\"'$", s[i]) && !ft_isspace(s[i]))
		i++;
	key = ft_substr(s, 0, i);
	return (key);
}

char	*get_double_quotes(char *s, t_env_list *env)
{
	size_t	i;
	char	*word;
	char	*expanded;

	i = 0;
	while (s[i] && s[i] != '"')
		i++;
	word = ft_substr(s, 0, i);
	expanded = expand(word, env);
	free(word);
	return (expanded);
}
