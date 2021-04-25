#include "push_swap.h"

void	new_super(t_general *g)
{
	size_t	i;
	i = 0;
	int	rot[100];
	int	cr;
	int	a;

	if (g->len_argc > 5 && g->len_argc < 250)
		cr = 10;
	else if (g->len_argc > 250 && g->len_argc < 800)
		cr = 50;
	if (check_polusort_stack_a(g->array) == 1 && get_len_array(g->stack_b) == 0)
		just_rotate_a(g, g->array, rotate_master(g->array, 'a'));
	else if (check_polusort_stack_a(g->array) == 1 && check_polusort_stack_a(g->stack_b) == 1)
		insert_sorts(g);
	while (i != g->len_argc)
	{
		if (check_sort(g->array) == 0)
			break ;
		if (get_len_array(g->array) >= cr)
		{
			while (get_len_array(g->stack_b) != (i + cr))
			{
				a = 0;
				while (a != cr)
				{
					rot[a] = get_min_way(g->array, get_pos_elem(g->array, g->sort_array[i + a]));
					a++;
				}
				push_b_with_rotate(g, g->array, rot[rot_find_min(rot, cr)]);
			}
			i += cr;
		}
		// else
		// {
		// 	int	remain;
		// 	int	remain_2;

		// 	remain = get_len_array(g->array);
		// 	remain_2 = remain;
		// 	while (remain_2-- != 0)
		// 	{
		// 		a = 0;
		// 		while (a != remain)
		// 		{
		// 			rot[a] = get_min_way(g->array, get_pos_elem(g->array, g->sort_array[i + a]));
		// 			a++;
		// 		}
		// 		push_b_with_rotate(g, g->array, rot[rot_find_min(rot, a)]);
		// 	}
		// 	i += remain;
		// }
	}
	print_array(g->array, "Stack A");
	print_array(g->stack_b, "Stack B");
	// back_to_you(g);
}
