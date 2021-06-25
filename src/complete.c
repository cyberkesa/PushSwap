#include "push_swap.h"

void	free_array(char **r)
{
	size_t	i;

	i = 0;
	while (r[i] != NULL)
		free(r[i++]);
	free(r);
}

void	ft_exit(t_general *g)
{
	free(g->array);
	free(g->stack_b);
	free(g->sort_array);
	exit (0);
}

void	complete_sort(t_general *g)
{
	// if (check_sort(g->array) == 0)
	// 	printf("\033[32m\nCортировка:			ОК\n\033[1m\033[32m");
	// else
	// 	printf("\033[31m\nCортировка:			ERRRROOOOOOR!!!!!!!!!!!!!\n\033[1m\033[31m");
	// printf("Совершено операций:		%zu\nКоличество аргументов подано:	%zu\n", g->ins_num, g->len_argc);
	// print_light_array(g->array, -1);
	ft_exit(g);
}
