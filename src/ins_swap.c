#include "push_swap.h"

void	sa_ins(t_general *g)
{
	char	*tmp;

	if (!(g->a[0]) || !(g->a[1]))
		return ;
	tmp = g->a[0];
	g->a[0] = g->a[1];
	g->a[1] = tmp;
	g->number_ins++;
	printf("sa\n");
}

void	sb_ins(t_general *g)
{
	char	*tmp;

	if (!(g->b[0]) || !(g->b[1]))
		return ;
	tmp = g->b[0];
	g->b[0] = g->b[1];
	g->b[1] = tmp;
	g->number_ins++;
	printf("sb\n");
}
