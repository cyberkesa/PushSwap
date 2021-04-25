#include "push_swap.h"

int	push_a_with_rotate(t_general *g, char **array, int rotate)
{
	if (rotate > 0)
	{
		while (rotate != 0)
		{
			rb_ins(g);
			rotate--;
		}
	}
	else if (rotate < 0)
	{
		while (rotate != 0)
		{
			rrb_ins(g);
			rotate++;
		}
	}
	pa_ins(g);
	return (rotate);
}

int	push_b_with_rotate(t_general *g, char **array, int rotate)
{
	// if (rotate == 1 && maybe_sa(array) == 1)
	// {
	// 	sa_ins(g);
	// 	pa_ins(g);
	// 	return (0);
	// }
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
	pb_ins(g);
	return (rotate);
}
