#include "push_swap.h"

void	back_to_you(t_general *g)
{
	register size_t	i;
	int	rotate;

	i = get_len_array(g->stack_b);
	while (i--)
	{
		rotate = get_min_way(g->stack_b,
		get_pos_elem(g->stack_b, g->sort_array[i]));
		push_a_with_rotate(g, g->stack_b, rotate);
	}
	print_array(g->array, "Stack A");
	print_array(g->stack_b, "Stack B");
	complete_sort(g);
}
