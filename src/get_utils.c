#include "push_swap.h"

int		get_pos_elem(char **array, char *elem)
{
	int	pos;

	pos = 0;
	while (array[pos] != NULL)
	{
		if (ft_atoi(array[pos]) == ft_atoi(elem))
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

int	get_current_max(char **array)
{
	int	max;
	size_t	p;
	int	pos;
	int	i;

	max = ft_atoi(array[0]);
	p = 1;
	while (array[p] != NULL)
	{
		if (ft_atoi(array[p]) > max)
			max = ft_atoi(array[p]);
		p++;
	}
	pos = 0;
	i = 0;
	while (array[i] != NULL)
	{
		if (ft_atoi(array[i]) == max)
			pos = i;
		i++;
	}
	return (pos);
}

int	get_current_min(char **array)
{
	int	min;
	size_t	p;
	int	pos;
	int	i;

	p = 1;
	min = ft_atoi(array[0]);
	while (array[p] != NULL)
	{
		if (ft_atoi(array[p]) < min)
			min = ft_atoi(array[p]);
		p++;
	}
	pos = 0;
	i = 0;
	while (array[i] != NULL)
	{
		if (ft_atoi(array[i]) == min)
			pos = i;
		i++;
	}
	return (pos);
}
