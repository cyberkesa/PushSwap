#include "push_swap.h"

int	check_sort(char **array)
{
	size_t	i;
	size_t	tmpl;

	i = 0;
	if (get_len_array(array) == 0)
		return (1);
	tmpl = get_len_array(array) - 1;
	while (tmpl--)
	{
		if (array[i] == NULL)
			break ;
		if (ft_atoi(array[i]) < ft_atoi(array[i + 1]))
			i++;
		else
			return (1);
	}
	return (0);
}

int	polusort_1(char **array, size_t min, size_t max)
{
	size_t	i;

	i = min;
	while (array[i + 1])
	{
		if (ft_atoi(array[i]) < ft_atoi(array[i + 1]))
			i++;
		else
			return (0);
	}
	if (max != 0 && min ^ 0)
	{
		while (i != min && array[i + 1])
		{
			if (ft_atoi(array[i]) < ft_atoi(array[i + 1]))
				i++;
			else
				return (0);
		}
	}
	return (1);
}

int	polusort(char **array, size_t min, size_t max, size_t len)
{
	if (min == max + 1 || (min == 0 && max == len - 1))
		polusort_1(array, min, max);
	else
		return (0);
	return (1);
}

int	check_polusort_stack_a(char **array)
{
	size_t	max;
	size_t	min;
	size_t	len;

	if (array[0] == NULL)
		return (-1);
	min = get_current_min(array);
	max = get_current_max(array);
	len = get_len_array(array);
	return (polusort(array, min, max, len));
}
