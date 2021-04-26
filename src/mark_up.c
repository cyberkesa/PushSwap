#include "push_swap.h"

int	len_int(int *b)
{
	int	i;

	i = 0;
	while (b != '\0')
		i++;
	return (i);
}

int	my_lis()
{
	int	a[10] = {1, 9, 6, 10, 7, 8, 5, 2, 4, 11};
	int	n = 11;
	int	i;
	int	j;
	int		prev[n - 1];
	int		d[n - 1];

	i = 0;
	while (i != n - 1)
	{
		d[i] = 1;
		prev[i] = -1;
		j = 0;
		while (j != n - 1)
		{
			if (a[j] < a[i] && d[j] + 1 > d[i])
			{
				d[i] = d[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		i++;
	}
	// printf("i: %d\n", i);
	int	pos = 0;
	printf("d[0]: %d\n", d[0]);
	int	length = d[0];
	while (i != n - 1)
	{
		if (d[i] > length)
		{
			pos = i;
			length = d[i];
		}
		i++;
	}

	int	answer[n];
	int		l;

	l = 0;
	while (pos != 0)
	{
		answer[l] = a[pos];
		pos = prev[pos];
		l++;
		// reverse(answer);
	}
	printf("%d\n", answer[0]);
	printf("%d\n", answer[1]);
	printf("%d\n", answer[2]);
	printf("%d\n", answer[3]);
	printf("%d\n", answer[4]);
	printf("%d\n", answer[5]);
	printf("%d\n", answer[6]);
	printf("%d\n", answer[7]);
	printf("%d\n", answer[8]);
	// printf("%d\n", answer[1]);
	// printf("%d\n", answer[2]);
	return (0);
}

char	*mark_ups[200];

void	mark(t_general *g, int base_elem)
{
	size_t	i;
	size_t	a;
	size_t	o;
	size_t	x;
	size_t	marks;
	int		start;

	i = 0;
	a = 1;
	o = 0;
	x = 0;
	marks = 0;


	mark_ups[0] = g->array[x];
	// start = g->array[base_elem];
	// int	in_sort = get_pos_elem(g->sort_array, g->array[base_elem]);
	while (g->array[i + 1] != NULL)
	{
		if (ft_atoi(g->array[base_elem]) < ft_atoi(g->array[base_elem + 1]))
		{
			mark_ups[a] = g->array[base_elem + 1];
			base_elem++;
			marks++;
		}
		i++;
	}
	printf("marks:	%zu\n", marks);
	print_light_array(mark_ups);

}

void	mark_up(t_general *g)
{
	// size_t	i;
	// int		rot[100];
	// int		cr;
	// int		a;

	// i = 0;
	my_lis();
	// mark(g, 0);
	// if (check_polusort_stack_a(g->array) == 1 && get_len_array(g->stack_b) == 0)
	// 	just_rotate_a(g, g->array, rotate_master(g->array, 'a'));
	// else if (check_polusort_stack_a(g->array) == 1 && check_polusort_stack_a(g->stack_b) == 1)
	// 	insert_sorts(g);
	// while (i != g->len_argc) //mark_up on false
	// {
	// 	mark(g);
	// 	maybe_sa(g->array);
	// 	if (get_pos_elem(g->sort_array, g->array[0]) > g->len_argc / 2)
	// 	{
	// 		pb_ins(g);
	// 	}
	// 	else
	// 		ra_ins(g);
	// 	i++;
	// }
	// print_array(g->array, "Stack A");
	// print_array(g->stack_b, "Stack B");
	// // kubik_rubic(g);
	// // back_to_you(g);
	// complete_sort(g);
}
