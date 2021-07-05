#include "push_swap.h"

void	alg_three(t_general *g)
{
	if (check_polusort_stack_a(g->a) == 0)
		sa_ins(g);
	if (check_sort(g->a) == 0)
		complete_sort(g);
	if (g->a[0] == g->middle)
		rra_ins(g);
	else
		ra_ins(g);
}

void	alg_five_1(t_general *g, int i, int rotate)
{
	while (i != g->len_argc)
	{
		if (check_sort(g->a) == 0)
			break ;
		rotate = get_min_way(g->a, get_pos_elem(g->a, g->sort[i]));
		push_b_with_rotate(g, g->a, rotate);
		if (get_len_array(g->a) == 3)
		{
			if (ft_atoi(g->a[0]) > ft_atoi(g->a[1])
				&& ft_atoi(g->a[0]) > ft_atoi(g->a[2]))
				ra_ins(g);
			if (ft_atoi(g->a[0]) > ft_atoi(g->a[1])
				&& ft_atoi(g->a[0]) < ft_atoi(g->a[2]))
				sa_ins(g);
		}
		else if (ft_atoi(g->a[0]) > ft_atoi(g->a[1]))
			sa_ins(g);
		i++;
	}
	while (get_len_array(g->b) != 0)
		pa_ins(g);
}

void	alg_five(t_general *g)
{
	size_t	i;
	int		rotate;

	i = 0;
	if (ft_atoi(g->a[3]) == ft_atoi(g->sort[0])
		&& ft_atoi(g->a[0]) > ft_atoi(g->a[1]))
		sa_ins(g);
	if (check_polusort_stack_a(g->a) == 1 && get_len_array(g->b) == 0)
	{
		rotate = rotate_master(g->a, 'a');
		if (rotate == get_len_array(g->a))
			rotate = 0;
		just_rotate_a(g, g->a, rotate);
	}
	else if (check_polusort_stack_a(g->a) == 1
		&& check_polusort_stack_a(g->b) == 1)
		insert_sorts(g);
	alg_five_1(g, i, rotate);
}
