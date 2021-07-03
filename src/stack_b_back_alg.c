#include "push_swap.h"

void	alg_max(t_general *g, int i, int min, int current_number)
{
	g->num_ins[i].stack_a_rotate = get_min_way(g->a,
			get_pos_elem(g->a, pf_itoa_base(min, 10)));
	g->num_ins[i].stack_b_rotate = get_min_way(g->b,
			get_pos_elem(g->b, pf_itoa_base(current_number, 10)));
	g->num_ins[i].count = (abs)(g->num_ins[i].stack_a_rotate)
		+ (abs)(g->num_ins[i].stack_b_rotate);
}

void	alg_min(t_general *g, int i, int min, int current_number)
{
	g->num_ins[i].stack_a_rotate = get_min_way(g->a,
			get_pos_elem(g->a, pf_itoa_base(min, 10)));
	g->num_ins[i].stack_b_rotate = get_min_way(g->b,
			get_pos_elem(g->b, pf_itoa_base(current_number, 10)));
	g->num_ins[i].count = (abs)(g->num_ins[i].stack_a_rotate)
		+ (abs)(g->num_ins[i].stack_b_rotate);
}

void	alg_middle(t_general *g, int i, int res)
{
	g->num_ins[i].stack_a_rotate = get_min_way(g->a, res) + 1;
	g->num_ins[i].stack_b_rotate = get_min_way(g->b,
			get_pos_elem(g->b, g->num_ins[i].number));
	g->num_ins[i].count = (abs)(g->num_ins[i].stack_a_rotate)
		+ (abs)(g->num_ins[i].stack_b_rotate);
}

void	alg_else(t_general *g, int current_number, int i)
{
	int	a;
	int	res;

	a = 0;
	res = -1;
	while (a + 1 ^ get_len_array(g->a))
	{
		if (ft_atoi(g->a[a]) < current_number
			&& ft_atoi(g->a[a + 1]) > current_number)
			res = a;
		a++;
	}
	if (res == -1)
		if (ft_atoi(g->a[a]) < current_number
			&& ft_atoi(g->a[0]) > current_number)
			res = -1;
	alg_middle(g, i, res);
}

void	get_best_alg(t_general *g, int i)
{
	int	current_number;
	int	min;

	min = find_min_in_a(g);
	current_number = ft_atoi(g->num_ins[i].number);
	if (current_number > find_max_in_a(g))
		alg_max(g, i, min, current_number);
	else if (current_number < min)
		alg_min(g, i, min, current_number);
	else
		alg_else(g, current_number, i);
	processing_ins(g, i);
}
