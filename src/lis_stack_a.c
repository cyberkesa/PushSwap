#include "push_swap.h"

int	find_last_elem(char **array)
{
	size_t	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	if (!i)
		return (-1);
	return (ft_atoi(array[i - 1]));
}

int	check_lises(t_general *g, char *elem)
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

void	next_from_lis(t_general *g)
{
	size_t	i;
	size_t	a;

	i = 0;
	a = 0;
	g->unliss = (char **)malloc(sizeof(char *) * (g->len_liss + 1));
	while (g->sort[i] != NULL)
	{
		if (check_lises(g, g->sort[i]) == 1)
		{
			g->unliss[a] = g->sort[i];
			a++;
		}
		i++;
	}
	g->unliss[a] = NULL;
}
