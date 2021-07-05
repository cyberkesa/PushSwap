#include "push_swap.h"

void	pb_1(t_general *g, char **new_a, char **new_b, size_t len_b)
{
	size_t	i;
	size_t	a;

	i = 1;
	a = 0;
	new_b[0] = g->a[0];
	if (len_b > 0)
	{
		while (a != len_b)
		{
			new_b[i] = g->b[a];
			i++;
			a++;
		}
		new_b[i] = NULL;
	}
	else
		new_b[1] = NULL;
	free(g->b);
	free(g->a);
	g->a = new_a;
	g->b = new_b;
	g->number_ins++;
	write(1, "pb\n", 3);
}

void	pb_ins(t_general *g)
{
	char	**new_a;
	char	**new_b;
	size_t	len_a;
	size_t	i;
	size_t	a;

	len_a = get_len_array(g->a);
	if (len_a == 0)
		return ;
	new_a = (char **)malloc(sizeof(char *) * (len_a));
	new_b = (char **)malloc(sizeof(char *) * (get_len_array(g->b) + 2));
	i = 0;
	a = 1;
	while (a != len_a)
	{
		new_a[i] = g->a[a];
		a++;
		i++;
	}
	new_a[i] = NULL;
	pb_1(g, new_a, new_b, get_len_array(g->b));
}
