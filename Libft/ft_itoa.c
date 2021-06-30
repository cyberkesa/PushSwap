#include "libft.h"

static int	len(long l)
{
	int		len;

	len = 0;
	if (l < 0)
	{
		l *= -1;
		len++;
	}
	if (l == 0)
	{
		return (1);
	}
	while (l > 0)
	{
		l /= 10;
		len++;
	}
	return (len);
}

static char	*ft_itoa_1(long l, char*array, int i)
{
	if (l == 0)
		array[0] = 48;
	if (l < 0)
	{
		array[0] = '-';
		l = l * -1;
	}
	while (l > 0)
	{
		array[i] = 48 + (l % 10);
		l = l / 10;
		i--;
	}
	return (array);
}

char	*ft_itoa(int n)
{
	char	*array;
	long	l;
	int		i;
	int		res;

	l = n;
	if (l > 0)
		res = 1;
	if (l <= 0)
		res = 0;
	i = len(l);
	array = (char *)malloc(sizeof(char) * (i + 1) + res);
	if (!(array))
		return (NULL);
	array[i--] = '\0';
	return (ft_itoa_1(l, array, i));
}
