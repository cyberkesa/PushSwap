#include "push_swap.h"

void	super_lis(char **array, t_general *g, int root)
{
	size_t	i;
	size_t	a;

	i = root;
	a = 1;
	g->lis = (char **)malloc(sizeof(char *) * (get_len_array(array) + 1));
	g->lis[0] = array[root];
	g->lis[1] = NULL;
	while (array[i + 1] != NULL)
	{
		if (ft_atoi(array[i]) > find_last_elem(g->lis))
			if (ft_atoi(array[i]) <= ft_atoi(g->sort_array[(get_pos_elem(g->sort_array,
							array[i])) % get_len_array(g->sort_array)]))
			{
				g->lis[a] = array[i];
				g->lis[a + 1] = NULL;
				a++;
			}
		i++;
	}
	i = 0;
	while (i != root + 1)
	{
		if (ft_atoi(array[i]) > find_last_elem(g->lis))
			if (ft_atoi(array[i]) <= ft_atoi(g->sort_array[(get_pos_elem(g->sort_array,
							array[i])) % get_len_array(g->sort_array)]))
			{
				g->lis[a] = array[i];
				g->lis[a + 1] = NULL;
				a++;
			}
		i++;
	}
}

void	main_lis(t_general *g)
{
	size_t	root;
	size_t	len_lis;
	size_t	best_root;

	len_lis = 0;
	root = 0;
	while (root != get_len_array(g->array))
	{
		super_lis(g->array, g, root);
		if (len_lis <= get_len_array(g->lis))
		{
			best_root = root;
			len_lis = get_len_array(g->lis);
		}
		free(g->lis);
		root++;
	}
	super_lis(g->array, g, best_root);
	g->len_liss = len_lis;
}
