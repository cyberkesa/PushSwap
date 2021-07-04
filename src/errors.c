#include "push_swap.h"

int	max_int(const char *str)
{
	unsigned long	result;
	size_t			i;
	int				sign;

	result = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == 45 || str[i] == 43)
		i++;
	while (ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	if (sign == -1)
	{
		if (result - 1 > INT_MAX)
			return (1);
	}
	else if (result > INT_MAX)
			return (1);
	return (0);
}

void	check_maxint(char **av)
{
	int	i;

	i = 1;
	while (av[i] != NULL)
	{
		if (max_int(av[i]) == 1)
			ft_error("Error! MAXINT.\n");
		i++;
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
			if (!ft_isdigit((int)av[i][a]) && av[i][a] ^ '-' && av[i][a] ^ ' ')
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