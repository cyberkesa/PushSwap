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
	free(g->a);
	free(g->b);
	free(g->sort);
	free(g->unliss);
	exit (0);
}

void	complete_sort(t_general *g)
{
	ft_exit(g);
}
