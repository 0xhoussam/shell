/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:00:38 by habouiba          #+#    #+#             */
/*   Updated: 2022/07/03 17:28:52 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_2d_array_to_fd(char **str, int std);
static int	is_flag(char *str);

void	echo(t_params *params)
{
	char	**str;
	t_cmd	*cmd;
	t_list	*args;
	int		fd;

	cmd = params->cmd;
	fd = get_redir_fd(params);
	args = cmd->args->next;
	if (args && is_flag(args->content))
	{
		while (args && is_flag(args->content))
			args = args->next;
		str = join_args(args);
		print_2d_array_to_fd(str, fd);
		free_2d_array(str);
		return ;
	}
	str = join_args(args);
	print_2d_array_to_fd(str, fd);
	write(fd, "\n", 1);
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
		write(std, str[i], ft_strlen(str[i]));
		i++;
		if (str[i] && *str[i - 1])
			write(std, " ", 1);
	}
}

static int	is_flag(char *str)
{
	int	i;

	if (!str)
		return (0);
	if (str[0] != '-')
		return (0);
	else
	{
		i = 1;
		while (str[i])
		{
			if (str[i] == '-' || str[i] != 'n')
				return (0);
			i++;
		}
	}
	return (1);
}
