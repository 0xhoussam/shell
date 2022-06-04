/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:51:26 by habouiba          #+#    #+#             */
/*   Updated: 2022/05/31 17:17:10 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **env) {

	ac = (int)ac;
	av = (char **)av;
	env = (char **)env;
	t_list *tokens = NULL;

	char *line = "cd echo";

	int i = 0;
	char **keywords = ft_split(KEYWORDS, ' ');
	char **punctuations = ft_split(PUNCTUATIONS, ' ');
	char **operators = ft_split(OPERATORS, ' ');


	int  j = 0;
	while (keywords[j])
	{
		if_helper(line, &tokens, &i, keywords[j]);
		j++;
	}

	// while (tokens)
	// {
		t_token *token = tokens->content;
		t_token *next = tokens->next->content;
		printf("%s\n", token->keyword == CD ? "cd" : "Not a keyword");
		printf("%s\n", next->keyword == ECHO ? "echo" : "Not a keyword");

	// 	tokens = tokens->next;
	// }

}
