#include "push_swap.h"

size_t	get_len_array(char **array_for_size)
{
	size_t	len;

	len = 0;
	while (array_for_size[len] != NULL)
		len++;
	return (len);
}

char	*get_middle_values(char **array_for_find, size_t lens)
{
	return (array_for_find[(int)((get_len_array(array_for_find)) / 2)]);
}

int		maybe_sa(char **array)
{

}

int		insert_sorts(t_general *g)
{

}

int		rotate_master(char **array, char ab)
{

}

int		get_current_min(char **array)
{

}

int		get_pos_elem(char **array, char *elem)
{

}

void	super_algorithm(t_general *g)
{
	get_pos_elem()
}

void	push_swap(t_general *g)
{
	g->sort_array = quick_sort_arr(g->sort_array, 0, get_len_array(g->sort_array) - 1);
	g->middle = get_middle_values(g->sort_array, get_len_array(g->sort_array));
	super_algorithm(g);
}
