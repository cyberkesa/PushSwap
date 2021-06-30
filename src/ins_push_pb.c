#include "push_swap.h"

void	pb_ins(t_general *g)
{
	char	**new_a;
	char	**new_b;
	size_t	len_a;
	size_t	len_b;
	size_t	i;
	size_t	a;

	len_a = get_len_array(g->array);
	len_b = get_len_array(g->stack_b);

	if (len_a == 0)
		return;
	new_a = (char **)malloc(sizeof(char *) * (len_a));
	new_b = (char **)malloc(sizeof(char *) * (len_b + 2));
	i = 0;
	a = 1;
	while (a != len_a)
	{
		new_a[i] = g->array[a];
		a++;
		i++;
	}
	new_a[i] = NULL;
	i = 1;
	a = 0;
	new_b[0] = g->array[0];
	if (len_b > 0)
	{
		while (a != len_b)
		{
			new_b[i] = g->stack_b[a];
			i++;
			a++;
		}
		new_b[i] = NULL;
	}
	else
		new_b[1] = NULL;
	free(g->stack_b);
	free(g->array);
	g->array = new_a;
	g->stack_b = new_b;
	g->number_ins++;
	printf("pb\n");
}
