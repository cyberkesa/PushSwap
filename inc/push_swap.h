#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef	struct	s_num_ins
{
	char		*number;
	int			stack_a_rotate;	//waiting
	int			stack_b_rotate;	//waiting
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
	size_t		len_argc;
	size_t		len_arr;
	size_t		len_liss;
	size_t		ins_num;
	char		**array;
	char		**lis;
	char		**new_sort_unliss;
	char		**sort_array;
	char		**stack_b;
	char		*middle;
	int			flag;

}				t_general;

void	push_a(t_general *g);
void	my_best(t_general *g);
void		all_night(t_general *g);
int				main(int ac, char **av);
void			ft_exit(t_general *g);
void			free_array(char **r);
void			complete_sort(t_general *g);
void			parse_number_values(t_general *general, char **av);
int				just_rotate(t_general *g, char **array, int rotate);
void			ft_error(char *str);
void			make_array_values(t_general *general, char **av);
void			print_array(char **array, char *s);
void			print_light_array(char **array, int target);
void			print_list(t_list *lst);
void			check_doubles_arr(char **array);
char			**quick_sort_arr(char **array, int b, int e);
void			merge_sort_arr(t_general *general);
int				check_sort(char **array);
void			push_swap(t_general *general);
size_t			get_len_array(char **array_for_size);
int				get_pos_elem(char **array, char *elem);
char			*get_middle_values(char **array_for_find, size_t lens);
int				get_min_way(char **array, size_t pos_elem);
void			alg_three(t_general *g);
void			alg_five(t_general *g);

void			ra_ins(t_general *general);
void			rra_ins(t_general *general);
void			rb_ins(t_general *general);
void			rrb_ins(t_general *general);
void			rr_ins(t_general *general);
void			rrr_ins(t_general *general);
void			sa_ins(t_general *general);
void			sb_ins(t_general *general);
void			ss_ins(t_general *general);
void			pa_ins(t_general *general);
void			pb_ins(t_general *general);
void			add_elem(char *elem, char **array);

void			push_realloc(int check, char **array);
int				rotate_master(char **array, char ab);
int				get_current_min(char **array);
int				get_current_max(char **array);
int				check_polusort_stack_a(char **array);
int				check_polusort_stack_b(char **array);


int				maybe_sa(char **array);
void			super_algorithm(t_general *g);
int				insert_sorts(t_general *g);
int				push_b_with_rotate(t_general *g, char **array, int rotate);


void			new_alg(t_general *g);
void			back_to_you(t_general *g);


int	just_rotate_a(t_general *g, char **array, int rotate);
int	just_rotate_b(t_general *g, char **array, int rotate);
int	push_a_with_rotate(t_general *g, char **array, int rotate);
int	push_b_with_rotate(t_general *g, char **array, int rotate);
void	new_super(t_general *g);
int	rot_find_min(int *array, int len);
void	kubik_rubic(t_general *g);
void	mark_up(t_general *g);
void	main_lis(t_general *g);
void	next_from_lis(t_general *g);
int		check_lises(t_general *g, char *elem);
void	back_in_a(t_general *g);
void	back_push(t_general *g);

#endif
