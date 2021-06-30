#include "push_swap.h"

void	get_best_alg(t_general *g, int i)
{
	int	a;
	int	res;
	int	current_number;
	int	max;
	int	min;

	min = find_min_in_a(g);
	max = find_max_in_a(g);
	current_number = ft_atoi(g->num_ins[i].number);
	if (current_number > max)
	{
		g->num_ins[i].stack_a_rotate = get_min_way(g->array,
				get_pos_elem(g->array, ft_itoa(min)));
		g->num_ins[i].stack_b_rotate = get_min_way(g->stack_b,
				get_pos_elem(g->stack_b, ft_itoa(current_number)));
		g->num_ins[i].count = (abs)(g->num_ins[i].stack_a_rotate)
			+ (abs)(g->num_ins[i].stack_b_rotate);
	}
	else if (current_number < min)
	{
		g->num_ins[i].stack_a_rotate = get_min_way(g->array,
				get_pos_elem(g->array, ft_itoa(min)));
		g->num_ins[i].stack_b_rotate = get_min_way(g->stack_b,
				get_pos_elem(g->stack_b, ft_itoa(current_number)));
		g->num_ins[i].count = (abs)(g->num_ins[i].stack_a_rotate)
			+ (abs)(g->num_ins[i].stack_b_rotate);
	}
	else
	{
		a = 0;
		res = -1;
		while (a + 1 ^ get_len_array(g->array))
		{
			if (ft_atoi(g->array[a]) < current_number
				&& ft_atoi(g->array[a + 1]) > current_number)
				res = a;
			a++;
		}
		if (res == -1)
		{
			if (ft_atoi(g->array[a]) < current_number
				&& ft_atoi(g->array[0]) > current_number)
				res = -1;
		}
		g->num_ins[i].stack_a_rotate = get_min_way(g->array, res) + 1;
		g->num_ins[i].stack_b_rotate = get_min_way(g->stack_b,
				get_pos_elem(g->stack_b, g->num_ins[i].number));
		g->num_ins[i].count = (abs)(g->num_ins[i].stack_a_rotate)
			+ (abs)(g->num_ins[i].stack_b_rotate);
	}
	processing_ins(g, i);
}
