#include "push_swap.h"

void	ft_error(char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
		write(1, str, i);
	}
	exit (0);
}

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
		new_super(g);
		// new_alg(g);
		// super_algorithm(g);
}

int	main(int ac, char **av)
{
	t_general	g;
	t_list	*lst;

	if (ac < 4)
		ft_error("Error this number arguments.\n");
	printf("\x1b[H\x1b[J");
	ft_bzero(&g, sizeof(t_general));
	parse_number_values(&g, av);
	make_array_values(&g, av);
	check_doubles_arr(g.array);
	push_swap(&g);
	// print_array(g->sort_array, "Sort");
	return (0);
}
