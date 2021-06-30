#include "push_swap.h"

int	rotate_master(char **array, char ab)
{
	size_t	len;
	int		ra_x;
	int		rra_x;
	int		max;
	int		min;

	if (array[0] == NULL)
		return(-1);
	len = get_len_array(array);
	max = get_current_max(array);
	min = get_current_min(array);
	ra_x = 0;
	rra_x = 0;
	if ((len - min) > (int)(len / 2))
		ra_x = max + 1;
	if (len - min <= (int)(len / 2))
		rra_x = len - min;
	if (rra_x != 0)
		return (rra_x * -1);
	if (ra_x != 0)
		return (ra_x);
	return (0);
}

void	check_doubles_arr(char **array)
{
	size_t	current;
	size_t	next;
	size_t	len;

	len = get_len_array(array);
	current = 0;
	next = 0;
	while (current < len)
	{
		while (next < len)
		{
			if (next == current)
				next++;
			if (array[next] == NULL)
				return;
			if (ft_strcmp(array[next], array[current]) == 0)
				ft_error("Error, doubles element!\n");
			next++;
		}
		current++;
		next = 0;
	}
}
