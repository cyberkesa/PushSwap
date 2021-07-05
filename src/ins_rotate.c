#include "push_swap.h"

void	ra_ins(t_general *g)
{
	size_t	len;
	size_t	i;
	size_t	a;
	char	*tmp;

	len = get_len_array(g->a);
	i = 0;
	a = 1;
	tmp = g->a[0];
	while (g->a[i])
	{
		g->a[i] = g->a[a];
		i++;
		a++;
	}
	g->a[i - 1] = tmp;
	g->number_ins++;
	write(1, "ra\n", 3);
}

void	rb_ins(t_general *g)
{
	size_t	len;
	size_t	i;
	size_t	b;
	char	*tmp;

	len = get_len_array(g->b);
	i = 0;
	b = 1;
	tmp = g->b[0];
	while (g->b[i])
	{
		g->b[i] = g->b[b];
		i++;
		b++;
	}
	g->b[i - 1] = tmp;
	g->number_ins++;
	write(1, "rb\n", 3);
}

void	rra_ins(t_general *g)
{
	size_t	len;
	char	*tmp;

	len = get_len_array(g->a);
	tmp = g->a[len - 1];
	while (--len)
		g->a[len] = g->a[len - 1];
	g->a[0] = tmp;
	g->number_ins++;
	write(1, "rra\n", 4);
}

void	rrb_ins(t_general *g)
{
	size_t	len;
	char	*tmp;

	len = get_len_array(g->b);
	tmp = g->b[len - 1];
	while (--len)
		g->b[len] = g->b[len - 1];
	g->b[0] = tmp;
	g->number_ins++;
	write(1, "rrb\n", 4);
}
