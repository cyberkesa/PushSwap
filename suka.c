void	push_lol(t_general *general)
{
	char	**new_a;
	char	**new_b;
	size_t	len_a;
	size_t	len_b;
	size_t	i;
	size_t	a;

	len_a = get_len_array(general->lol);
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
			new_a[i] = general->lol[a];
			a++;
			i++;
		}
		new_a[i] = NULL;
	}
	else
		new_a[1] = NULL;
	free(general->stack_b);
	free(general->lol);
	general->lol = new_a;
	general->stack_b = new_b;
	general->ins_num += 1;
	printf("push_lol\n");
}
