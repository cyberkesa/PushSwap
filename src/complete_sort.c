#include "push_swap.h"

void	complete_sort(t_general *g)
{
	if (check_sort(g->array) == 1)
		printf("\nCортировка:			ОК\n");
	printf("Совершено операций:		%zu\nКоличество аргументов подано:	%zu\n", g->ins_num, g->len_argc);
	print_light_array(g->array);
	print_light_array(g->sort_array);
}
