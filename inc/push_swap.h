#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_num_ins
{
	char		*number;
	int			stack_a_rotate;
	int			stack_b_rotate;
	int			ra;
	int			rb;
	int			rra;
	int			rrb;
	int			rr;
	int			rrr;
	int			count;
}				t_num_ins;

typedef struct s_general
{
	t_num_ins	*num_ins;
	char		**a;
	char		**b;
	char		**lis;
	char		**unliss;
	char		**sort;
	char		*middle;
	size_t		len_argc;
	size_t		len_arr;
	size_t		len_liss;
	size_t		number_ins;
	int			flag;
}				t_general;

void	free_array(char **r);
void	push_a(t_general *g);
void	all_night(t_general *g);
int		main(int ac, char **av);
void	ft_exit(t_general *g);
void	complete_sort(t_general *g);
void	parse_number_values(t_general *general, char **av);
int		just_rotate(t_general *g, char **array, int rotate);
void	ft_error(char *str);
void	make_array_values(t_general *general, char **av);
void	print_array(char **array, char *s);
void	print_light_array(char **array, int target);
void	check_doubles_arr(char **array);
char	**quick_sort_arr(char **array, int b, int e);
int		check_sort(char **array);
void	push_swap(t_general *general);
size_t	get_len_array(char **array_for_size);
int		get_pos_elem(char **array, char *elem);
char	*get_middle_values(char **array_for_find, size_t lens);
int		get_min_way(char **array, size_t pos_elem);
void	alg_three(t_general *g);
void	alg_five(t_general *g);
int		insert_sorts(t_general *g);
void	ra_ins(t_general *general);
void	rra_ins(t_general *general);
void	rb_ins(t_general *general);
void	rrb_ins(t_general *general);
void	rr_ins(t_general *general);
void	rrr_ins(t_general *general);
void	sa_ins(t_general *general);
void	sb_ins(t_general *general);
void	ss_ins(t_general *general);
void	pa_ins(t_general *general);
void	pb_ins(t_general *general);
int		rotate_master(char **array, char ab);
int		get_current_min(char **array);
int		get_current_max(char **array);
int		check_polusort_stack_a(char **array);
int		push_b_with_rotate(t_general *g, char **array, int rotate);
int		just_rotate_a(t_general *g, char **array, int rotate);
void	main_lis(t_general *g);
void	next_from_lis(t_general *g);
int		check_lises(t_general *g, char *elem);
void	back_push(t_general *g);
int		find_max_in_a(t_general *g);
int		find_min_in_a(t_general *g);
void	rb_rr(t_general *g);
void	ra_rr(t_general *g);
void	rra_rrr(t_general *g);
void	rrb_rrr(t_general *g);
void	get_best_alg(t_general *g, int i);
void	processing_ins(t_general *g, int i);
int		find_last_elem(char **array);
void	init_numbers(t_general *g);
void	init_struct(t_general *g);
void	alg_four(t_general *g);
void	check_errors(char **av);
char		*pf_itoa_base(unsigned long nbr, int base);

#endif
