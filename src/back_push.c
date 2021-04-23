#include "push_swap.h"

void	push_lol(t_general *general)
{
	char	**new_a;
	char	**new_b;
	size_t	len_a;
	size_t	len_b;
	size_t	i;
	size_t	a;

	len_a = get_len_array(general->lol);
	len_b = get_len_array(general->stack_b);
	if (len_b == 0)
		return;
	new_a = (char **)malloc(sizeof(char *) * (len_a + 2));
	new_b = (char **)malloc(sizeof(char *) * (len_b));

	i = 0;
	a = 1;
	while (a != len_b)
	{
		new_b[i] = general->stack_b[a];
		a++;
		i++;
	}
	new_b[i] = NULL;

	i = 1;
	a = 0;
	new_a[0] = general->stack_b[0];
	if (len_a > 0)
	{
		while (a != len_a)
		{
			new_a[i] = general->lol[a];
			a++;
			i++;
		}
		new_a[i] = NULL;
	}
	else
		new_a[1] = NULL;
	free(general->stack_b);
	free(general->lol);
	general->lol = new_a;
	general->stack_b = new_b;
	general->ins_num += 1;
	printf("push_lol\n");
}


int	push_a_with_rotate(t_general *g, char **array, int rotate)
{
	// printf("rotate: %d\n", rotate);
	// if (rotate == 1 && maybe_sa(array) == 1)
	// {
	// 	sb_ins(g);
	// 	pb_ins(g);
	// 	return (0);
	// }
	if (rotate > 0)
	{
		while (rotate--)
			rb_ins(g);
	}
	else if (rotate < 0)
	{
		while (rotate++ != 0)
			rrb_ins(g);
	}
	push_lol(g);
	return (rotate);
}

void	back_to_you(t_general *g)
{
	complete_sort(g);

	print_array(g->stack_b, "Pizda");
	//Здесь должен быть алгоритм, который скинет из стека B > в стек A
	//подставляя лучшие варианты


	size_t	i;
	int	rotate;

	i = 0;

	// if (ft_atoi(g->array[3]) == ft_atoi(g->sort_array[0])
	// 	&& ft_atoi(g->array[0]) > ft_atoi(g->array[1]) && g->len_argc == 5)
	// 	sa_ins(g);
	// if (check_polusort_stack_a(g->array) == 1 && get_len_array(g->stack_b) == 0)
	// {
	// 	rotate = rotate_master(g->array, 'a');
	// 	just_rotate(g, g->array, rotate);
	// }
	// else if (check_polusort_stack_a(g->array) == 1 && check_polusort_stack_a(g->stack_b) == 1)
	// 	insert_sorts(g);
	i =  g->len_argc;
	while (i != 0)
	{
		if (check_sort(g->stack_b) == 0)
			break ;
		rotate = get_min_way(g->stack_b, get_pos_elem(g->stack_b, g->sort_array[i]));
		push_a_with_rotate(g, g->stack_b, rotate);
		// if (ft_atoi(g->stack_b[0]) > ft_atoi(g->stack_b[1]))
		// 	sb_ins(g);
		i--;
	}
	while (get_len_array(g->stack_b) != 0)
		push_lol(g);
	print_array(g->array, "Final");
	print_array(g->stack_b, "Final B");
	print_array(g->lol, "lol");
	complete_sort(g);


	// printf("g->sort_array[g->len_argc]: %s\n", g->sort_array[g->len_argc - 1]);
	// int i = get_pos_elem(g->stack_b, g->sort_array[g->len_argc - 1]);
	// int a = get_min_way(g->stack_b, get_pos_elem(g->stack_b, g->sort_array[g->len_argc - 1]));
	// printf("i: %d\n", i);
	// printf("a: %d\n", a);

	// char	*elem = g->sort_array[g->len_argc - 2];
	// printf("g->sort_array[g->len_argc]: %s\n", elem);
	// i = get_pos_elem(g->stack_b, elem);
	// a = get_min_way(g->stack_b, get_pos_elem(g->stack_b, elem));
	// printf("i: %d\n", i);
	// printf("a: %d\n", a);

	// elem = g->sort_array[g->len_argc - 3];
	// printf("g->sort_array[g->len_argc]: %s\n", elem);
	// i = get_pos_elem(g->stack_b, elem);
	// a = get_min_way(g->stack_b, get_pos_elem(g->stack_b, elem));
	// printf("i: %d\n", i);
	// printf("a: %d\n", a);

	// elem = g->sort_array[g->len_argc - 4];
	// printf("g->sort_array[g->len_argc]: %s\n", elem);
	// i = get_pos_elem(g->stack_b, elem);
	// a = get_min_way(g->stack_b, get_pos_elem(g->stack_b, elem));
	// printf("i: %d\n", i);
	// printf("a: %d\n", a);

	// elem = g->sort_array[g->len_argc - 5];
	// printf("g->sort_array[g->len_argc]: %s\n", elem);
	// i = get_pos_elem(g->stack_b, elem);
	// a = get_min_way(g->stack_b, get_pos_elem(g->stack_b, elem));
	// printf("i: %d\n", i);
	// printf("a: %d\n", a);

	// elem = g->sort_array[g->len_argc - 6];
	// printf("g->sort_array[g->len_argc]: %s\n", elem);
	// i = get_pos_elem(g->stack_b, elem);
	// a = get_min_way(g->stack_b, get_pos_elem(g->stack_b, elem));
	// printf("i: %d\n", i);
	// printf("a: %d\n", a);

}
