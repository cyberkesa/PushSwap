#include "libft.h"

int	ft_isalpha_char(char c)
{
	return (ft_islower((int)c) || ft_isupper((int)c));
}