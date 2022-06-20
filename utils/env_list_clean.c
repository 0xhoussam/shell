#include "minishell.h"

void	_env_list_clean(t_env_list *lst)
{
	if (lst->next)
		_env_list_clean(lst->next);
	free(lst->key);
	free(lst->value);
	free(lst);
}

void	env_list_clean(t_env_list **lst)
{
	_env_list_clean(*lst);
	*lst = NULL;
}
