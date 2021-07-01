#include "push_swap.h"

void	check_maxint(char **av)
{

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
			if (!ft_isdigit((int)av[i][a]) && av[i][a] ^ '-')
				ft_error("Error! Non numeric parameters.\n");
			a++;
		}
		i++;
	}
}

void	check_errors(char **av)
{
	check_maxint(av);
	check_non_numeric(av);
}