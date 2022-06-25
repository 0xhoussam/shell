/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:00:38 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/25 21:39:17 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_2d_array_to_fd(char **str, int std);

void	echo(t_params *params)
{
	char	**str;
	t_cmd	*cmd;
	t_list	*args;
	int		fd;

	cmd = params->cmd;
	fd = get_redir_fd(params);
	args = cmd->args->next;
	if (args && !ft_strcmp(args->content, "-n"))
	{
		args = args->next;
		str = join_args(args);
		print_2d_array_to_fd(str, fd);
		free_2d_array(str);
		return ;
	}
	str = join_args(args);
	print_2d_array_to_fd(str, fd);
	write(fd, "\n", fd);
	free_2d_array(str);
	g_exit_code = 0;
}

static void	print_2d_array_to_fd(char **str, int std)
{
	int	i;

	if (!str)
		return ;
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
