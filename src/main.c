#include "push_swap.h"

void	complete_sort(t_general *g)
{
	free(g->a);
	free(g->b);
	free(g->sort);
	free(g->unliss);
	exit (0);
}

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
	if (check_sort(g->a) == 0)
		complete_sort(g);
	g->sort = quick_sort_arr(g->sort, 0,
			get_len_array(g->sort) - 1);
	g->middle = get_middle_values(g->sort,
			get_len_array(g->sort));
	if (g->len_argc < 4)
		alg_three(g);
	if (g->len_argc > 3 && g->len_argc < 6)
		alg_five(g);
	else if (g->len_argc > 5)
	{
		push_a(g);
		all_night(g);
	}
}

void	all_night(t_general *g)
{
	while (get_len_array(g->b) ^ 0)
		back_push(g);
	if (check_polusort_stack_a(g->a) == 1 && get_len_array(g->b) == 0)
		just_rotate_a(g, g->a, rotate_master(g->a, 'a'));
	complete_sort(g);
}

int	main(int ac, char **av)
{
	t_general	g;
	t_list		*lst;

	if (ac < 2)
		exit(0);
	check_errors(av);
	ft_bzero(&g, sizeof(t_general));
	parse_number_values(&g, av);
	make_array_values(&g, av);
	check_doubles_arr(g.a);
	push_swap(&g);
	return (0);
}
