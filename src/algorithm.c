#include "push_swap.h"

int		maybe_sa(char **array)
{
	if (array[0] > array[1])
		return (1);
	return (0);
}

int		insert_sorts(t_general *g)
{
	if (check_sort(g->array) == 1
	&& get_len_array(g->stack_b) == 0)
		return (1);
	return (0);
}

int		get_min_way(char **array, size_t pos_elem)
{
	size_t	len;
	int	rotate;

	rotate = 0;
	len = get_len_array(array);
	if ((len / 2) < pos_elem)
		return (pos_elem);
	else if ((len / 2) >= pos_elem)
		return ((len - pos_elem) * -1);
	return (rotate);
}

void	check_sa(t_general *g, char **array)
{
	if (array[0] > array[1])
		sa_ins(g);
}

int		push_b_with_rotate(t_general *g, char **array, int rotate)
{
	printf("rotate: %d\n", rotate);
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
	check_sa(g, g->array);
	return (rotate);
}

void	super_algorithm(t_general *g)
{
	size_t	i;
	int	rotate;

	i = 0;
	if (check_polusort_stack_a(g->array) == 1)
	{
		rotate_master(g->array, 'a');
		
	}
	print_array(g->array);
	while (i != g->len_argc / 2)//get_pos_elem(g->sort_array, g->middle))
	{
		rotate = get_pos_elem(g->array, g->sort_array[i]);
		push_b_with_rotate(g, g->array, rotate);
		i++;
	}
	// printf("rotate: %d\n", rotate);
	print_array(g->array);
	print_array(g->stack_b);
}

void	push_swap(t_general *g)
{
	g->sort_array = quick_sort_arr(g->sort_array, 0, get_len_array(g->sort_array) - 1);
	g->middle = get_middle_values(g->sort_array, get_len_array(g->sort_array));
	print_array(g->array);
	super_algorithm(g);
	while (get_len_array(g->stack_b) != 0)
		pb_ins(g);
	print_array(g->array);
}
