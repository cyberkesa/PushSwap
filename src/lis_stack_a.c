#include "push_swap.h"

int		check_lises(t_general *g, char *elem)
{
	size_t	i;

	i = 0;
	while (g->lis[i] != NULL)
	{
		if (ft_atoi(g->lis[i]) == ft_atoi(elem))
			return (1);
		i++;
	}
	return (0);
}

char	**re_sort_array(t_general *g)
{
	char	**new_sort;
	size_t	i;
	size_t	a;

	i = 0;
	a = 0;
	new_sort = (char **)malloc(sizeof(char *) * (g->len_liss + 1));
	while (g->sort_array[i] != NULL)
	{
		if (check_lises(g, g->sort_array[i]) == 1)
		{
			printf("%p = %s\n", new_sort[a], g->sort_array[i]);
			new_sort[a] = g->sort_array[i];
			a++;
		}
		i++;
	}
	new_sort[a] = NULL;
	return (new_sort);
}

void	next_from_lis(t_general *g)
{
	g->new_sort_unliss = re_sort_array(g);
	print_array(g->new_sort_unliss, "LIS");
}
