#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*new;
	size_t			s1len;
	size_t			s2len;
	size_t			i;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (!(new = (char *)malloc(s1len + s2len + 1)))
		return (NULL);
	i = 0;
	while (s1len--)
	{
		new[i] = s1[i];
		i++;
	}
	while (s2len--)
		new[i++] = *s2++;
	new[i] = '\0';
	return (new);
}
