/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumouss <aoumouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:51:26 by habouiba          #+#    #+#             */
/*   Updated: 2022/07/04 18:35:47 by aoumouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_init(t_params *params, char **env);
void	shell_destroy(t_params *params);
void	print_cmds(t_list *cmds);
void	printc(t_list *cmds);

int		g_exit_code = 0;

int	main(int _, char **__, char **env)
{
	t_params	params;
	char		*line;
	t_list		*cmds;

	__ = __;
	_ = _;
	shell_init(&params, env);
	while (1)
	{
		line = prompt();
		cmds = parser(line, params.env);
		free(line);
		executer(&params, cmds);
		delete_commands(&cmds);
	}
	shell_destroy(&params);
	return (g_exit_code);
}

void	shell_init(t_params *params, char **env)
{
	params->env = env_array_to_list(env);
	params->cwd = getcwd(NULL, 0);
	if (!params->cwd)
		perror(GET_CWD_ERROR);
}

void	shell_destroy(t_params *params)
{
	free(params->cwd);
	env_list_clean(&params->env);
	rl_clear_history();
}

/*
void print_cmds(t_list *cmds)
{
	while (cmds)
	{
		t_cmd *cmd = (t_cmd *)cmds->content;
		if (cmd->cmd_name)
			printf("'%s'", (char *)cmd->cmd_name);
		t_list *args = cmd->args;
		t_list *heredocs = cmd->heredoc_del;
		while (heredocs)
		{
			printf("<<'%s' ", (char *)heredocs->content);
			heredocs = heredocs->next;
		}
		if (cmd->in)
			printf("<'%s' ", (char *)cmd->in);
		if (cmd->out)
			printf(">'%s' ", (char *)cmd->out);
		while (args && args->next)
		{

			printf("'%s' ", (char *)args->next->content);
			args = args->next;
		}
		if (cmds->next)
		{
			if (cmd->right_delimiter == PIPE)
				printf(" | ");
			else if (cmd->right_delimiter == AND)
				printf(" && ");
			else if (cmd->right_delimiter == OR)
				printf(" || ");
		}
		cmds = cmds->next;
	}
	printf("\n");
}

void printc(t_list *cmds)
{
	char *a[] = {"NONE", "AND", "OR", "SEMICOLON", "PIPE"};
	char *b[] = {"NIL", "SINGLE", "DOUBLE", "HEREDOC"};
	for (t_list *node = cmds; node; node = node->next)
	{
		printf("\n------------------------------------------------\n");
		t_cmd *cmd = node->content;
		printf("cmd_name: {%s}\n", cmd->cmd_name);
		printf("args: ");
		for (t_list *arg = cmd->args; arg; arg = arg->next)
		{
			printf("{%s} ", (char *)arg->content);
		}
		printf("\n");
		printf("in: {%s} type: {%s}\n", cmd->in, b[cmd->in_redir]);
		printf("out: {%s} type: {%s}\n", cmd->out, b[cmd->out_redir]);
		printf("left: {%s}\n", a[cmd->left_delimiter]);
		printf("right: {%s}\n", a[cmd->right_delimiter]);
		for (t_list *hered = cmd->heredoc_del; hered; hered = hered->next)
		{
			printf("{%s} ", (char *)hered->content);
		}
	}
	printf("\n------------------------------------------------\n");
}

*/
