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

int	check_sa(t_general *g, char **array)
{
	if (ft_atoi(array[0]) > ft_atoi(g->array[1]))
		return (1);
	return (0);
}

int	check_sb(t_general *g, char **array)
{
	if (array[0] < array[1])
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

int	just_rotate_b(t_general *g, char **array, int rotate)
{
	if (rotate == 1 && maybe_sa(array) == 1)
	{
		sb_ins(g);
		return (0);
	}
	else if (rotate > 0)
	{
		while (rotate--)
			rb_ins(g);
	}
	else if (rotate < 0)
	{
		while (rotate++ != 0)
			rrb_ins(g);
	}
	return (rotate);
}

int	rot_find_min(int *array, int len)
{
	int	pos;
	int	min;
	int	i;

	i = 0;
	pos = 0;
	min = (abs)(array[0]);
	while (len--)
	{
		if ((abs)(array[i]) < min)
		{
			min = (abs)(array[i]);
			pos = i;
		}
		i++;
	}
	return (pos);
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

int		is_in_array(char **array, char *s)
{
	while (*array)
		if (!ft_strcmp(*array++, s))
			return (1);
	return (0);
}

void	takoe(t_general *g)
{
	if (check_polusort_stack_a(g->array) == 1 && get_len_array(g->stack_b) == 0)
		just_rotate_a(g, g->array, rotate_master(g->array, 'a'));
	else if (check_polusort_stack_a(g->array) == 1 && check_polusort_stack_a(g->stack_b) == 1)
		insert_sorts(g);
}

void	all_night(t_general *g)
{
	while (get_len_array(g->stack_b) ^ 0)
		back_push(g);
	if (check_polusort_stack_a(g->array) == 1 && get_len_array(g->stack_b) == 0)
		just_rotate_a(g, g->array, rotate_master(g->array, 'a'));
}
