#include "push_swap.h"

void	print_light_array(char **array)
{
	size_t	len;
	size_t	ltmp;

	len = 0;
	ltmp = get_len_array(array);
	while (ltmp--)
	{
		printf("%s ", array[len]);
		len++;
	}
	printf("\n");
}

void	print_array(char **array)
{
	size_t	len;
	size_t	ltmp;

	len = 0;
	ltmp = get_len_array(array);
	printf("\nArray:	\n");
	while (ltmp--)
	{
		printf("%zu:	[%s]\n", len, array[len]);
		len++;
	}
	printf("\n");
}

