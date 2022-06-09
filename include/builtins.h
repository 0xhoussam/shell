/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:49:56 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/09 06:30:48 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <dirent.h>
# include <string.h>

#ifndef MAX_BUF
#define MAX_BUF 100
#endif
# define ECHO_N_FLAG 0x01

typedef struct s_env_list
{
    char *key;
    char *value;
    struct s_env_list *next;
}	t_env_list;

typedef struct s_env_list t_env_list;

size_t  echo(const char *str, int flags);
void    pwd();
void    cd(const char *dir);
void    export(t_env_list **list, char *key, char *value);

#endif
