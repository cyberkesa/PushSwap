#include "push_swap.h"

int	find_neighbour_up(t_general *g, int b_elem) //под него
{
	int	neighbour;

	neighbour = get_pos_elem(g->array, g->sort_array[b_elem - 1]);
	printf("up: %d\n", neighbour);
	return (neighbour);
}

int	find_neighbour_down(t_general *g, int b_elem) //над ним
{
	int	neighbour;

	neighbour =	get_pos_elem(g->array, g->sort_array[b_elem + 1]);
	printf("down: %d\n", neighbour);
	return (neighbour);
}

void	kubik_rubic(t_general *g)
{
	size_t	it_b;
	size_t	it_a;
	size_t	i;

	int		current_b;
	int		a;
	int		b;
	int		c;

	i = 0;
	a = 1;
	while (a != g->len_argc + 1)
	{
		current_b = get_pos_elem(g->stack_b, g->sort_array[a]);
		printf("INDEX:	%d[%s]\n", current_b, g->sort_array[a]);
		b = find_neighbour_up(g, a);
		c = find_neighbour_down(g, a);
		printf("		%d %d\n", b, c);

		printf("up:	%d\n", get_min_way(g->array, b));
		printf("down:	%d\n", get_min_way(g->array, c));
		just_rotate_a(g, g->array, c);
		just_rotate_b(g, g->stack_b, get_min_way(g->stack_b, current_b));
		pa_ins(g);
		// break ;
		a += 2;
	}
	print_array(g->array, "A res");
	print_array(g->stack_b, "B res");

	//для каждого current elem_b нужно найти соседей -- младшего и старшего
	// вычислить, какой сосед будет ближе, выбрать лучшее действие

	//затем сделать так для каждого элемента массива

	//сравнить лучшее из двух действий для каждого элемента и выбрать лучшее

	//повторить пока массив не опустеет)))))))))))))

	// а там и посмотрим что из этого вышло
	complete_sort(g);
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
		just_rotate_a(g, g->array, rotate);
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
		|| get_pos_elem(g->sort_array, g->array[0]) == 49
		|| get_pos_elem(g->sort_array, g->array[0]) == 51
		|| get_pos_elem(g->sort_array, g->array[0]) == 53
		|| get_pos_elem(g->sort_array, g->array[0]) == 55
		|| get_pos_elem(g->sort_array, g->array[0]) == 57
		|| get_pos_elem(g->sort_array, g->array[0]) == 59
		|| get_pos_elem(g->sort_array, g->array[0]) == 61
		|| get_pos_elem(g->sort_array, g->array[0]) == 63
		|| get_pos_elem(g->sort_array, g->array[0]) == 65
		|| get_pos_elem(g->sort_array, g->array[0]) == 67
		|| get_pos_elem(g->sort_array, g->array[0]) == 69
		|| get_pos_elem(g->sort_array, g->array[0]) == 71
		|| get_pos_elem(g->sort_array, g->array[0]) == 73
		|| get_pos_elem(g->sort_array, g->array[0]) == 75
		|| get_pos_elem(g->sort_array, g->array[0]) == 77
		|| get_pos_elem(g->sort_array, g->array[0]) == 79
		|| get_pos_elem(g->sort_array, g->array[0]) == 81
		|| get_pos_elem(g->sort_array, g->array[0]) == 83
		|| get_pos_elem(g->sort_array, g->array[0]) == 85
		|| get_pos_elem(g->sort_array, g->array[0]) == 87
		|| get_pos_elem(g->sort_array, g->array[0]) == 89
		|| get_pos_elem(g->sort_array, g->array[0]) == 91
		|| get_pos_elem(g->sort_array, g->array[0]) == 93
		|| get_pos_elem(g->sort_array, g->array[0]) == 95
		|| get_pos_elem(g->sort_array, g->array[0]) == 97
		|| get_pos_elem(g->sort_array, g->array[0]) == 99
		|| get_pos_elem(g->sort_array, g->array[0]) == 101)
		{
			pb_ins(g);
			num_stack_b++;
		}
		else
		{
			if (get_len_array(g->stack_b) > 50)
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
