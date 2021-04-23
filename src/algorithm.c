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

// void	super_algorithm(t_general *g)
// {
// 	size_t	i;
// 	int	rotate;

// 	i = 0;

// 	if (ft_atoi(g->array[3]) == ft_atoi(g->sort_array[0])
// 		&& ft_atoi(g->array[0]) > ft_atoi(g->array[1]) && g->len_argc == 5)
// 		sa_ins(g);
// 	if (check_polusort_stack_a(g->array) == 1 && get_len_array(g->stack_b) == 0)
// 	{
// 		rotate = rotate_master(g->array, 'a');
// 		just_rotate(g, g->array, rotate);
// 	}
// 	else if (check_polusort_stack_a(g->array) == 1 && check_polusort_stack_a(g->stack_b) == 1)
// 		insert_sorts(g);
// 	while (i != g->len_argc)
// 	{
// 		if (check_sort(g->array) == 0)
// 			break ;
// 		rotate = get_min_way(g->array, get_pos_elem(g->array, g->sort_array[i]));
// 		push_b_with_rotate(g, g->array, rotate);
// 		if (ft_atoi(g->array[0]) > ft_atoi(g->array[1]))
// 			sa_ins(g);
// 		i++;
// 	}
// 	while (get_len_array(g->stack_b) != 0)
// 		pb_ins(g);
// 	complete_sort(g);
// }

// void	back_to_you(t_general *g);

int	rot_find_min(int *array)
{
	int	pos;
	int	min;
	int	len;
	int	i;

	i = 0;
	pos = 0;
	len = 10;
	min = (abs)(array[0]);
	while (len--)
	{
		if ((abs)(array[i]) < min)
		{
			min = (abs)(array[i]);
			pos = i;
		}
		i++;
	}
	return (pos);
}

void	super_algorithm(t_general *g)
{
	size_t	i;
	int	rotate_1;
	int	rotate_2;
	int	rotate_3;
	int	rotate_4;
	int	rotate_5;
	int	rotate_6;
	int	rotate_7;
	int	rotate_8;
	int	rotate_9;
	int	rotate_10;
	// int	rotate_11;
	// int	rotate_12;
	// int	rotate_13;
	// int	rotate_14;
	// int	rotate_15;
	// int	rotate_16;
	// int	rotate_17;
	// int	rotate_18;
	// int	rotate_19;
	// int	rotate_20;

	i = 0;

	if (check_polusort_stack_a(g->array) == 1 && get_len_array(g->stack_b) == 0)
	{
		int rotate;
		rotate = rotate_master(g->array, 'a');
		just_rotate(g, g->array, rotate);
	}
	else if (check_polusort_stack_a(g->array) == 1 && check_polusort_stack_a(g->stack_b) == 1)
		insert_sorts(g);

	while (i != g->len_argc)
	{
		if (check_sort(g->array) == 0)
			break ;
		while (get_len_array(g->stack_b) != (i + 10))
		{
			rotate_1 = get_min_way(g->array, get_pos_elem(g->array, g->sort_array[i]));
			rotate_2 = get_min_way(g->array, get_pos_elem(g->array, g->sort_array[i + 1]));
			rotate_3 = get_min_way(g->array, get_pos_elem(g->array, g->sort_array[i + 2]));
			rotate_4 = get_min_way(g->array, get_pos_elem(g->array, g->sort_array[i + 3]));
			rotate_5 = get_min_way(g->array, get_pos_elem(g->array, g->sort_array[i + 4]));
			rotate_6 = get_min_way(g->array, get_pos_elem(g->array, g->sort_array[i + 5]));
			rotate_7 = get_min_way(g->array, get_pos_elem(g->array, g->sort_array[i + 6]));
			rotate_8 = get_min_way(g->array, get_pos_elem(g->array, g->sort_array[i + 7]));
			rotate_9 = get_min_way(g->array, get_pos_elem(g->array, g->sort_array[i + 8]));
			rotate_10 = get_min_way(g->array, get_pos_elem(g->array, g->sort_array[i + 9]));
			// rotate_11 = get_min_way(g->array, get_pos_elem(g->array, g->sort_array[i + 10]));
			// rotate_12 = get_min_way(g->array, get_pos_elem(g->array, g->sort_array[i + 11]));
			// rotate_13 = get_min_way(g->array, get_pos_elem(g->array, g->sort_array[i + 12]));
			// rotate_14 = get_min_way(g->array, get_pos_elem(g->array, g->sort_array[i + 13]));
			// rotate_15 = get_min_way(g->array, get_pos_elem(g->array, g->sort_array[i + 14]));
			// rotate_16 = get_min_way(g->array, get_pos_elem(g->array, g->sort_array[i + 15]));
			// rotate_17 = get_min_way(g->array, get_pos_elem(g->array, g->sort_array[i + 16]));
			// rotate_18 = get_min_way(g->array, get_pos_elem(g->array, g->sort_array[i + 17]));
			// rotate_19 = get_min_way(g->array, get_pos_elem(g->array, g->sort_array[i + 18]));
			// rotate_20 = get_min_way(g->array, get_pos_elem(g->array, g->sort_array[i + 19]));
			// printf("%d	", (abs)(rotate_1));
			// printf("%d	", (abs)(rotate_2));
			// printf("%d	", (abs)(rotate_3));
			// printf("%d	", (abs)(rotate_4));
			// printf("%d	", (abs)(rotate_5));
			// printf("%d	", (abs)(rotate_6));
			// printf("%d	", (abs)(rotate_7));
			// printf("%d	", (abs)(rotate_8));
			// printf("%d	", (abs)(rotate_9));
			// printf("%d	", (abs)(rotate_10));
			int	rot[21];
			rot[0] = rotate_1;
			rot[1] = rotate_2;
			rot[2] = rotate_3;
			rot[3] = rotate_4;
			rot[4] = rotate_5;
			rot[5] = rotate_6;
			rot[6] = rotate_7;
			rot[7] = rotate_8;
			rot[8] = rotate_9;
			rot[9] = rotate_10;
			// rot[10] = rotate_11;
			// rot[11] = rotate_12;
			// rot[12] = rotate_13;
			// rot[13] = rotate_14;
			// rot[14] = rotate_15;
			// rot[15] = rotate_16;
			// rot[16] = rotate_17;
			// rot[17] = rotate_18;
			// rot[18] = rotate_19;
			// rot[20] = rotate_20;
			if ((abs)(rot[0]) == 1 && (abs)(rot[1]) == 1
				&& (abs)(rot[2]) == 1 && (abs)(rot[3]) == 1
				&& (abs)(rot[4]) == 1 && (abs)(rot[5]) == 1
				&& (abs)(rot[6]) == 1 && (abs)(rot[7]) == 1
				&& (abs)(rot[8]) == 1 && (abs)(rot[9]) == 1)
					break;
			int pos_in_rot = rot_find_min(rot);
			// printf("pos_in_rot %d\n", pos_in_rot);
			push_b_with_rotate(g, g->array, rot[pos_in_rot]);
		}
		// if ((abs)(rotate_second) < (abs)(rotate))
		// 	push_b_with_rotate(g, g->array, rotate_second);
		// else
		// 	push_b_with_rotate(g, g->array, rotate);
		i += 10;
	}
	// while (get_len_array(g->stack_b) != 0)
	// 	pb_ins(g);
	back_to_you(g);
	print_array(g->stack_b, "Kek");
	// complete_sort(g);
}
