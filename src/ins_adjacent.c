#include "push_swap.h"

void	ss_ins(t_general *g)
{
	sa_ins(g);
	sb_ins(g);
	g->number_ins++;
}

void	rr_ins(t_general *g)
{
	ra_rr(g);
	rb_rr(g);
	g->number_ins++;
	printf("rr\n");
}

void	rrr_ins(t_general *g)
{
	rra_rrr(g);
	rrb_rrr(g);
	g->number_ins++;
	printf("rrr\n");
}
