#include "project/libft.h"

int	main(void)
{
	printf("\nsubstr\n-------\n");
	printf("substr Hola amigos 5 4 -> %s\n", ft_substr("Hola amigos", 5, 4));
	printf("substr Hola amigos 0 100 -> %s\n", ft_substr("Hola amigos", 0, 100));
	printf("substr Hola amigos 100 4 -> %s\n", ft_substr("Hola amigos", 100, 4));
	printf("substr (NULL) 100 4 -> %s\n", ft_substr(NULL, 100, 4));
	printf("substr Hola amigos 0 0 -> %s\n", ft_substr("Hola amigos", 0, 0));

	printf("\nstrjoin\n-------\n");
    printf("strjoin Hola amigos -> %s\n", ft_strjoin("Hola", " amigos"));
    printf("strjoin (NULL) amigos -> %s\n", ft_strjoin(NULL, " amigos"));
    printf("strjoin Hola (NULL) -> %s\n", ft_strjoin("Hola", NULL));
}
