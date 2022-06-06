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

#include "lexer.h"
#include "minishell.h"

int main(int ac, char **av, char **env) {

	ac = (int)ac;
	av = (char **)av;
	env = (char **)env;
	t_list *tokens = NULL;

	// char *line = "cd () echo <>";
	char *line = "+ echo";  // TODO: the first token type is overiding all the next tokens
  tokens = extract_tokens_from_line(line);
  t_list *token = tokens;
  while (token)
    {
      t_token *t = (t_token *)tokens->content;
      if (t->token_type == KEYWORD)
        printf("KeyWord\n");
      else if (t->token_type == PUNCTUATION)
        printf("Punctuation\n");
      else if (t->token_type == OPERATOR)
        printf("Operation\n");
      token = token->next;
    }
}
