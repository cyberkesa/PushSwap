#include "push_swap.h"

void	parse_number_values(t_general *general, char **av)
{
	size_t	len;

	len = 1;
	while (av[len])
		len++;
	general->len_argc = len - 1;
	general->len_arr = general->len_argc - 1;
}

void	make_array_values(t_general *general, char **av)
{
	size_t		len;

	general->sort_array = (char **)malloc(sizeof(char *) * (general->len_argc + 1));
	general->array = (char **)malloc(sizeof(char *) * (general->len_argc + 1));
	general->stack_b = (char **)malloc(sizeof(char *) * (1));
	len = 0;
	while (len < general->len_argc)
	{
		general->array[len] = av[len + 1];
		general->sort_array[len] = general->array[len];
		len++;
	}
	general->sort_array[len] = NULL;
	general->array[len] = NULL;
	general->stack_b[0] = NULL;
}

