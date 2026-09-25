#include "project/libft.h"

char	cifrado_map(unsigned int index, char c)
{
    (void) index;
	return (c + 1);
}

void	cifrado_iter(unsigned int index, char *str)
{
	(void) index;
	*str = cifrado_map(index, *str);
}

void	descifrado(unsigned int index, char *str)
{
	(void) index;
    *str = *str - 1;
}

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

	printf("\nstrtrim\n-------\n");
    printf("strtrim '      Hola amigos' ' ' -> '%s'\n", ft_strtrim("      Hola amigos", " "));
    printf("strtrim 'Hola amigos      ' ' ' -> '%s'\n", ft_strtrim("Hola amigos      ", " "));
    printf("strtrim '   Hola amigos   ' ' ' -> '%s'\n", ft_strtrim("   Hola amigos   ", " "));
    printf("strtrim (NULL) ' ' -> '%s'\n", ft_strtrim(NULL, " "));
    printf("strtrim 'Hola amigos' (NULL) -> '%s'\n", ft_strtrim("hola amigos", NULL));
    printf("strtrim ' hola amigos ' ' hs' -> '%s'\n", ft_strtrim("hola amigos", " hs"));

	printf("\nsplit\n-------\n");
    printf("split 'Hola amigos' ' ' -> \n");
	char **s = ft_split("Hola amigos", ' ');
	for (int i = 0; s[i] != NULL; i++)
	{
		printf("'%s', ", s[i]);
	}
	printf("\nsplit 'Hola amigos' 'a' -> \n");
	char **t = ft_split("Hola amigos", 'a');
    for (int i = 0; t[i] != NULL; i++)
    {
        printf("'%s', ", t[i]);
    }
	printf("\nsplit (NULL) ' ' -> \n");
	char **u = ft_split(NULL, ' ');
    for (int i = 0; u != NULL && u[i] != NULL; i++)
    {
        printf("'%s', ", u[i]);
    }
	printf("\n");

	printf("\nitoa\n-------\n");
	printf("itoa 1 -> %s\n", ft_itoa(1));
	printf("itoa 123456 -> %s\n", ft_itoa(123456));
	printf("itoa 0 -> %s\n", ft_itoa(0));
	printf("itoa -1 -> %s\n", ft_itoa(-1));
	printf("itoa -123456 -> %s\n", ft_itoa(-123456));
	printf("itoa INT_MAX -> %s\n", ft_itoa(INT_MAX));
	printf("itoa INT_MIN -> %s\n", ft_itoa(INT_MIN));

	printf("\nstrmapi\n-------\n");
	printf("strmapi 'Hola' cifrado(1) -> %s\n", ft_strmapi("Hola", &cifrado_map));
	printf("strmapi 'Hola' (NULL) -> %s\n", ft_strmapi("Hola", NULL));
	printf("strmapi (NULL) cifrado(1) -> %s\n", ft_strmapi(NULL, &cifrado_map));

	printf("\nstriteri\n-------\n");
	char x[15] = "Hola amigos";
	printf("initial -> %s\n", x);
	ft_striteri(x, &cifrado_iter);
    printf("striteri cifrado(1) -> %s\n", x);
	ft_striteri(x, &descifrado);
    printf("striteri descifrado(1) -> %s\n", x);
	ft_striteri(x, NULL);
	printf("striteri (NULL) -> %s\n", x);
	
	char *y = NULL;
	printf("\ninitial -> %s\n", y);
	ft_striteri(y, &cifrado_iter);
    printf("striteri cifrado(1) -> %s\n", y);
	ft_striteri(y, &descifrado);
    printf("striteri descifrado(1) -> %s\n", y);

	printf("\nputchar_fd\n-------\n");
    printf("putchar_fd 'h' 1\n");	
    printf("putchar_fd 'o' 1\n");	
    printf("putchar_fd 'l' 1\n");	
    printf("putchar_fd 'a' 1\n");	
    printf("putchar_fd '\\n' 1\n");
	ft_putchar_fd('h', 1);
	ft_putchar_fd('o', 1);
	ft_putchar_fd('l', 1);
	ft_putchar_fd('a', 1);
	ft_putchar_fd('\n', 1);

	printf("\nputstr_fd\n-------\n");
    printf("putstr_fd Hola\\n 1\n");
	ft_putstr_fd("Hola\n", 1);
    printf("putstr_fd (NULL) \\n 1\n");
	ft_putstr_fd(NULL, 1);
	
    printf("\nputendl_fd\n-------\n");
    printf("putendl_fd Hola 1\n");
    ft_putendl_fd("Hola", 1);
    printf("putendl_fd (NULL) 1\n");
    ft_putendl_fd(NULL, 1);

	printf("\nputnbr_fd\n-------\n");
    printf("putnbr_fd 5 1\n");
	ft_putnbr_fd(5, 1);
    printf("\nputnbr_fd -167 1\n");
	ft_putnbr_fd(-167, 1);
    printf("\nputnbr_fd INT_MAX 1\n");
	ft_putnbr_fd(INT_MAX, 1);
    printf("\nputnbr_fd INT_MIN 1\n");
	ft_putnbr_fd(INT_MIN, 1);
	printf("\n\n");
}
