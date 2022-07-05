/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:51:26 by habouiba          #+#    #+#             */
/*   Updated: 2022/07/05 11:06:03 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_init(t_params *params, char **env);
void	shell_destroy(t_params *params);
void	print_cmds(t_list *cmds);
void	printc(t_list *cmds);

int		g_exit_code = 0;

int	main(int argc, char **argv, char **env)
{
	t_params	params;
	char		*line;
	t_list		*cmds;

	argv = (char **)argv;
	argc = (int)argc;
	shell_init(&params, env);
	while (1)
	{
		line = prompt();
		cmds = parser(line, params.env);
		free(line);
		executer(&params, cmds);
		delete_commands(&cmds);
	}
	shell_destroy(&params);
	return (g_exit_code);
}

void	shell_init(t_params *params, char **env)
{
	params->env = env_array_to_list(env);
	params->cwd = getcwd(NULL, 0);
	if (!params->cwd)
		perror(GET_CWD_ERROR);
}

void	shell_destroy(t_params *params)
{
	free(params->cwd);
	env_list_clean(&params->env);
	rl_clear_history();
}
