#include "push_swap.h"

void	print_light_array(char **array, int target)
{
	size_t	len;
	size_t	ltmp;

	len = 0;
	ltmp = get_len_array(array);
	while (ltmp--)
	{
		if (len == target)
			printf(">> ");
		printf("%s ", array[len]);
		len++;
	}
	printf("\n");
}

void	print_array(char **array, char *s)
{
	size_t	len;
	size_t	ltmp;

	len = 0;
	ltmp = get_len_array(array);
	printf("\n%s:	\n", s);
	while (ltmp--)
	{
		printf("%zu:	[%s]\n", len, array[len]);
		len++;
	}
	printf("\n");
}
