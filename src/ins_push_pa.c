#include "push_swap.h"

void	pa_1(t_general *g, char **new_a, char **new_b, size_t len_a)
{
	size_t	i;
	size_t	a;

	i = 1;
	a = 0;
	new_a[0] = g->b[0];
	if (len_a > 0)
	{
		while (a != len_a)
		{
			new_a[i] = g->a[a];
			a++;
			i++;
		}
		new_a[i] = NULL;
	}
	else
		new_a[1] = NULL;
	free(g->b);
	free(g->a);
	g->a = new_a;
	g->b = new_b;
	g->number_ins++;
	write(1, "pa\n", 3);
}

void	pa_ins(t_general *g)
{
	char	**new_a;
	char	**new_b;
	size_t	len_b;
	size_t	i;
	size_t	a;

	len_b = get_len_array(g->b);
	if (len_b == 0)
		return ;
	new_a = (char **)malloc(sizeof(char *) * (get_len_array(g->a) + 2));
	new_b = (char **)malloc(sizeof(char *) * (len_b));
	i = 0;
	a = 1;
	while (a != len_b)
	{
		new_b[i] = g->b[a];
		a++;
		i++;
	}
	new_b[i] = NULL;
	pa_1(g, new_a, new_b, get_len_array(g->a));
}
