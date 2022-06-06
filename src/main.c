/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:51:26 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/06 09:28:50 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **env) {

	ac = (int)ac;
	av = (char **)av;
	env = (char **)env;
	t_list *tokens = NULL;

	char *line = "cd echo";


}
