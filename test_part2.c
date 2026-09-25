#include "project/libft.h"

void	cifrado(unsigned int index, char *str)
{
	(void) index;
	*str = *str + 1;
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

	printf("\nitoa\n-------\n");
	printf("itoa 1 -> %s\n", ft_itoa(1));
	printf("itoa 123465 -> %s\n", ft_itoa(123456));
	printf("itoa 0 -> %s\n", ft_itoa(0));
	printf("itoa -1 -> %s\n", ft_itoa(-1));
	printf("itoa -123456 -> %s\n", ft_itoa(-123456));

	printf("\nstriteri\n-------\n");
	char x[15] = "Hola amigos";
	printf("\ninitial -> %s\n", x);
	ft_striteri(x, &cifrado);
    printf("striteri cifrado(1) -> %s\n", x);
	ft_striteri(x, &descifrado);
    printf("striteri descifrado(1) -> %s\n", x);
	ft_striteri(x, NULL);
	printf("striteri (NULL) -> %s\n", x);
	
	char *y = NULL;
	printf("\ninitial -> %s\n", y);
	ft_striteri(y, &cifrado);
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

}
