#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof((content)))))
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
