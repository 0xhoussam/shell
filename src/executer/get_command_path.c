/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:53:19 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/13 15:36:50 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

static char	*search_for_cmd(char *command, char **paths);
static char	*check_command(char *command, char **paths);

char	*get_cmd_path(t_params *params)
{
	char	*path;
	char	*command_path;
	char	**paths;
	char	*command;
	char	**env;

	command = (char *) params->cmd->cmd_name;
	env = params->env;
	path = get_env_path(env);
	if (path == NULL)
		return (NULL);
	paths = ft_split(path, ':');
	if (!paths)
		return (NULL);
	command_path = check_command(command, paths);
	if (!command_path)
	{
		array_2d_free(paths);
		return (NULL);
	}
	array_2d_free(paths);
	return (command_path);
}

static char	*search_for_cmd(char *command, char **paths)
{
	char	*path;
	char	*tmp;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		path = ft_strjoin(tmp, command);
		free(tmp);
		if (access(path, F_OK) == 0)
		{
			if (access(path, X_OK) < 0)
			{
				print_error(command, USE_ERRNO);
				return (NULL);
			}
			else
				return (path);
		}
		free(path);
		paths++;
	}
	return (NULL);
}

static char	*check_command(char *command, char **paths)
{
	char	*path;

	path = search_for_cmd(command, paths);
	if (path)
		return (path);
	if (access(command, F_OK) == 0)
	{
		if (access(command, X_OK) < 0)
		{
			print_error(command, USE_ERRNO);
			return (NULL);
		}
		else
			return (ft_strdup(command));
	}
	return (NULL);
}
