#include "push_swap.h"

int	maybe_sa(char **array)
{
	if (ft_atoi(array[0]) > ft_atoi(array[1]))
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

int	just_rotate_a(t_general *g, char **array, int rotate)
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

int	just_rotate_b(t_general *g, char **array, int rotate)
{
	if (rotate == 1 && maybe_sa(array) == 1)
	{
		sb_ins(g);
		return (0);
	}
	else if (rotate > 0)
	{
		while (rotate--)
			rb_ins(g);
	}
	else if (rotate < 0)
	{
		while (rotate++ != 0)
			rrb_ins(g);
	}
	return (rotate);
}

int	rot_find_min(int *array, int len)
{
	int	pos;
	int	min;
	int	i;

	i = 0;
	pos = 0;
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
	i = 0;
	int	rot[100];
	int	cr;
	int	a;

	if (g->len_argc > 5 && g->len_argc < 250)
		cr = 25;
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
					rot[a] = get_min_way(g->array, get_pos_elem(g->array, g->new_sort_unliss[i + a]));
					a++;
				}
				push_b_with_rotate(g, g->array, rot[rot_find_min(rot, cr)]);
				printf("%d\n", rot[rot_find_min(rot, a)]);
			}
			i += cr;
			cr -= 3;
		}
		else
			i++;
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
		// 			rot[a] = get_min_way(g->array, get_pos_elem(g->array, g->new_sort_unliss[i + a]));
		// 			a++;
		// 		}
		// 		push_b_with_rotate(g, g->array, rot[rot_find_min(rot, a)]);
		// 		printf("%d\n", rot[rot_find_min(rot, a)]);
		// 	}
		// 	i += remain;
		// }
	}
	back_to_you(g);
}
