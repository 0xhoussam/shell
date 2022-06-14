/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:49:56 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/14 17:56:15 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "types.h"

size_t  echo(t_params *params);
void    pwd(t_params *params);
void    cd(t_params *params);
void    export(t_params *params);
void	unset(t_params *params);
void	env(t_params *params);
void	ft_exit(t_params *params);

#endif
