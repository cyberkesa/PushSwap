#include "push_swap.h"

void	sa_ins(t_general *g)
{
	char	*tmp;

	if (!(g->array[0]) || !(g->array[1]))
		return ;
	tmp = g->array[0];
	g->array[0] = g->array[1];
	g->array[1] = tmp;
	g->number_ins++;
	printf("sa\n");
}

void	sb_ins(t_general *g)
{
	char	*tmp;

	if (!(g->stack_b[0]) || !(g->stack_b[1]))
		return ;
	tmp = g->stack_b[0];
	g->stack_b[0] = g->stack_b[1];
	g->stack_b[1] = tmp;
	g->number_ins++;
	printf("sb\n");
}
