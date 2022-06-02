/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:24:05 by aoumouss          #+#    #+#             */
/*   Updated: 2022/05/31 17:16:11 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

t_env_list  *env_array_to_list(char **env);
char        **env_list_to_array(t_env_list *list);
void        env_list_delete(t_env_list **list, char *key);
t_env_list *env_list_insert(t_env_list **head, char *key, char *value);
size_t	    max_strs_len(char *s1, char *s2);
void        sort_strs(char **strs);

#endif