#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	lst = NULL;
	free(lst);
	del(lst);
}
