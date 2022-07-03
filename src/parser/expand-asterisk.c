/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand-asterisk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 07:37:48 by habouiba          #+#    #+#             */
/*   Updated: 2022/07/03 16:31:53 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"

t_list	*read_dir_and_match_name(char *pattern)
{
	t_list			*filenames;
	DIR				*d;
	struct dirent	*dir;

	d = opendir(".");
	filenames = NULL;
	if (!d)
		return (NULL);
	dir = readdir(d);
	while (dir != NULL)
	{
		if (is_matched(pattern, dir->d_name))
			ft_lstadd_back(&filenames, ft_lstnew(ft_strdup(dir->d_name)));
		dir = readdir(d);
	}
	closedir(d);
	return (filenames);
}

void	normal_inc(t_list **prev, t_list **curr)
{
	*prev = *curr;
	*curr = (*curr)->next;
}

void	if_inc(t_list **prev, t_list **curr, t_list *expanded_arg)
{
	*prev = expanded_arg;
	*curr = expanded_arg->next;
}

void	_expand_asterisk(void *_cmd)
{
	t_list	*expanded_arg;
	t_list	*curr;
	t_list	*prev;
	t_cmd	*cmd;

	_expand_asterisk_init(&cmd, &_cmd, &curr, &prev);
	expanded_arg = NULL;
	while (curr)
	{
		if (check_if_expandable(curr))
		{
			expanded_arg = read_dir_and_match_name(curr->content);
			if (!expanded_arg)
				curr = curr->next;
			if (expanded_arg && !prev)
				insert_at_front(expanded_arg, curr, cmd);
			if (expanded_arg && prev)
				insert_at_any(prev, expanded_arg, curr);
			if (expanded_arg)
				if_inc(&prev, &curr, expanded_arg);
		}
		else
			normal_inc(&prev, &curr);
	}
}

void	expand_asterisk(t_list *cmds, t_env_list *lst)
{
	ft_lstiter(cmds, _expand_asterisk);
}
