/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:14:57 by aoumouss          #+#    #+#             */
/*   Updated: 2022/07/02 16:22:42 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_key(char *key);
static void	env_list_insert_one(t_env_list **h, char *key, char *value);
static char	*get_value(char *arg, char *key);
static char	*get_key(char *arg);

void	env_list_insert(t_env_list **head, t_list *args)
{
	char	*key;
	char	*value;

	while (args)
	{
		key = get_key(args->content);
		if (!is_valid_key(key))
		{
			print_export_error(key, args->content);
			free(key);
			g_exit_code = -1;
			args = args->next;
			continue ;
		}
		value = get_value(args->content, key);
		env_list_insert_one(head, key, value);
		free(key);
		free(value);
		args = args->next;
	}
}

static void	env_list_insert_one(t_env_list **head, char *key, char *value)
{
	t_env_list	*new;
	t_env_list	*tmp;

	tmp = env_list_get_node(*head, key);
	if (tmp)
	{
		if (value)
		{
			free(tmp->value);
			tmp->value = ft_strdup(value);
		}
		return ;
	}
	new = env_list_new(key, value);
	if (!new)
		return ;
	if (!*head)
		*head = new;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

static char	*get_key(char *arg)
{
	char	*key;
	int		i;
	int		j;

	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	key = ft_substr(arg, 0, i);
	return (key);
}

static char	*get_value(char *arg, char *key)
{
	char	*value;
	int		i;

	if (ft_strlen(key) == ft_strlen(arg))
		value = NULL;
	else
		value = ft_substr(arg, ft_strlen(key) + 1, ft_strlen(arg));
	return (value);
}

static int	is_valid_key(char *key)
{
	int	i;

	i = 0;
	if (!*key || !key)
		return (0);
	if (!ft_isalpha(key[0]) && key[0] != '_')
		return (0);
	i = 1;
	while (key[i])
	{
		if (!ft_isalnum(key[i]) && key[i] != '_')
			return (0);
		i++;
	}
	return (1);
}
