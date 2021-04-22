#include "push_swap.h"

int	get_min_way(char **array, size_t pos_elem)
{
	size_t	len;
	int	rotate;

	rotate = 0;
	len = get_len_array(array);
	if ((len / 2) < pos_elem)
		return ((len - pos_elem) * -1);
	else if ((len / 2) >= pos_elem)
		return (pos_elem);
	return (rotate);
}
