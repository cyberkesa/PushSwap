#include "push_swap.h"

int	check_polusort_stack_a(char **array)
{
	size_t	i;
	size_t	max;
	size_t	min;
	size_t len;

	i = 0;
	if (array[0] == NULL)
		return(-1);
	min = get_current_min(array);
	max = get_current_max(array);
	len = get_len_array(array);
	if (min == max + 1 || (min == 0 && max == len - 1))
	{
		i = min;
		while (array[i + 1])
		{
			if (ft_atoi(array[i]) < ft_atoi(array[i + 1]))
				i++;
			else
			{
				printf("Polusort A: NO!\n");
				return (0);
			}
		}
		if (max != 0)
		{
			if (min != 0)
			{
				while (i != min && array[i + 1])
				{
					if (ft_atoi(array[i]) < ft_atoi(array[i + 1]))
						i++;
					else
					{
						printf("Polusort A: NO!\n");
						return (0);
					}
				}
			}
		}
	}
	else
	{
		printf("Polusort A: NO!\n");
		return (0);
	}
	printf("Polusort A: OK!\n");
	return (1);
}

int	check_polusort_stack_b(char **array)
{
	size_t	i;
	size_t	max;
	size_t	min;
	size_t len;

	i = 0;
	if (array[0] == NULL)
		return(-1);
	min = get_current_min(array);
	max = get_current_max(array);
	len = get_len_array(array);
	if (max == min + 1 || (max == 0 && min == len - 1))
	{
		i = min;
		if (i > 1)
		{
			while (array[i - 1])
			{
				if (i == 1)
					break ;
				if (ft_atoi(array[i]) < ft_atoi(array[i - 1]))
					i--;
				else
				{
					printf("Polusort B: NO!\n");
					return (0);
				}
			}
		}
		if (max != 0)
		{
			if (min != 0)
			{
				i = max;
				while (array[i + 1])
				{
					if (ft_atoi(array[i]) > ft_atoi(array[i + 1]))
						i++;
					else
					{
						printf("Polusort B: NO!\n");
						return (0);
					}
				}
			}
		}
	}
	else
	{
		printf("Polusort B: NO!\n");
		return (0);
	}
	printf("Polusort B: OK!\n");
	return (1);
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

int	rotate_master(char **array, char ab)
{
	size_t	len;
	int	ra_x;
	int	rra_x;
	int	max;
	int	min;

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
	printf("ra: %d\n", ra_x);
	printf("rra: %d\n", rra_x);
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
			if (strcmp(array[next], array[current]) == 0)
				ft_error("Error, doubles element!\n");
			next++;
		}
		current++;
		next = 0;
	}
}

int	check_sort(char **array)
{
	size_t	i;
	size_t	tmpl;

	i = 0;
	tmpl = get_len_array(array) - 1;
	while (tmpl--)
	{
		if (array[i] == NULL)
			break ;
		if (ft_atoi(array[i]) < ft_atoi(array[i + 1]))
			i++;
		else
		{
			printf("Sort: ERROR\n");
			return (1);
		}
	}
	printf("Sort: OK\n");
	return (0);
}
