#include "push_swap.h"

void	alg_three(t_general *g)
{
	int	rotate;
	char	*midl;

	midl = get_middle_values(g->array, 3);
	if (check_polusort_stack_a(g->array) == 0)
		sa_ins(g);
	if (check_sort(g->array) == 0)
		complete_sort(g);
	if (g->array[0] == midl)
		ra_ins(g);
	else
		rra_ins(g);
}

void	alg_five(t_general *g)
{

}
