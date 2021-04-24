#include "push_swap.h"

int	push_a_with_rotate(t_general *g, char **array, int rotate)
{
	if (rotate > 0)
	{
		while (rotate--)
			rb_ins(g);
	}
	else if (rotate < 0)
	{
		while (rotate++ != 0)
			rrb_ins(g);
	}
	pa_ins(g);
	return (rotate);
}

void	back_to_you(t_general *g)
{
	// print_array(g->stack_b, "Pizda");
	register size_t	i;
	int	rotate;

	i = g->len_argc;
	while (i--)
	{
		rotate = get_min_way(g->stack_b,
		get_pos_elem(g->stack_b, g->sort_array[i]));
		push_a_with_rotate(g, g->stack_b, rotate);
	}
	// print_array(g->lol, "lol");
	// print_array(g->array, "kek");
	complete_sort(g);
}
