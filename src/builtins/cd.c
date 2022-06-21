/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:37:39 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/21 16:54:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	open_home_dir(t_params *params);
void	open_prev_dir(t_params *params);

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
		error = ft_strjoin(dir_name, ": no such file or directory");
		print_error_no_exit("cd", error);
	}
	chdir(dir_name);
	closedir(dir);
	pwd(params, 0);
}

void	open_home_dir(t_params *params)
{
	char	*home;
	char	*error;
	DIR		*dir;

	home = get_env_variable(params->env, "HOME");
	if (!home)
		return (print_error_no_exit("cd", "HOME not set"));
	dir = opendir(home);
	if (!dir)
	{
		error = ft_strjoin(home, ": no such file or directory");
		print_error_no_exit("cd", error);
		return ;
	}
	chdir(home);
	closedir(dir);
}

void	open_prev_dir(t_params *params)
{
	char	*old_pwd;
	char	*error;
	DIR		*dir;

	old_pwd = get_env_variable(params->env, "OLDPWD");
	if (!old_pwd)
		return (print_error_no_exit("cd", "OLDPWD not set"));
	dir = opendir(old_pwd);
	if (!dir)
	{
		error = ft_strjoin(old_pwd, ": no such file or directory");
		print_error_no_exit("cd", error);
		return ;
	}
	chdir(old_pwd);
	closedir(dir);
}
