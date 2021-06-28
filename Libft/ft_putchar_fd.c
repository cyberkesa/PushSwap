#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (ft_isascii(c) == 1)
		write(fd, &c, 1);
}
