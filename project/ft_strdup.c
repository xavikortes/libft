#include "libft.h"

char	*ft_strdup(const char *str)
{
	void	*ptr;
	size_t	len;

	len = ft_strlen(str);
	ptr = ft_calloc(len + 1, sizeof(char));
	if (ptr == NULL)
		return (ptr);
	ft_strlcpy(ptr, str, len + 1);
	return (ptr);
}
