/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:25:10 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/03 18:53:31 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef LEXER_H
# define LEXER_H

#include "libft.h"

# define KEYWORDS "cd pwd unset echo export env exit"
# define PUNCTUATIONS ", * ; ( ) | \" \' / { } [ ] | &"
# define OPERATORS "+ - * / < > << >> = == != & && | ||"

enum e_token_type {
	IDENTIFIER,
	OPERATOR,
	CONSTANTS,
	KEYWORD,
	LETERALS,
	PUNCTUATION,
	SPECIAL_CHARACTERS
};

enum e_keywords {
	CD,
	PWD,
	//READ,
	//SET,
	UNSET, // doing...
	ECHO, // done
	//READONLY,
	//SHIFT,
	EXPORT,
	ENV,
	EXIT,
	//IF, // done
	//FI,
	//ELSE,
	//WHILE,
	//DO,
	//DONE,
	//FOR,
	//UNTIL,
	//CASE,
	//ESACK,
	//BREAK,
	//CONTINUE,
	//EXIT,
	//RETURN,
	//TRAP,
	//WAIT,
	//EVAL,
	//EXEC,
	//ULIMIT,
	//UMASK
};

enum e_punctuation {
	CAMMA, // ,
	ASTERISK, // *
	SEMICOLON, // ;
	OPEN_PARENTHESES, // (
	CLOSED_PARENTHESES, // )
	DOUBLE_QUOTAION, // "
	SINGLE_QUOTAION, // '
	SLASH, // /
	OPEN_CURLY_BRACKET, // {
	CLOSED_CURLY_BRACKET, // }
	OPEN_SQUAR_BRACKETS, // [
	CLOSED_SQUAR_BRACKETS, // ]
	VERTICAL_BAR, // |
};

enum e_operators {
	PLUS,
	MINUS,
	MULT,
	DIVI,
	LESS_THAT,
	MORE_THAN,
	DOUBLE_LESS_THAN,
	DOUBLE_MORE_THAN,
	AND,
	DOUBLE_AND,
};

typedef struct s_token {
	enum e_token_type	token_type;
	enum e_punctuation	punc;
	enum e_keywords		keyword;
	enum e_operators	op;
	char				*str;
}	t_token;

void	extract_token(const char *line, t_list **tokens, int *i, const char *word);
t_list	*extract_tokens_from_line(const char *line);
// void	echo_helper(const char *line, t_list **tokens, int *i);

#endif
