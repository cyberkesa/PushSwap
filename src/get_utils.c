#include "push_swap.h"

int		get_pos_elem(char **array, char *elem)
{
	int	pos;

	pos = 0;
	while (array[pos] != NULL)
	{
		if (array[pos] == elem)
			return (pos);
		pos++;
	}
	return (-1);
}

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

