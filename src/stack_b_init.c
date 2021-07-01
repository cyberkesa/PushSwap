#include "push_swap.h"

void	init_numbers(t_general *g)
{
	int	i;
	int	len;

	len = get_len_array(g->b);
	i = 0;
	while (i ^ len)
	{
		g->num_ins[i].number = g->b[i];
		i++;
	}
	g->num_ins[i].number = NULL;
}

void	init_struct(t_general *g)
{
	int	len;

	init_numbers(g);
	len = 0;
	while (len ^ get_len_array(g->b))
	{
		get_best_alg(g, len);
		len++;
	}
}
