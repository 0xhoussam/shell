#include "parser.h"

void	delete_command(void *_cmd)
{
	t_cmd	*cmd;

	cmd = _cmd;
	free(cmd->cmd_name);
	ft_lstclear(&cmd->args, free);
	ft_lstclear(&cmd->heredoc_del, free);
	free(cmd->in);
	free(cmd->out);
	free(cmd);
}

void	delete_commands(t_list **cmds)
{
	ft_lstclear(cmds, delete_command);
	*cmds = NULL;
}
