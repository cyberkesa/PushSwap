#include "push_swap.h"

void				ft_error(char *str)
{
	size_t			i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
		write(1, str, i);
	}
	exit (0);
}

int					main(int ac, char **av)
{
	t_general		general;
	t_list			*lst;

	if (ac < 4)
		ft_error("Error this number arguments.\n");
	printf("\x1b[H\x1b[J");
	ft_bzero(&general, sizeof(t_general));
	parse_number_values(&general, av);
	make_array_values(&general, av);
	check_doubles_arr(general.array);
	push_swap(&general);
	return (0);
}
