#include "push_swap.h"

void	rra_rrr(t_general *g)
{
	size_t	len;
	char	*tmp;

	len = get_len_array(g->array);
	tmp = g->array[len - 1];
	while (--len)
		g->array[len] = g->array[len - 1];
	g->array[0] = tmp;
}

void	rrb_rrr(t_general *g)
{
	size_t	len;
	char	*tmp;

	len = get_len_array(g->stack_b);
	tmp = g->stack_b[len - 1];
	while (--len)
		g->stack_b[len] = g->stack_b[len - 1];
	g->stack_b[0] = tmp;
}

void	ra_rr(t_general *g)
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
}

void	rb_rr(t_general *g)
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
}
