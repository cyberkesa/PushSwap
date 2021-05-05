#include "push_swap.h"

// int	len_int(int *b)
// {
// 	int	i;

// 	i = 0;
// 	while (b != '\0')
// 		i++;
// 	return (i);
// }

// char	**my_lis(char **array, char *root)
// {
// 	size_t	len;

// 	len = 10;
// 	char	*lis_array[len];
// 	char	*maybe_lis[len];

// 	size_t	i;

// 	i = get_pos_elem(array, root); //затем проверять остаток (< root_pos (rotate))
// 	maybe_lis[0] = root;
// 	size_t	len_arr = get_len_array(array);
// 	while (array[i + 1])
// 	{
// 		int a = 0;
// 		if (ft_atoi(array[i + 1]) > ft_atoi(root))
// 		{
// 			if (i != len_arr - 2)
// 			{
// 				if (!(ft_atoi(array[i + 2]) > ft_atoi(root) && ft_atoi(array[i + 2]) < ft_atoi(array[i + 1])))
// 				{
// 					maybe_lis[a] = array[i + 1];
// 					root = maybe_lis[a];
// 					printf("maybe_lis[a] %s\n", maybe_lis[a]);
// 					a++;
// 				}
// 			}
// 			else
// 			{
// 				maybe_lis[a] = array[i + 1];
// 				root = maybe_lis[a];
// 				printf("maybe_lis[a] %s\n", maybe_lis[a]);
// 				a++;
// 			}
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// void	delete_sort_arr(t_general *g)
// {
// 	size_t	i;

// 	i = 0;

// 	while (g->sort_array[i])
// 	{
// 		if (ft_atoi(g->sort_array[i]) == 1 ||
// 			ft_atoi(g->sort_array[i]) == 2 ||
// 			ft_atoi(g->sort_array[i]) == 3 ||
// 			ft_atoi(g->sort_array[i]) == 4 ||
// 			ft_atoi(g->sort_array[i]) == 5 ||
// 			ft_atoi(g->sort_array[i]) == 6 ||
// 			ft_atoi(g->sort_array[i]) == 7 ||
// 			ft_atoi(g->sort_array[i]) == 8 ||
// 			ft_atoi(g->sort_array[i]) == 9 ||
// 			ft_atoi(g->sort_array[i]) == 10 ||
// 			ft_atoi(g->sort_array[i]) == 20)
// 				g->sort_array[i] = "9999";
// 		i++;
// 	}
// 	quick_sort_arr(g->sort_array, 0, get_len_array(g->sort_array) - 1);
// 	print_light_array(g->sort_array);
// 	i = 0;
// 	while (i != 10)
// 	{
// 		g->new_arr[i] = g->sort_array[i];
// 		i++;
// 	}
// 	print_light_array(g->new_arr);

// }

// void	mark_up(t_general *g)
// {
// 	char	*LOL[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "20"};
// 	size_t	i;
// 	i = 0;
// 	int	rot[100];
// 	int	cr;
// 	int	a;

// 	if (g->len_argc > 5 && g->len_argc < 250)
// 		cr = 10;
// 	else if (g->len_argc > 250 && g->len_argc < 800)
// 		cr = 50;
// 	if (check_polusort_stack_a(g->array) == 1 && get_len_array(g->stack_b) == 0)
// 		just_rotate_a(g, g->array, rotate_master(g->array, 'a'));
// 	else if (check_polusort_stack_a(g->array) == 1 && check_polusort_stack_a(g->stack_b) == 1)
// 		insert_sorts(g);
// 	delete_sort_arr(g);
// 	while (i != g->len_argc - 10)
// 	{
// 		if (check_sort(g->array) == 0)
// 			break ;
// 		if (get_len_array(g->array) >= cr)
// 		{
// 			while (get_len_array(g->stack_b) != (i + cr))
// 			{
// 				a = 0;
// 				while (a != cr)
// 				{
// 					rot[a] = get_min_way(g->array, get_pos_elem(g->array, g->new_arr[i + a]));
// 					a++;
// 				}
// 				push_b_with_rotate(g, g->array, rot[rot_find_min(rot, cr)]);
// 			}
// 			i += cr;
// 		}
// 		// else
// 		// {
// 		// 	int	remain;
// 		// 	int	remain_2;

// 		// 	remain = get_len_array(g->array);
// 		// 	remain_2 = remain;
// 		// 	while (remain_2-- != 0)
// 		// 	{
// 		// 		a = 0;
// 		// 		while (a != remain)
// 		// 		{
// 		// 			rot[a] = get_min_way(g->array, get_pos_elem(g->array, g->sort_array[i + a]));
// 		// 			a++;
// 		// 		}
// 		// 		push_b_with_rotate(g, g->array, rot[rot_find_min(rot, a)]);
// 		// 	}
// 		// 	i += remain;
// 		// }
// 	}
// 	ra_ins(g);
// 	ra_ins(g);
// 	ra_ins(g);
// 	// kubik_rubic(g);
// 	print_array(g->array, "Stack A");
// 	print_array(g->stack_b, "Stack B");
// }

