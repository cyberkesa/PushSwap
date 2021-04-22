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

void	alg_five(t_general *g)
{

}
