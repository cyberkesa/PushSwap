#include "push_swap.h"

void	push_a(t_general *g)
{
	main_lis(g);
	int	a;
	int	i;
	int	lol;	
	a = get_len_array(g->array);
	i = 0;
	while (i ^ a)
	{
		if (check_lises(g, g->array[0]) == 1)
			ra_ins(g);
		if (check_lises(g, g->array[0]) == 0)
			pb_ins(g);
		i++;
	}
} 