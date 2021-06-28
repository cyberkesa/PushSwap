#include "push_swap.h"

int		find_last_elem(char **array)
{
	size_t	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	if (!i)
		return (-1);
	return (ft_atoi(array[i - 1]));
}

char	**super_lis(char **array, t_general *g, int root)
{
	char	**lis;
	size_t	i;
	size_t	a;
	int	meow;
	int	curent;

	i = root;
	a = 1;
	lis = (char **)malloc(sizeof(char *) * get_len_array(array));
	lis[0] = array[root];
	lis[1] = NULL;
	while (array[i + 1] != NULL)
	{
		if (ft_atoi(array[i]) > find_last_elem(lis))
		{
			meow = ft_atoi(g->sort_array[(get_pos_elem(g->sort_array,
			array[i])) % get_len_array(g->sort_array)]);
			if (ft_atoi(array[i]) <= meow)
			{
				lis[a] = array[i];
				lis[a + 1] = NULL;
				a++;
			}
		}
		i++;
	}
	i = 0;
	while (i != root + 1)
	{
		if (ft_atoi(array[i]) > find_last_elem(lis))
		{
			curent = ft_atoi(g->sort_array[(get_pos_elem(g->sort_array,
			array[i])) % get_len_array(g->sort_array)]);
			if (ft_atoi(array[i]) <= curent)
			{
				lis[a] = array[i];
				lis[a + 1] = NULL;
				a++;
			}
		}
		i++;
	}
	return (lis);
}

void	main_lis(t_general *g)
{
	size_t	root;
	size_t	len_lis;
	size_t	best_root;
	char	**lis;

	len_lis = 0;
	root = 0;
	while (root != get_len_array(g->array))
	{
		lis = super_lis(g->array, g, root);
		if (len_lis <= get_len_array(lis))
		{
			best_root = root;
			len_lis = get_len_array(lis);
		}
		free(lis);
		root++;
	}
	g->lis = super_lis(g->array, g, best_root);
	g->len_liss = len_lis;
}
