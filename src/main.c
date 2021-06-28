#include "push_swap.h"

void	push_swap(t_general *g)
{
	if (check_sort(g->array) == 0)
		complete_sort(g);
	g->sort_array = quick_sort_arr(g->sort_array, 0,
	get_len_array(g->sort_array) - 1);
	g->middle = get_middle_values(g->sort_array,
	get_len_array(g->sort_array));
	if (g->len_argc == 3)
		alg_three(g);
	else if (g->len_argc > 3 && g->len_argc < 6)
		alg_five(g);
	else if (g->len_argc > 5)
	{
		push_a(g);
		all_night(g);
	}
	complete_sort(g);
}

int	main(int ac, char **av)
{
	t_general	g;
	t_list	*lst;

	ft_bzero(&g, sizeof(t_general));
	errors_detected(&g, ac, av);
	push_swap(&g);
	return (0);
}
