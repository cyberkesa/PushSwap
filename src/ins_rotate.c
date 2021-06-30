#include "push_swap.h"

void	ra_ins(t_general *g)
{
	size_t	len;
	size_t	i;
	size_t	a;
	char	*tmp;

	len = get_len_array(g->array);
	i = 0;
	a = 1;
	tmp = g->array[0];
	while (g->array[i])
	{
		g->array[i] = g->array[a];
		i++;
		a++;
	}
	g->array[i - 1] = tmp;
	g->number_ins++;
	printf("ra\n");
}

void	rb_ins(t_general *g)
{
	size_t	len;
	size_t	i;
	size_t	b;
	char	*tmp;

	len = get_len_array(g->stack_b);
	i = 0;
	b = 1;
	tmp = g->stack_b[0];
	while (g->stack_b[i])
	{
		g->stack_b[i] = g->stack_b[b];
		i++;
		b++;
	}
	g->stack_b[i - 1] = tmp;
	g->number_ins++;
	printf("rb\n");
}

void	rra_ins(t_general *g)
{
	size_t	len;
	char	*tmp;

	len = get_len_array(g->array);
	tmp = g->array[len - 1];
	while (--len)
		g->array[len] = g->array[len - 1];
	g->array[0] = tmp;
	g->number_ins++;
	printf("rra\n");
}

void	rrb_ins(t_general *g)
{
	size_t	len;
	char	*tmp;

	len = get_len_array(g->stack_b);
	tmp = g->stack_b[len - 1];
	while (--len)
		g->stack_b[len] = g->stack_b[len - 1];
	g->stack_b[0] = tmp;
	g->number_ins++;
	printf("rrb\n");
}
