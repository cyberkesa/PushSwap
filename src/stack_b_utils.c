#include "push_swap.h"

int	find_max_in_a(t_general *g)
{
	int	max;
	int	i;
	int	len;

	i = 1;
	len = get_len_array(g->a);
	max = ft_atoi(g->a[0]);
	while (i ^ len)
	{
		if (ft_atoi(g->a[i]) > max)
			max = ft_atoi(g->a[i]);
		i++;
	}
	return (max);
}

int	find_min_in_a(t_general *g)
{
	int	min;
	int	i;

	i = 1;
	min = ft_atoi(g->a[0]);
	while (i ^ get_len_array(g->a))
	{
		if (ft_atoi(g->a[i]) < min)
			min = ft_atoi(g->a[i]);
		i++;
	}
	return (min);
}

int	ft_intlen_base(unsigned long nbr, int base)
{
	int		i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

char	*pf_itoa_base(unsigned long nbr, int base)
{
	static char		buf[50];
	register int	len;
	char			c;

	len = ft_intlen_base(nbr, base);
	buf[len--] = '\0';
	while (len >= 0)
	{
		c = (char)(nbr % base);
		if (c > 9)
			buf[len--] = c + 'W';
		else
			buf[len--] = c + '0';
		nbr /= base;
	}
	return (buf);
}
