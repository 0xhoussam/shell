/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:14:57 by aoumouss          #+#    #+#             */
/*   Updated: 2022/07/01 14:08:38 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int			is_valid_key(char*arg, char **key);
static t_env_list	*env_list_new(char *arg, char **key_value);
static void			update_env_var(t_env_list *tmp, char *arg, char **key);
static void			env_list_insert_one(t_env_list **h, char *arg, char **key);

void	env_list_insert(t_env_list **head, t_list *args)
{
	char	**key_value;
	char	*key;
	int		ret;

	while (args)
	{
		key_value = ft_split(args->content, '=');
		ret = is_valid_key(args->content, key_value);
		if (!ret || ret == 2)
		{
			print_export_error(key_value, args->content, ret);
			g_exit_code = 1;
			free_2d_array(key_value);
			return ;
		}
		env_list_insert_one(head, args->content, key_value);
		free_2d_array(key_value);
		args = args->next;
	}
}

static void	env_list_insert_one(t_env_list **head, char *arg, char **key_value)
{
	t_env_list	*new;
	t_env_list	*tmp;

	tmp = env_list_get_node(*head, key_value[0]);
	if (tmp)
		return (update_env_var(tmp, arg, key_value));
	new = env_list_new(arg, key_value);
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

static void	update_env_var(t_env_list *tmp, char *arg, char **key_value)
{
	if (key_value[1])
	{
		free(tmp->value);
		tmp->value = ft_strdup(key_value[1]);
	}
	if (!key_value[1] && arg[ft_strlen(key_value[0])] == '=')
	{
		free(tmp->value);
		tmp->value = ft_strdup("");
	}
}

static t_env_list	*env_list_new(char *arg, char **key_value)
{
	t_env_list	*new;

	new = malloc(sizeof(t_env_list));
	if (!new)
		return (NULL);
	new->key = ft_strdup(key_value[0]);
	new->value = ft_strdup(key_value[1]);
	if (!key_value[1] && arg[ft_strlen(key_value[0])] == '=')
	{
		free(new->value);
		new->value = ft_strdup("");
	}
	new->next = NULL;
	return (new);
}

static int	is_valid_key(char *arg, char **key)
{
	int	i;

	if (!key || !arg || !key[0])
		return (0);
	i = 0;
	while (ft_isspace(arg[i]))
		i++;
	if (arg[i] == '=')
		return (2);
	if (!ft_isalpha(key[0][0]) && key[0][0] != '_')
		return (0);
	i = 1;
	while (key[0][i])
	{
		if (!ft_isalnum(key[0][i]) && key[0][i] != '_')
			return (0);
		i++;
	}
	return (1);
}
