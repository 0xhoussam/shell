/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:37:39 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/27 12:51:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	open_home_dir(t_params *params);
static void	open_prev_dir(t_params *params);

void	cd(t_params *params)
{
	char	*dir_name;
	char	*error;
	DIR		*dir;

	dir_name = NULL;
	if (ft_lstsize(params->cmd->args) > 2)
		return (print_error_no_exit("cd", "too many arguments"));
	if (params->cmd->args->next)
		dir_name = params->cmd->args->next->content;
	if (!dir_name || !ft_strcmp(dir_name, "~"))
		return (open_home_dir(params));
	if (!ft_strcmp(dir_name, "-"))
		return (open_prev_dir(params));
	dir = opendir(dir_name);
	if (!dir)
	{
		error = ft_strjoin("cd: ", dir_name);
		print_error_no_exit(error, USE_ERRNO);
		return (free(error));
	}
	chdir(dir_name);
	closedir(dir);
	free(params->cwd);
	params->cwd = getcwd(NULL, 0);
	g_exit_code = 0;
}

static void	open_home_dir(t_params *params)
{
	char	*home;
	char	*error;
	DIR		*dir;

	home = env_list_get(params->env, "HOME");
	if (!home)
		return (print_error_no_exit("cd", "HOME not set"));
	dir = opendir(home);
	if (!dir)
	{
		error = ft_strjoin("cd: ", home);
		print_error_no_exit(error, USE_ERRNO);
		return (free(error));
	}
	chdir(home);
	closedir(dir);
}

static void	open_prev_dir(t_params *params)
{
	char	*old_pwd;
	char	*error;
	DIR		*dir;

	old_pwd = env_list_get(params->env, "OLDPWD");
	if (!old_pwd)
		return (print_error_no_exit("cd", "OLDPWD not set"));
	dir = opendir(old_pwd);
	if (!dir)
	{
		error = ft_strjoin("cd: ", old_pwd);
		print_error_no_exit(error, USE_ERRNO);
		return (free(error));
	}
	chdir(old_pwd);
	closedir(dir);
}
