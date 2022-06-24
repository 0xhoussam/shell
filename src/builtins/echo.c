/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:00:38 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/24 19:12:49 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_2d_array_to_pipe(char **str, int std);

void	echo(t_params *params)
{
	char	**str;
	t_cmd	*cmd;
	t_list	*args;
	int		i;
	int		write_end;

	cmd = params->cmd;
	write_end = get_redir_fd(params);
	args = cmd->args->next;
	str = join_args(args);
	if (args && !ft_strcmp(args->content, "-n"))
	{
		args = args->next;
		str = join_args(args);
		print_2d_array_to_pipe(str, write_end);
		free_2d_array(str);
		return ;
	}
	print_2d_array_to_pipe(str, write_end);
	write(write_end, "\n", 1);
	free_2d_array(str);
	g_exit_code = 0;
}

static void	print_2d_array_to_pipe(char **str, int std)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strncmp(str[i], "eg", 3))
			ft_putnbr_fd(g_exit_code, std);
		else
			write(std, str[i], ft_strlen(str[i]));
		i++;
		if (str[i])
			write(std, " ", 1);
	}
}
