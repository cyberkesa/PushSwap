#include "push_swap.h"

size_t	get_len_array(char **array_for_size)
{
	size_t	len;

	len = 0;
	while (array_for_size[len] != NULL)
		len++;
	return (len);
}

char	*get_middle_values(char **array_for_find, size_t lens)
{
	return (array_for_find[(int)((get_len_array(array_for_find)) / 2)]);
}

void	super_algorithm(t_general *general)
{
	print_array(general->array);

	rotate_master(general->array, 'a');
	// rra_ins(general);
	print_array(general->array);

	check_polusort_stack_a(general->array);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	pa_ins(general);
	print_array(general->stack_b);
	check_polusort_stack_b(general->stack_b);
}

void	push_swap(t_general *general)
{
	general->sort_array = quick_sort_arr(general->sort_array, 0, get_len_array(general->sort_array) - 1);
	general->middle = get_middle_values(general->sort_array, get_len_array(general->sort_array));
	super_algorithm(general);
}
