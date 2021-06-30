#include "push_swap.h"

void	free_array(char **r)
{
	size_t	i;

	i = 0;
	while (r[i] != NULL)
		free(r[i++]);
	free(r);
}

void	ft_exit(t_general *g)
{
	free(g->array);
	free(g->stack_b);
	free(g->sort_array);
	free(g->new_sort_unliss);
	exit (0);
}

void	complete_sort(t_general *g)
{
	ft_exit(g);
}
