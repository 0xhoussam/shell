/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:49:56 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/21 16:05:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "types.h"

void	echo(t_params *params);
void    pwd(t_params *params, int print);
void    cd(t_params *params);
void    export(t_params *params);
void	unset(t_params *params);
void	env(t_params *params);
void	ft_exit(t_params *params);

#endif
