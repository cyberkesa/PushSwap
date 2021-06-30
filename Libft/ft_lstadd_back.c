#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = *lst;
		lst = &tmp->next;
	}
	*lst = new;
}
