#include "push_swap.h"

int	maybe_sa(char **array)
{
	if (ft_atoi(array[0]) > ft_atoi(array[1]))
		return (1);
	return (0);
}

int	insert_sorts(t_general *g)
{
	if (check_sort(g->array) == 1
		&& get_len_array(g->stack_b) == 0)
		return (1);
	return (0);
}

int	just_rotate_a(t_general *g, char **array, int rotate)
{
	if (rotate > 0)
	{
		while (rotate--)
			ra_ins(g);
	}
	else if (rotate < 0)
	{
		while (rotate++ != 0)
			rra_ins(g);
	}
	return (rotate);
}

char	check(int nbr, t_general *g)
{
	int	i;

	i = -1;
	while (++i ^ g->len_liss)
		if (ft_atoi(g->lis[i]) == nbr)
			return (0);
	return (1);
}

int	get_middle(int count, t_general *g)
{
	int	i;

	i = 0;
	while (count && count ^ g->len_liss)
	{
		if (check(ft_atoi(g->sort_array[i]), g))
			count--;
		i++;
	}
	return (i);
}
