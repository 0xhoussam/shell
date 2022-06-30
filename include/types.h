/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:38:54 by aoumouss          #+#    #+#             */
/*   Updated: 2022/06/30 12:32:40 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "libft.h"

typedef enum e_redir_type
{
	NIL,
	SINGLE,
	DOUBLE,
	HEREDOC
}	t_redir_type;

typedef enum e_token_type
{
	LEX_WORD,
	LEX_PIPE,
	LEX_AND,
	LEX_OR,
	LEX_REDIR,
	OPEN_PARENTHESIS,
	CLOSE_PARENTHESIS,
}	t_token_type;

typedef enum e_delimiter {
	NONE,
	AND,
	OR,
	SEMICOLON,
	PIPE
}	t_delimiter;

typedef struct s_token {
	char			*value;
	t_token_type	type;
}				t_token;

typedef struct s_cmd {
	char			*cmd_name;
	t_list			*args;
	char			*in;
	char			*out;
	t_list			*heredoc_del;
	t_redir_type	in_redir;
	t_redir_type	out_redir;
	t_delimiter		left_delimiter;
	t_delimiter		right_delimiter;

}	t_cmd;

typedef struct s_env_list
{
	char				*key;
	char				*value;
	struct s_env_list	*next;
}	t_env_list;

typedef struct s_params {
	t_cmd		*cmd;
	t_env_list	*env;
	int			**pipes;
	int			*pids;
	char		*cwd;
	int			cmds_list_size;
	int			index;
}	t_params;

#endif
