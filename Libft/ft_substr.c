#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	len++;
	new = (char *)malloc(len);
	if (!(new))
		return (NULL);
	ft_strlcpy(new, s + start, len);
	return (new);
}
