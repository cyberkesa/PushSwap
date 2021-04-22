#include "push_swap.h"

void	ss_ins(t_general *general)
{
	sa_ins(general);
	sb_ins(general);
	general->ins_num--;
	printf("ss\n");
}

void	rr_ins(t_general *general)
{
	ra_ins(general);
	rb_ins(general);
	general->ins_num--;
	printf("rr\n");
}

void	rrr_ins(t_general *general)
{
	rra_ins(general);
	rrb_ins(general);
	general->ins_num--;
	printf("rrr\n");
}

void	sa_ins(t_general *general)
{
	char	*tmp;

	// print_array(general->array);
	if (!(general->array[0]) || !(general->array[1]))
		return ;
	tmp = general->array[0];
	general->array[0] = general->array[1];
	general->array[1] = tmp;
	general->ins_num += 1;
	// print_array(general->array);
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
	general->ins_num += 1;
	printf("sb\n");
}

void	ra_ins(t_general *general)
{
	size_t	len_in_stack_a;
	size_t	i;
	size_t	a;
	char	*tmp;

	len_in_stack_a = get_len_array(general->array);
	i = 0;
	a = 1;
	tmp = general->array[0];
	while (general->array[i])
	{
		general->array[i] = general->array[a];
		i++;
		a++;
	}
	general->array[i - 1] = tmp;
	general->ins_num += 1;
	printf("ra\n");
}

void	rb_ins(t_general *general)
{
	size_t	len_in_stack_b;
	size_t	i;
	size_t	b;
	char	*tmp;

	len_in_stack_b = get_len_array(general->stack_b);
	i = 0;
	b = 1;
	tmp = general->stack_b[0];
	while (general->stack_b[i])
	{
		general->stack_b[i] = general->stack_b[b];
		i++;
		b++;
	}
	general->stack_b[i - 1] = tmp;
	general->ins_num += 1;
	printf("rb\n");
}

void	rra_ins(t_general *general)
{
	size_t	len;
	char	*tmp;

	len = get_len_array(general->array);
	tmp = general->array[len - 1];
	while (--len)
		general->array[len] = general->array[len - 1];
	general->array[0] = tmp;
	general->ins_num += 1;
	printf("rra\n");
}

void	rrb_ins(t_general *general)
{
	size_t	len;
	char	*tmp;

	len = get_len_array(general->stack_b);
	tmp = general->stack_b[len - 1];
	while (--len)
		general->stack_b[len] = general->stack_b[len - 1];
	general->stack_b[0] = tmp;
	general->ins_num += 1;
	printf("rrb\n");
}

void	pa_ins(t_general *general)
{
	char	**new_a;
	char	**new_b;
	size_t	len_a;
	size_t	len_b;
	size_t	i;
	size_t	a;

	len_a = get_len_array(general->array);
	len_b = get_len_array(general->stack_b);

	if (len_a == 0)
		return;
	new_a = (char **)malloc(sizeof(char *) * (len_a));
	new_b = (char **)malloc(sizeof(char *) * (len_b + 2));
	i = 0;
	a = 1;
	while (a != len_a)
	{
		new_a[i] = general->array[a];
		a++;
		i++;
	}
	new_a[i] = NULL;
	i = 1;
	a = 0;
	new_b[0] = general->array[0];
	if (len_b > 0)
	{
		while (a != len_b)
		{
			new_b[i] = general->stack_b[a];
			i++;
			a++;
		}
		new_b[i] = NULL;
	}
	else
		new_b[1] = NULL;
	free(general->stack_b);
	free(general->array);
	general->array = new_a;
	general->stack_b = new_b;
	general->ins_num += 1;
	printf("pb\n");
}

void	pb_ins(t_general *general)
{
	char	**new_a;
	char	**new_b;
	size_t	len_a;
	size_t	len_b;
	size_t	i;
	size_t	a;

	len_a = get_len_array(general->array);
	len_b = get_len_array(general->stack_b);
	if (len_b == 0)
		return;
	new_a = (char **)malloc(sizeof(char *) * (len_a + 2));
	new_b = (char **)malloc(sizeof(char *) * (len_b));

	i = 0;
	a = 1;
	while (a != len_b)
	{
		new_b[i] = general->stack_b[a];
		a++;
		i++;
	}
	new_b[i] = NULL;

	i = 1;
	a = 0;
	new_a[0] = general->stack_b[0];
	if (len_a > 0)
	{
		while (a != len_a)
		{
			new_a[i] = general->array[a];
			a++;
			i++;
		}
		new_a[i] = NULL;
	}
	else
		new_a[1] = NULL;
	free(general->stack_b);
	free(general->array);
	general->array = new_a;
	general->stack_b = new_b;
	general->ins_num += 1;
	printf("pa\n");
}
