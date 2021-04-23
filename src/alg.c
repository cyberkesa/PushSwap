#include "push_swap.h"

void	new_alg(t_general *g)
{
	int	rotate;
	size_t	i;
	size_t	num_stack_b;
	int	median;

	i = 0;
	num_stack_b = 0;
	median = g->len_argc / 2;
	if (check_polusort_stack_a(g->array) == 1 && get_len_array(g->stack_b) == 0) //если подали полусортированный массив
	{
		rotate = rotate_master(g->array, 'a');
		just_rotate(g, g->array, rotate);
	}
	while (get_len_array(g->stack_b) != median)
	{
		print_array(g->array, "A");
		print_array(g->stack_b, "B");
		if (get_pos_elem(g->sort_array, g->array[0]) == 1
		|| get_pos_elem(g->sort_array, g->array[0]) == 3
		|| get_pos_elem(g->sort_array, g->array[0]) == 5
		|| get_pos_elem(g->sort_array, g->array[0]) == 7
		|| get_pos_elem(g->sort_array, g->array[0]) == 9
		|| get_pos_elem(g->sort_array, g->array[0]) == 11)
		{
			pa_ins(g);
			num_stack_b++;
		}
		else
			ra_ins(g);
		if (ft_atoi(g->array[0]) > ft_atoi(g->array[1])
			&& get_pos_elem(g->sort_array, g->array[0]) > median
			&& get_pos_elem(g->sort_array, g->array[1]) > median)
			{
				sa_ins(g);
			}
		if (get_len_array(g->stack_b) > 1)
		{
			if (num_stack_b == 2 && ft_atoi(g->stack_b[0]) < ft_atoi(g->stack_b[1])
				&& get_pos_elem(g->sort_array, g->stack_b[0]) < median
				&& get_pos_elem(g->sort_array, g->stack_b[1]) < median)
				{
					sb_ins(g);
					num_stack_b -= 2;
				}
		}
	}
	print_array(g->array, "A");
	print_array(g->stack_b, "B");
	complete_sort(g);
}
