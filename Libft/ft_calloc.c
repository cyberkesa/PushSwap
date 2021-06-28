#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	register void	*p;

	p = (void *)malloc(size * count);
	if (!p)
		return (NULL);
	ft_bzero(p, size * count);
	return (p);
}
