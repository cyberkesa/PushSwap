#include "push_swap.h"

void	alg_three(t_general *g)
{
	if (check_polusort_stack_a(g->array) == 0)
		sa_ins(g);
	if (check_sort(g->array) == 0)
		complete_sort(g);
	if (g->array[0] == g->middle)
		rra_ins(g);
	else
		ra_ins(g);
}

void	alg_five(t_general *g)
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
	while (i != g->len_argc - 2)
	{
		while (get_pos_elem(g->sort_array, g->array[0]) > (g->len_argc / 2))
			ra_ins(g);
		if (ft_atoi(g->array[0]) > ft_atoi(g->array[1]))
		{
			sa_ins(g);
			i++;
		}
		if (check_sort(g->array) == 0 && get_len_array(g->stack_b) == 0)
			break ;
		rotate = get_min_way(g->array, get_pos_elem(g->array, g->sort_array[i]));
		printf("rotate: %d\n", rotate);
		print_array(g->array, "rotate check A");
		print_array(g->stack_b, "rotate check B");
		push_b_with_rotate(g, g->array, rotate);
		if (check_polusort_stack_a(g->array) == 1)
		{
			rotate = rotate_master(g->array, 'a');
			just_rotate(g, g->array, rotate);
		}
		i++;
	}
	// print_array(g->array, "check A");
	// print_array(g->stack_b, "check B");
	while (get_len_array(g->stack_b) != 0)
		pb_ins(g);
	printf("\nFinal sort: ");
	print_light_array(g->array);
	complete_sort(g);

}
