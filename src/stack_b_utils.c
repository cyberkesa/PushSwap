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
