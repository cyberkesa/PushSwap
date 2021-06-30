#include "push_swap.h"

void	alg_three(t_general *g)
{
	if (check_polusort_stack_a(g->array) == 0)
		sa_ins(g);
	if (check_sort(g->array) == 0)
		complete_sort(g);
	if (g->array[0] == g->middle)
		rra_ins(g);
	else
		ra_ins(g);
}

void	alg_five_1(t_general *g, int i, int rotate)
{
	while (i != g->len_argc)
	{
		if (check_sort(g->array) == 0)
			break ;
		rotate = get_min_way(g->array,
				get_pos_elem(g->array, g->sort_array[i]));
		push_b_with_rotate(g, g->array, rotate);
		if (ft_atoi(g->array[0]) > ft_atoi(g->array[1]))
			sa_ins(g);
		i++;
	}
	while (get_len_array(g->stack_b) != 0)
		pa_ins(g);
}

void	alg_five(t_general *g)
{
	size_t	i;
	int		rotate;

	i = 0;
	if (ft_atoi(g->array[3]) == ft_atoi(g->sort_array[0])
		&& ft_atoi(g->array[0]) > ft_atoi(g->array[1]))
		sa_ins(g);
	if (check_polusort_stack_a(g->array) == 1 && get_len_array(g->stack_b) == 0)
	{
		rotate = rotate_master(g->array, 'a');
		just_rotate_a(g, g->array, rotate);
	}
	else if (check_polusort_stack_a(g->array) == 1
		&& check_polusort_stack_a(g->stack_b) == 1)
		insert_sorts(g);
	alg_five_1(g, i, rotate);
}
