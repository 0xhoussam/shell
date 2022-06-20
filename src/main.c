/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:51:26 by habouiba          #+#    #+#             */
/*   Updated: 2022/06/20 11:55:53 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "tests.h"

int g_exit_code = 0;
// const char *__asan_default_options() { return "detect_leaks=0"; }

void print_cmds(t_list *cmds);
void printc(t_list *cmds);

int main(int ac, char **av, char **env)
{
	ac = (int)ac;
	av = (char **)av;
	env = (char **)env;
	t_env_list *lst;

	lst = env_array_to_list(env);
	// t_list *commands = parser("cat $USER <file >| ls -l", lst);
	// evaluate_str_and_var(commands, lst);
	// print_cmds(commands);
	// printc(commands);
	//executer(commands, env);

	char *s = _expand("hello $NAME world", lst);
	printf("'%s'\n", s);
	free(s);
	return (WEXITSTATUS(g_exit_code));
}

// int main(int ac, char **av, char **env)
// {
//     ac = (int)ac;
//     av = (char **)av;
//     env = (char **)env;
//     t_env_list lst;

// 		lst.key = "name";
// 		lst.value = "houssam";
// 		lst.next = NULL;
//     t_list *commands = parser("cat | ls", &lst);
// 		evaluate_str_and_var(commands, &lst);
//     printc(commands);
//     //executer(commands, env);
//     // lst.key = "name";
//     // lst.value = "houssam";
//     // lst.next = NULL;
//     // char *a = remove_double_quotes("\"$name hello $name hello\"", &lst);
//     // printf("%s\n", a);
//     return (WEXITSTATUS(g_exit_code));
// }

void print_cmds(t_list *cmds)
{
	while (cmds)
	{
		t_cmd *cmd = (t_cmd *)cmds->content;
		printf("%s ", (char *)cmd->cmd_name);
		t_list *args = cmd->args;
		t_list *heredocs = cmd->heredoc_del;
		while (heredocs)
		{
			printf("<<%s ", (char *)heredocs->content);
			heredocs = heredocs->next;
		}
		if (cmd->in)
			printf("<%s ", (char *)cmd->in);
		if (cmd->out)
			printf(">%s ", (char *)cmd->out);
		while (args->next)
		{

			printf("%s ", (char *)args->next->content);
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
		printf("------------------------------------------------\n\n");
		t_cmd *cmd = node->content;
		printf("cmd_name: %s\n", cmd->cmd_name);
		printf("args: ");
		for (t_list *arg = cmd->args; arg; arg = arg->next)
		{
			printf("%s ", (char *)arg->content);
		}
		printf("\n");
		printf("in: %s type: %s\n", cmd->in, b[cmd->in_redir]);
		printf("out: %s type: %s\n", cmd->out, b[cmd->out_redir]);
		printf("left: %s\n", a[cmd->left_delimiter]);
		printf("right: %s\n", a[cmd->right_delimiter]);
		for (t_list *hered = cmd->heredoc_del; hered; hered = hered->next)
		{
			printf("%s ", (char *)hered->content);
		}
		printf("\n\n");
	}
}
