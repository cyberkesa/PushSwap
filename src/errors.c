#include "push_swap.h"

void	ft_error(char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
		write(1, str, i);
	}
	exit (0);
}


int		check_max_atoi(char *str)
{
	size_t	result;
	size_t	i;
	
	result = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == 45 || str[i] == 43)
		i++;
	while (ft_isdigit(str[i]))
	{
		if (result >= INT_MAX)
			return (-1);
		result = result * 10 + (str[i++] - '0');
	}
	return (1);
}

void	check_max_int(t_general *g)
{
	int	i; 
	int	a;

	i = 0;
	a = 0;
	while (a ^ g->len_argc)
	{
		// i = 0;
		// while (g->array[i] != NULL)
		// {
			if (check_max_atoi(g->array[a]) == -1)
				ft_error("Error, MAX INT!\n");
			// i++;
		// }
		a++;
	}
}

void	check_non_numeric(char **av)
{
	int	i;
	int a;

	i = 1;
	while (av[i] != NULL)
	{
		a = 0;
		while (av[i][a])
		{
			// printf("%c\n", av[i][a]);
			if (!ft_isdigit_char(av[i][a]) && !ft_issign_char(av[i][a]))
				ft_error("Error! Non numeric parameters.\n");
			if (ft_issign_char(av[i][a]))
				if (!(av[i][a + 1]) || !ft_isdigit_char(av[i][a + 1]))
					ft_error("Error! Non numeric parameters.\n");
				if (av[i][a + 1] == '0')
					ft_error("Error! Non numeric parameters.\n");

			a++;
		}
		i++;
	}
}

void	errors_detected(t_general *g, int ac, char **av)
{
	if (ac < 2)
		ft_error("Error! not valid number arguments.\n");
	check_non_numeric(av);
	// exit (0);
	check_max_int(g);
	parse_number_values(g, av);
	make_array_values(g, av);
	check_doubles_arr(g->array);
}