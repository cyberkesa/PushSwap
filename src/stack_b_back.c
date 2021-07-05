#include "push_swap.h"

void	pushing_number(t_general *g, int number_id)
{
	if (g->num_ins[number_id].ra > 0)
		while (g->num_ins[number_id].ra--)
			ra_ins(g);
	if (g->num_ins[number_id].rra > 0)
		while (g->num_ins[number_id].rra--)
			rra_ins(g);
	if (g->num_ins[number_id].rb > 0)
		while (g->num_ins[number_id].rb--)
			rb_ins(g);
	if (g->num_ins[number_id].rrb > 0)
		while (g->num_ins[number_id].rrb--)
			rrb_ins(g);
	if (g->num_ins[number_id].rr > 0)
		while (g->num_ins[number_id].rr--)
			rr_ins(g);
	if (g->num_ins[number_id].rrr > 0)
		while (g->num_ins[number_id].rrr--)
			rrr_ins(g);
	pa_ins(g);
}

void	make_counts_struct(t_general *g)
{
	free(g->num_ins);
	g->num_ins = (t_num_ins *)malloc(sizeof(t_num_ins)
			* (get_len_array(g->b) + 1));
	init_struct(g);
}

int	get_number(t_general *g)
{
	int	len;
	int	i;
	int	return_id;
	int	count_return_id;

	len = get_len_array(g->b);
	count_return_id = g->num_ins[0].count;
	return_id = 0;
	if (len ^ 1)
	{
		i = 1;
		while (i ^ len)
		{
			if (g->num_ins[i].count <= count_return_id)
			{
				return_id = i;
				count_return_id = g->num_ins[i].count;
			}
			i++;
		}
	}
	return (return_id);
}

void	back_push(t_general *g)
{
	while (get_len_array(g->b) ^ 0)
	{
		make_counts_struct(g);
		pushing_number(g, get_number(g));
	}
}
