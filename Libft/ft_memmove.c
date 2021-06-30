#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char		*s;
	const char		*lasts;
	char			*d;
	char			*lastd;

	d = dst;
	s = src;
	lasts = s + (len - 1);
	lastd = d + (len - 1);
	if (dst != 0 || src != 0)
	{
		while (len--)
		{
			if (d < s)
				*d++ = *s++;
			else
				*lastd-- = *lasts--;
		}
	}
	return (dst);
}
