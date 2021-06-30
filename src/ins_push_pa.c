#include "push_swap.h"

void	pa_1(t_general *g, char **new_a, char **new_b, size_t len_a)
{
	size_t	i;
	size_t	a;

	i = 1;
	a = 0;
	new_a[0] = g->stack_b[0];
	if (len_a > 0)
	{
		while (a != len_a)
		{
			new_a[i] = g->array[a];
			a++;
			i++;
		}
		new_a[i] = NULL;
	}
	else
		new_a[1] = NULL;
	free(g->stack_b);
	free(g->array);
	g->array = new_a;
	g->stack_b = new_b;
	g->number_ins++;
	printf("pa\n");
}

void	pa_ins(t_general *g)
{
	char	**new_a;
	char	**new_b;
	size_t	len_b;
	size_t	i;
	size_t	a;

	len_b = get_len_array(g->stack_b);
	if (len_b == 0)
		return ;
	new_a = (char **)malloc(sizeof(char *) * (get_len_array(g->array) + 2));
	new_b = (char **)malloc(sizeof(char *) * (len_b));
	i = 0;
	a = 1;
	while (a != len_b)
	{
		new_b[i] = g->stack_b[a];
		a++;
		i++;
	}
	new_b[i] = NULL;
	pa_1(g, new_a, new_b, get_len_array(g->array));
}
