#include "push_swap.h"

int	find_neighbour_small(t_general *g, int b_elem)
{
	int	neighbour;

	neighbour = get_pos_elem(g->stack_b, g->sort_array[b_elem - 1]);
	printf("small: %d\n", neighbour);
	return (0);
}

int	find_neighbour_big(t_general *g, int b_elem)
{
	int	neighbour;

	neighbour =	get_pos_elem(g->stack_b, g->sort_array[b_elem + 1]);
	printf("big: %d\n", neighbour);
	return (0);
}

void	kubik_rubic(t_general *g)
{
	size_t	it_b;
	size_t	it_a;
	size_t	i;

	int		current_b;
	int		a;

	i = 0;
	a = 1;
	while (a - 1 != g->len_argc)
	{
		current_b = get_pos_elem(g->stack_b, g->sort_array[a]);
		printf("current_b: %d\n", current_b);
		find_neighbour_small(g, a);
		find_neighbour_big(g, a);

		a += 2;
	}
	//для каждого current elem_b нужно найти соседей -- младшего и старшего
	// вычислить, какой сосед будет ближе, выбрать лучшее действие

	//затем сделать так для каждого элемента массива

	//сравнить лучшее из двух действий для каждого элемента и выбрать лучшее

	//повторить пока массив не опустеет)))))))))))))

	// а там и посмотрим что из этого вышло
}

void	new_alg(t_general *g)
{
	int	rotate;
	size_t	i;
	size_t	num_stack_b;
	int	median;

	i = 0;
	num_stack_b = 0;
	median = g->len_argc / 2;
	if (check_polusort_stack_a(g->array) == 1 && get_len_array(g->stack_b) == 0)
	{
		rotate = rotate_master(g->array, 'a');
		just_rotate(g, g->array, rotate);
	}
	while (get_len_array(g->stack_b) != median)
	{
		if (get_pos_elem(g->sort_array, g->array[0]) == 1
		|| get_pos_elem(g->sort_array, g->array[0]) == 3
		|| get_pos_elem(g->sort_array, g->array[0]) == 5
		|| get_pos_elem(g->sort_array, g->array[0]) == 7
		|| get_pos_elem(g->sort_array, g->array[0]) == 9
		|| get_pos_elem(g->sort_array, g->array[0]) == 11
		|| get_pos_elem(g->sort_array, g->array[0]) == 13
		|| get_pos_elem(g->sort_array, g->array[0]) == 15
		|| get_pos_elem(g->sort_array, g->array[0]) == 17
		|| get_pos_elem(g->sort_array, g->array[0]) == 19
		|| get_pos_elem(g->sort_array, g->array[0]) == 21
		|| get_pos_elem(g->sort_array, g->array[0]) == 23
		|| get_pos_elem(g->sort_array, g->array[0]) == 25
		|| get_pos_elem(g->sort_array, g->array[0]) == 27
		|| get_pos_elem(g->sort_array, g->array[0]) == 29
		|| get_pos_elem(g->sort_array, g->array[0]) == 31
		|| get_pos_elem(g->sort_array, g->array[0]) == 33
		|| get_pos_elem(g->sort_array, g->array[0]) == 35
		|| get_pos_elem(g->sort_array, g->array[0]) == 37
		|| get_pos_elem(g->sort_array, g->array[0]) == 39
		|| get_pos_elem(g->sort_array, g->array[0]) == 41
		|| get_pos_elem(g->sort_array, g->array[0]) == 43
		|| get_pos_elem(g->sort_array, g->array[0]) == 45
		|| get_pos_elem(g->sort_array, g->array[0]) == 47
		|| get_pos_elem(g->sort_array, g->array[0]) == 49)
		{
			pb_ins(g);
			num_stack_b++;
		}
		else
		{
			if (get_len_array(g->stack_b) > 21)
				break ;
			ra_ins(g);
		}
		print_array(g->array, "Stack A");
		print_array(g->stack_b, "Stack B");
		if (ft_atoi(g->array[0]) > ft_atoi(g->array[1])
			&& get_pos_elem(g->sort_array, g->array[0]) > median
			&& get_pos_elem(g->sort_array, g->array[1]) > median)
			{
				sa_ins(g);
			}
		if (get_len_array(g->stack_b) > 1)
		{
			if (num_stack_b == 2 && ft_atoi(g->stack_b[0]) < ft_atoi(g->stack_b[1])
				&& get_pos_elem(g->sort_array, g->stack_b[0]) < median
				&& get_pos_elem(g->sort_array, g->stack_b[1]) < median)
				{
					sb_ins(g);
					num_stack_b -= 2;
				}
		}
	}
	kubik_rubic(g);
}
