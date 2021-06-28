#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;

	len = 1;
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
		++len;
	}
	return (len);
}
