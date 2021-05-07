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
	if (rotate == 1 && maybe_sa(array) == 1)
	{
		sa_ins(g);
		return (0);
	}
	else if (rotate > 0)
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

void	super_algorithm(t_general *g)
{
	size_t	i;
	size_t	elem_in_b;
	i = 0;
	int	a;
	int	wait_b;

	elem_in_b = 0;
	wait_b = (g->len_argc - g->len_liss) / 2;
	if (check_polusort_stack_a(g->array) == 1 && get_len_array(g->stack_b) == 0)
		just_rotate_a(g, g->array, rotate_master(g->array, 'a'));
	else if (check_polusort_stack_a(g->array) == 1 && check_polusort_stack_a(g->stack_b) == 1)
		insert_sorts(g);
	int	without_lis;
	without_lis = (g->len_argc - g->len_liss) / 2;
	printf("without_lis: %d\n", without_lis);
	int		next_part;

	next_part = without_lis;
	while (get_len_array(g->stack_b) != (g->len_argc - g->len_liss))
	{
			if (check_lises(g, g->array[0]) == 0)
			{
				if (ft_atoi(g->array[0]) > ft_atoi(g->sort_array[(int)((g->len_argc - (get_len_array(g->stack_b) - g->len_liss)) / 2)])
				&& get_len_array(g->array) != g->len_liss)
					ra_ins(g);
				else
					pb_ins(g);
				if (ft_atoi(g->stack_b[0]) < ft_atoi(g->sort_array[(int)(g->len_argc / 4) % get_len_array(g->sort_array)]))
					rb_ins(g);
			}
			if (check_lises(g, g->array[0]) == 1 && get_len_array(g->array) != g->len_liss)
				ra_ins(g);
	}
	print_array(g->array, "a");
	print_array(g->stack_b, "b");
	complete_sort(g);
	// while (get_len_array(g->array) != g->len_liss)
	// {
	// 	if (check_lises(g, g->array[0]) == 0)
	// 	{
	// 		pb_ins(g);
	// 		if (ft_atoi(g->stack_b[0]) > ft_atoi(g->sort_array[elem_in_b]))
	// 		{
	// 			rb_ins(g);
	// 			elem_in_b++;
	// 		}
	// 		//more move with stack B
	// 	}
	// 	else
	// 	{
	// 		elem_in_b++;
	// 		ra_ins(g);
	// 	}
	// }
	// back_in_a(g);
}
