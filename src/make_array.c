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

	general->sort = (char **)malloc(sizeof(char *)
			* (general->len_argc + 1));
	general->a = (char **)malloc(sizeof(char *) * (general->len_argc + 1));
	general->b = (char **)malloc(sizeof(char *) * (1));
	len = 0;
	while (len < general->len_argc)
	{
		general->a[len] = av[len + 1];
		general->sort[len] = general->a[len];
		len++;
	}
	general->sort[len] = NULL;
	general->a[len] = NULL;
	general->b[0] = NULL;
}
