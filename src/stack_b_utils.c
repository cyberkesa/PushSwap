#include "push_swap.h"

int	find_max_in_a(t_general *g)
{
	int	max;
	int	i;
	int	len;
	i = 1;
	len = get_len_array(g->array);
	max = ft_atoi(g->array[0]);
	while (i ^ len)
	{
		if (ft_atoi(g->array[i]) > max)
			max = ft_atoi(g->array[i]);
		i++;
	}
	return (max);
}

int	find_min_in_a(t_general *g)
{
	int	min;
	int	i;
	i = 1;
	min = ft_atoi(g->array[0]);
	while (i ^ get_len_array(g->array))
	{
		if (ft_atoi(g->array[i]) < min)
			min = ft_atoi(g->array[i]);
		i++;
	}
	return (min);
}