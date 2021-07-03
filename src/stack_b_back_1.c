#include "push_swap.h"

void	init_processing(t_general *g, int i)
{
	g->num_ins[i].ra = 0;
	g->num_ins[i].rb = 0;
	g->num_ins[i].rr = 0;
	g->num_ins[i].rrr = 0;
	g->num_ins[i].rrb = 0;
	g->num_ins[i].rra = 0;
	g->num_ins[i].count = 0;
}

void	if_processing_1(t_general *g, int i)
{
	if (g->num_ins[i].ra < g->num_ins[i].rb)
	{
		g->num_ins[i].rr = g->num_ins[i].ra;
		g->num_ins[i].ra = 0;
		g->num_ins[i].rb -= g->num_ins[i].rr;
	}
	if (g->num_ins[i].ra > g->num_ins[i].rb)
	{
		g->num_ins[i].rr = g->num_ins[i].rb;
		g->num_ins[i].rb = 0;
		g->num_ins[i].ra -= g->num_ins[i].rr;
	}
	if (g->num_ins[i].ra == g->num_ins[i].rb)
	{
		g->num_ins[i].rr = g->num_ins[i].ra;
		g->num_ins[i].rb = 0;
		g->num_ins[i].ra = 0;
	}
}

void	if_processing_2(t_general *g, int i)
{
	if (g->num_ins[i].rra < g->num_ins[i].rrb)
	{
		g->num_ins[i].rrr = g->num_ins[i].rra;
		g->num_ins[i].rra = 0;
		g->num_ins[i].rrb -= g->num_ins[i].rrr;
	}
	if (g->num_ins[i].rra > g->num_ins[i].rrb)
	{
		g->num_ins[i].rrr = g->num_ins[i].rrb;
		g->num_ins[i].rrb = 0;
		g->num_ins[i].rra -= g->num_ins[i].rrr;
	}
	if (g->num_ins[i].rra == g->num_ins[i].rrb)
	{
		g->num_ins[i].rrr = g->num_ins[i].rra;
		g->num_ins[i].rrb = 0;
		g->num_ins[i].rra = 0;
	}
}

void	processing_ins(t_general *g, int i)
{
	init_processing(g, i);
	if (g->num_ins[i].stack_a_rotate < 0)
		g->num_ins[i].rra = (abs)(g->num_ins[i].stack_a_rotate);
	if (g->num_ins[i].stack_b_rotate < 0)
		g->num_ins[i].rrb = (abs)(g->num_ins[i].stack_b_rotate);
	if (g->num_ins[i].stack_a_rotate > 0)
		g->num_ins[i].ra = g->num_ins[i].stack_a_rotate;
	if (g->num_ins[i].stack_b_rotate > 0)
		g->num_ins[i].rb = g->num_ins[i].stack_b_rotate;
	if (g->num_ins[i].ra > 0 && g->num_ins[i].rb > 0)
		if_processing_1(g, i);
	if (g->num_ins[i].rra > 0 && g->num_ins[i].rrb > 0)
		if_processing_2(g, i);
	g->num_ins[i].count = g->num_ins[i].rrr
		+ g->num_ins[i].rra + g->num_ins[i].rrb
		+ g->num_ins[i].rr + g->num_ins[i].ra + g->num_ins[i].rb;
}
