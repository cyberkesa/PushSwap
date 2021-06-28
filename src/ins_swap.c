#include "push_swap.h"

void	sa_ins(t_general *general)
{
	char	*tmp;

	if (!(general->array[0]) || !(general->array[1]))
		return ;
	tmp = general->array[0];
	general->array[0] = general->array[1];
	general->array[1] = tmp;
	printf("sa\n");
}

void	sb_ins(t_general *general)
{
	char	*tmp;

	if (!(general->stack_b[0]) || !(general->stack_b[1]))
		return ;
	tmp = general->stack_b[0];
	general->stack_b[0] = general->stack_b[1];
	general->stack_b[1] = tmp;
	printf("sb\n");
}
