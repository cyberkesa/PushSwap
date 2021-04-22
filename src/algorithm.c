#include "push_swap.h"

int	maybe_sa(char **array)
{
	if (array[0] > array[1])
		return (1);
	return (0);
}

int	insert_sorts(t_general *g)
{
	if (check_sort(g->array) == 1
	&& get_len_array(g->stack_b) == 0)
		return (1);
	return (0);
}

int	check_sa(t_general *g, char **array)
{
	if (ft_atoi(array[0]) > ft_atoi(g->array[1]))
		return (1);
	return (0);
}

int	check_sb(t_general *g, char **array)
{
	if (array[0] < array[1])
		return (1);
	return (0);
}

int	push_b_with_rotate(t_general *g, char **array, int rotate)
{
	// printf("rotate: %d\n", rotate);
	if (rotate == 1 && maybe_sa(array) == 1)
	{
		sa_ins(g);
		pa_ins(g);
		return (0);
	}
	else if (rotate > 0)
	{
		while (rotate--)
			ra_ins(g);
	}
	else if (rotate < 0)
	{
		while (rotate++ != 0)
			rra_ins(g);
	}
	pa_ins(g);
	return (rotate);
}

int	just_rotate(t_general *g, char **array, int rotate)
{
	// printf("rotate: %d\n", rotate);
	if (rotate == 1 && maybe_sa(array) == 1)
	{
		sa_ins(g);
		return (0);
	}
	else if (rotate > 0)
	{
		while (rotate--)
			ra_ins(g);
	}
	else if (rotate < 0)
	{
		while (rotate++ != 0)
			rra_ins(g);
	}
	return (rotate);
}

void	super_algorithm(t_general *g)
{
	size_t	i;
	int	rotate;

	i = 0;
	if (check_polusort_stack_a(g->array) == 1 && get_len_array(g->stack_b) == 0)
	{
		rotate = rotate_master(g->array, 'a');
		just_rotate(g, g->array, rotate);
	}
	else if (check_polusort_stack_a(g->array) == 1 && check_polusort_stack_a(g->stack_b) == 1)
		insert_sorts(g);
	// print_array(g->array, "Stack A");
	// while (i - 1 != get_pos_elem(g->sort_array, g->middle))
	while (i != g->len_argc)
	{
		if (check_sort(g->array) == 0)
			break ;
		rotate = get_min_way(g->array, get_pos_elem(g->array, g->sort_array[i]));
		push_b_with_rotate(g, g->array, rotate);
		if (ft_atoi(g->array[0]) > ft_atoi(g->array[1]))
			sa_ins(g);
		i++;
	}
	// print_array(g->stack_b, "Stack B");
	// print_array(g->array, "Stack A");
	while (get_len_array(g->stack_b) != 0)
		pb_ins(g);
	// printf("\nFinal sort: ");
	// print_light_array(g->array);
	complete_sort(g);
}

// void	push_back_array(t_general *g)
// {
// 	while (get_len_array(g->stack_b) != 0)
// 		pb_ins(g);
// }

