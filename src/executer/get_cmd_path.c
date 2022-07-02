/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:53:19 by aoumouss          #+#    #+#             */
/*   Updated: 2022/07/02 19:46:32 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			check_access(char *path);
static char	*search_for_cmd(char *command, char **paths);
static char	*check_command(char *command, char **paths);

char	*get_cmd_path(t_params *params)
{
	char	*path;
	char	*command_path;
	char	**paths;
	char	*command;

	command = (char *) params->cmd->cmd_name;
	if (!ft_strcmp(command, ".."))
		return (NULL);
	path = env_list_get(params->env, "PATH");
	if (path == NULL)
		return (NULL);
	paths = ft_split(path, ':');
	if (!paths)
		return (NULL);
	command_path = check_command(command, paths);
	if (!command_path)
	{
		free_2d_array(paths);
		return (NULL);
	}
	free_2d_array(paths);
	return (command_path);
}

static char	*check_command(char *command, char **paths)
{
	char	*path;

	if (!command || !*command)
		return (NULL);
	if (command[0] == '.')
	{
		if (!check_access(command))
			print_error(command, USE_ERRNO);
		return (ft_strdup(command));
	}
	path = search_for_cmd(command, paths);
	if (path)
		return (path);
	if (check_access(command))
		return (ft_strdup(command));
	return (NULL);
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
		if (check_access(path))
			return (path);
		free(path);
		paths++;
	}
	return (NULL);
}

int	check_access(char *path)
{
	if (access(path, F_OK) < 0)
		return (0);
	if (access(path, X_OK) < 0)
		return (0);
	return (1);
}
