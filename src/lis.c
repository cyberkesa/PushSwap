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

	lis = (char **)malloc(sizeof(char *) * get_len_array(array));
	size_t	i;
	size_t	a;
	i = root;
	a = 1;

	lis[0] = array[root];
	lis[1] = NULL;
	printf("\n");
	while (array[i + 1] != NULL)
	{
		if (ft_atoi(array[i]) > find_last_elem(lis))
		{
			int	meow = ft_atoi(g->sort_array[(get_pos_elem(g->sort_array, array[i])) % get_len_array(g->sort_array)]);
			if (ft_atoi(array[i]) <= meow)
			{
				printf("main:		[%d] <= %d\n", ft_atoi(array[i]), meow);
				lis[a] = array[i];
				lis[a + 1] = NULL;
				a++;
			}
			else
				printf("non main:	-%d- > %d\n", ft_atoi(array[i]), meow);
		}
		i++;
	}
	i = 0;
	while (i != root + 1)
	{
		if (ft_atoi(array[i]) > find_last_elem(lis))
		{
			int	curent = ft_atoi(g->sort_array[(get_pos_elem(g->sort_array, array[i])) % get_len_array(g->sort_array)]);
			if (ft_atoi(array[i]) <= curent)
			{
				printf("remain:		[%d] <= %d\n", ft_atoi(array[i]), curent);
				lis[a] = array[i];
				lis[a + 1] = NULL;
				a++;
			}
			else
				printf("non remain:	-%d- > %d\n", ft_atoi(array[i]), curent);
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
		printf("root: %zu\n", root);
		lis = super_lis(g->array, g, root);
		print_array(lis, "LIS");
		if (len_lis <= get_len_array(lis))
		{
			best_root = root;
			len_lis = get_len_array(lis);
		}
		free(lis);
		root++;
	}
	printf("Best root position:		%zu\n", best_root);
	printf("Root elem:			%s\n", g->array[best_root]);
	printf("Arguments len:			%zu\n", g->len_argc);
	printf("Lis len:			%zu\n", len_lis);
	printf("Array direction:		");
	print_light_array(g->array, best_root);
	printf("Longest Increasing Subsequence:	");
	print_light_array(g->lis = super_lis(g->array, g, best_root), -1);
	g->len_liss = len_lis;
}
