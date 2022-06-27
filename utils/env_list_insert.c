/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:14:57 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/27 15:37:03 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int			is_valid_key(char *key);
static t_env_list	*env_list_new(char *arg, char **key_value);
static void			update_env_var(t_env_list *tmp, char *arg, char **key);
static void			env_list_insert_one(t_env_list **head, char *arg);

void	env_list_insert(t_env_list **head, t_list *args)
{
	while (args)
	{
		env_list_insert_one(head, args->content);
		args = args->next;
	}
}

static void	env_list_insert_one(t_env_list **head, char *arg)
{
	t_env_list	*new;
	t_env_list	*tmp;
	char		**key_value;

	key_value = ft_split(arg, '=');
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
	free(key_value);
}

static void	update_env_var(t_env_list *tmp, char *arg, char **key_value)
{
	if (key_value[1])
		tmp->value = key_value[1];
	if (!key_value[1] && arg[ft_strlen(key_value[0])] == '=')
		tmp->value = ft_strdup("");
	free(key_value[0]);
	free(key_value);
}

static t_env_list	*env_list_new(char *arg, char	**key_value)
{
	t_env_list	*new;
	char		*error;

	if (!is_valid_key(key_value[0]))
	{
		error = ft_strjoin("export: ", key_value[0]);
		print_error_no_exit(error, "not a valid identifier");
		free(error);
		free_2d_array(key_value);
		return (NULL);
	}
	new = malloc(sizeof(t_env_list));
	if (!new)
		return (NULL);
	new->key = key_value[0];
	new->value = key_value[1];
	if (!key_value[1] && arg[ft_strlen(key_value[0])] == '=')
		new->value = ft_strdup("");
	new->next = NULL;
	return (new);
}

static int	is_valid_key(char *key)
{
	int	i;

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
