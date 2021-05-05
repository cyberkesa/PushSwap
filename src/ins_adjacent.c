#include "push_swap.h"

void	ss_ins(t_general *g)
{
	sa_ins(g);
	sb_ins(g);
	g->ins_num--;
	printf("ss\n");
}

void	rr_ins(t_general *g)
{
	ra_ins(g);
	rb_ins(g);
	g->ins_num--;
	printf("rr\n");
}

void	rrr_ins(t_general *g)
{
	rra_ins(g);
	rrb_ins(g);
	g->ins_num--;
	printf("rrr\n");
}
