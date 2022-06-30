/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:30:32 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/30 16:06:13 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "types.h"

t_list		*lexer(char *line);
t_token		*create_token(t_token_type type, char *value);
void		free_token(void *token);
void		check_pipe(t_list **tokens, char *line, int *index);
void		check_redir(t_list **tokens, char *line, int *index);
void		check_word(t_list **tokens, char *line, int *index);
void		check_and_or(t_list **tokens, char *line, int *index);
void		check_parentheses(t_list **tokens, char *line, int *index);

#endif