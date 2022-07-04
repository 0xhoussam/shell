/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand-string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:46:44 by habouiba          #+#    #+#             */
/*   Updated: 2022/07/03 16:27:40 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "types.h"
#include "utils.h"
#include "minishell.h"

void	_replace_value(char **old_val, t_env_list *env)
{
	void	*tmp;

	tmp = *old_val;
	*old_val = expand(*old_val, env);
	free(tmp);
}

void	evaluate_str_and_var(t_list *cmds, t_env_list *env)
{
	t_cmd	*cmd;
	t_list	*var;
	char	*tmp;

	while (cmds)
	{
		cmd = cmds->content;
		_replace_value(&cmd->cmd_name, env);
		var = cmd->args;
		while (var)
		{
			_replace_value((char **)&var->content, env);
			var = var->next;
		}
		_replace_value(&cmd->in, env);
		_replace_value(&cmd->out, env);
		var = cmd->heredoc_del;
		while (var)
		{
			_replace_value((char **)&var->content, env);
			var = var->next;
		}
		cmds = cmds->next;
	}
}

void	_add_appropriate_val(char *key, t_env_list *env, t_list **lst)
{
	char	**splits;
	size_t	i;

	splits = ft_split(env_list_get(env, key), ' ');
	if (!splits || !*splits || !**splits)
		return ;
	i = 0;
	while (i[splits])
	{
		ft_lstadd_back(lst, ft_lstnew(splits[i]));
		i++;
		if (i[splits])
			ft_lstadd_back(lst, ft_lstnew(ft_chardup(' ')));
	}
	free(splits);
}

void	add_appropriate_val_v2(char *key, t_env_list *env, t_list **lst)
{
	char	*tmp;

	if (ft_isalpha(key[0]) || key[0] == '_')
	{
		if (env_list_get(env, key))
			ft_lstadd_back(lst, ft_lstnew(ft_strdup(env_list_get(env, key))));
		else
		{
			ft_lstadd_back(lst, ft_lstnew(ft_strdup("")));
		}
	}
	else
	{
		if (key[0] == '?')
			ft_lstadd_back(lst, ft_lstnew(ft_itoa(g_exit_code)));
		else if (!*key)
			ft_lstadd_back(lst, ft_lstnew(ft_chardup('$')));
		else
			ft_lstadd_back(lst, ft_lstnew(ft_substr(key, 1, -1)));
	}
}

char	*expand(char *s, t_env_list *env)
{
	size_t	i;
	char	*tmp;
	t_list	*splits;

	i = 0;
	if (!s)
		return (NULL);
	splits = NULL;
	while (s[i])
	{
		if (s[i] == '$' && ft_strlen(&s[i]) > 1)
			expand_if_dollar(s, &splits, env, &i);
		else if (s[i] == '"')
			expand_if_double(s, &splits, &i, env);
		else if (s[i] == '\'')
			expand_if_single(s, &splits, &i);
		else
		{
			ft_lstadd_back(&splits, ft_lstnew(ft_chardup(s[i])));
			i++;
		}
	}
	return (expand_ret(&splits));
}
