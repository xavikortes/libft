#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
;
	if (s == NULL || start > ft_strlen(s))
		return (NULL);
	new = ft_calloc(len + 1, sizeof(char));
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, s + start, len + 1);
	return (new);
}
