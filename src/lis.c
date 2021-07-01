#include "push_swap.h"

void	super_lis_2(t_general *g, size_t i, int root, size_t a)
{
	while (i != root + 1)
	{
		if (ft_atoi(g->a[i]) > find_last_elem(g->lis))
		{
			if (ft_atoi(g->a[i]) <= ft_atoi(g->sort[
						(get_pos_elem(g->sort,
								g->a[i])) % get_len_array(g->sort)]))
			{
				g->lis[a] = g->a[i];
				g->lis[a + 1] = NULL;
				a++;
			}
		}
		i++;
	}
}

int	super_lis_1(t_general *g, size_t i, size_t a)
{
	while (g->a[i + 1] != NULL)
	{
		if (ft_atoi(g->a[i]) > find_last_elem(g->lis))
		{
			if (ft_atoi(g->a[i]) <= ft_atoi(g->sort[
						(get_pos_elem(g->sort,
								g->a[i])) % get_len_array(g->sort)]))
			{
				g->lis[a] = g->a[i];
				g->lis[a + 1] = NULL;
				a++;
			}
		}
		i++;
	}
	return (a);
}

void	super_lis(t_general *g, int root)
{
	size_t	a;

	a = 1;
	g->lis = (char **)malloc(sizeof(char *) * (get_len_array(g->a) + 1));
	g->lis[0] = g->a[root];
	g->lis[1] = NULL;
	a = super_lis_1(g, root, 1);
	super_lis_2(g, 0, root, a);
}

void	main_lis(t_general *g)
{
	size_t	root;
	size_t	len_lis;
	size_t	best_root;

	len_lis = 0;
	root = 0;
	while (root != get_len_array(g->a))
	{
		super_lis(g, root);
		if (len_lis <= get_len_array(g->lis))
		{
			best_root = root;
			len_lis = get_len_array(g->lis);
		}
		free(g->lis);
		root++;
	}
	super_lis(g, best_root);
	g->len_liss = len_lis;
}
