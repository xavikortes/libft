#include "libft.h"

char	*ft_strtrim(char const *str, char const *set)
{
	int		len;
	int		start;
	int		end;
	char	*new;

	if (str == NULL)
		return (NULL);
	if (set == NULL)
		return ((char *) str);
	len = ft_strlen(str);
	start = 0;
	while (start < len && ft_strchr(set, str[start]))
		start++;
	end = len;
	while (ft_strchr(set, str[end - 1]))
		end--;
	new = ft_calloc(end - start + 1, sizeof(char));
	if (new == NULL)
		return (NULL);
	strlcpy(new, str + start, end - start + 1);
	return (new);
}
