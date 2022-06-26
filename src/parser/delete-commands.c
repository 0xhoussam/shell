#include "parser.h"

void delete_command(void *_cmd)
{
    t_cmd *cmd;

    if (!cmd)
        return;
    cmd = _cmd;
    if (cmd->cmd_name)
        free(cmd->cmd_name);
    ft_lstclear(&cmd->args, free);
    ft_lstclear(&cmd->heredoc_del, free);
    if (cmd->in)
        free(cmd->in);
    if (cmd->out)
        free(cmd->out);
    free(cmd);
}

void delete_commands(t_list **cmds)
{
    ft_lstclear(cmds, delete_command);
    *cmds = NULL;
}
