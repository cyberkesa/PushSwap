#include "libft.h"

void	ft_putchar(char c)
{
	if (ft_isascii(c) == 1)
		write(1, &c, 1);
}
