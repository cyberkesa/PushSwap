#include "push_swap.h"

char	**qs_swap(char **array, size_t a, size_t b)
{
	char	*tmp;

	tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
	return (array);
}

char	**quick_sort_arr(char **array, int b, int e)
{
	int	l = b;
	int	r = e;
	int		pivot;

	pivot = ft_atoi(array[(l + r) / 2]);
	while (l <= r)
	{
		while (ft_atoi(array[l]) < pivot)
			l++;
		while (ft_atoi(array[r]) > pivot)
			r--;
		if (l <= r)
			array = qs_swap(array, l++, r--);
	}
	if (b < r)
		quick_sort_arr(array, b, r);
	if (e > l)
		quick_sort_arr(array, l, e);
	return (array);
}
