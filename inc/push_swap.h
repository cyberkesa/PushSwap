#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_general
{
	size_t		len_argc;
	size_t		len_arr;
	size_t		ins_num;
	char		**array;
	char		**sort_array;
	char		**stack_b;
	char		*middle;

}				t_general;

int				main(int ac, char **av);
void			parse_number_values(t_general *general, char **av);
void			ft_error(char *str);
void			make_array_values(t_general *general, char **av);
void			print_array(char **array);
void			print_light_array(char **array);
void			print_list(t_list *lst);
void			check_doubles_arr(char **array);
char			**quick_sort_arr(char **array, int b, int e);
void			merge_sort_arr(t_general *general);
int				check_sort(char **array);
void			push_swap(t_general *general);
size_t			get_len_array(char **array_for_size);
size_t			get_pos_elem(char **array, char *elem);
char			*get_middle_values(char **array_for_find, size_t lens);
int				get_min_way(char **array, size_t pos_elem);

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

size_t			free_array(char **r);
void			push_realloc(int check, char **array);
int				rotate_master(char **array, char ab);
int				get_current_min(char **array);
int				get_current_max(char **array);
int				check_polusort_stack_a(char **array);
int				check_polusort_stack_b(char **array);


int				maybe_sa(char **array);
void			super_algorithm(t_general *g);
int				insert_sorts(t_general *g);
int				rotate_master(char **array, char ab);
int				get_current_min(char **array);



#endif
