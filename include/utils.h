/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:24:05 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/24 19:13:33 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "types.h"

t_env_list	*env_array_to_list(char **env);
char		**env_list_to_array(t_env_list *list);
void		env_list_delete(t_env_list **list, char *key);
t_env_list	*env_list_insert(t_env_list **head, char *key, char *value);
void		env_list_clean(t_env_list **lst);
size_t		max_strs_len(char *s1, char *s2);
void		sort_strs(char **strs);
void		free_2d_array(char **args);
char		*env_list_get(t_env_list *list, const char *key);
char		*get_env_variable(char **env, char *key);
int			ft_strcmp(char *s1, char *s2);
int			ft_includes(const char *s, int c);
int			is_valid(const char *s, int c);
int			ft_includes(const char *s, int c);
int			is_valid(const char *s, int c);
int			is_spicial(char c);
int			ft_includes_str(char *haystack, char *needle);
#endif
