#include "minishell.h"
t_list	*args_generator(char **command);

t_list *generator()
{
	// commands names
	char	**commands = malloc(sizeof(char *) * 4);
	commands[0] = "sleep";
	commands[1] = "ls";
	commands[2] = "cat";
	commands[3] = "grep";
	
	// cat arguments
	char **cat = malloc(sizeof(char *) * 4);
	cat[0] = "cat";
	cat[1] = "-e";
	cat[2] = "cat_file";
	cat[3] = NULL;
	
	// ls arguments
	char **ls = malloc(sizeof(char *) * 3);
	ls[0] = "ls";
	ls[1] = "cat_file";
	ls[2] = NULL;
	
	// grep arguments
	char **grep = malloc(sizeof(char *) * 3);
	grep[0] = "grep";
	grep[1] = "cat";
	grep[2] = NULL;
	
	// sleep arguments
	char **sleep_cmd = malloc(sizeof(char *) * 3);
	sleep_cmd[0] = "sleep";
	sleep_cmd[1] = "4";
	sleep_cmd[2] = NULL;
	
	// in files
	char **in_files = malloc(sizeof(char *) * 4);
	in_files[0] = "cat_file";
	in_files[1] = "/etc/passwd";
	in_files[2] = "grep_file";
	in_files[3] = "/etc/passwd";

	// out files
	char **out_files = malloc(sizeof(char *) * 4);
	out_files[0] = "cat_out_file";
	out_files[1] = "ls_out_file";
	out_files[2] = "grep_out_file";
	out_files[3] = "sleep_out_file";

	
	t_list *list;
	t_cmd *cmd;

	list = NULL;
	cmd = NULL;
	int i = 0;
	while (i < 4)
	{
		cmd = malloc(sizeof(t_cmd));
		cmd->cmd_name = commands[i];
		if (ft_strcmp(commands[i], "cat") == 0)
			cmd->args = args_generator(cat);
		else if (ft_strcmp(commands[i], "ls") == 0)
			cmd->args = args_generator(ls);
		else if (ft_strcmp(commands[i], "grep") == 0)
			cmd->args = args_generator(grep);
		else if (ft_strcmp(commands[i], "sleep") == 0)
			cmd->args = args_generator(sleep_cmd);
		cmd->in = NULL;
		cmd->out = NULL;
		cmd->heredoc_del = NULL;
		cmd->in_redir = NIL;
		cmd->out_redir = NIL;
		cmd->left_delimiter = NONE;
		cmd->right_delimiter = PIPE;
		if (ft_strcmp(commands[i], "sleep"))
			cmd->left_delimiter = PIPE;
		ft_lstadd_back(&list, ft_lstnew(cmd));
		i++;
	}
	return (list);
}

t_list	*args_generator(char **command)
{
	t_list *list = NULL;
	int j = 0;
	while (command[j])
	{
		ft_lstadd_back(&list, ft_lstnew(command[j]));
		j++;
	}
	return (list);
}