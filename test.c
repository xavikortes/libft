#include "project/libft.h"

int	main(void)
{
	printf("isalpha\n-------\n");
	printf("3 -> %i\n", isalpha('3') == ft_isalpha('3') * 1024);
	printf("a -> %i\n", isalpha('a') == ft_isalpha('a') * 1024);
	printf("z -> %i\n", isalpha('z') == ft_isalpha('z') * 1024);
	printf("  -> %i\n", isalpha(' ') == ft_isalpha(' ') * 1024);
	printf("A -> %i\n", isalpha('A') == ft_isalpha('A') * 1024);
	printf("Z -> %i\n", isalpha('Z') == ft_isalpha('Z') * 1024);

	printf("\nisdigit\n-------\n");
	printf("3 -> %i\n", isdigit('3') == ft_isdigit('3') * 2048);
	printf("a -> %i\n", isdigit('a') == ft_isdigit('a') * 2048);
	printf("A -> %i\n", isdigit('A') == ft_isdigit('A') * 2048);
	printf("  -> %i\n", isdigit(' ') == ft_isdigit(' ') * 2048);

	printf("\nisalnum\n-------\n");
	printf("a -> %i\n", isalnum('a') == ft_isalnum('a') * 8);
	printf("A -> %i\n", isalnum('A') == ft_isalnum('A') * 8);
	printf("  -> %i\n", isalnum(' ') == ft_isalnum(' ') * 8);
	printf("* -> %i\n", isalnum('*') == ft_isalnum('*') * 8);

	printf("\nisascii\n-------\n");
	printf("3 -> %i\n", isascii('3') == ft_isascii('3'));
	printf("127 -> %i\n", isascii(127) == ft_isascii(127));
	printf("-12 -> %i\n", isascii(-12) == ft_isascii(-12));

	printf("\nisprint\n-------\n");
	printf("\\n -> %i\n", isprint('\n') == ft_isprint('\n') * 16384);
	printf("3 -> %i\n", isprint('3') == ft_isprint('3') * 16384);
	printf("a -> %i\n", isprint('a') == ft_isprint('a') * 16384);

	printf("\nstrlen\n-------\n");
	printf("hola ->  %i\n", strlen("hola") == ft_strlen("hola"));
	printf(" ->  %i\n", strlen("") == ft_strlen(""));

	printf("\nmemset\n-------\n");
	printf("my version\n");
	char s[5] = "Hola";
	printf("memset %s\n", s);
	ft_memset(s, 'X', 3);
	printf("memset %s\n", s);
	ft_memset(s, 'x', 2);
	printf("memset %s\n", s);

	printf("lib version\n");
	char r[5] = "Hola";
    printf("memset %s\n", r);
    memset(r, 'X', 3);
    printf("memset %s\n", r);
    memset(r, 'x', 2);
    printf("memset %s\n", r);

	printf("\nbzero\n-------\n");
	printf("my version\n");
	ft_bzero(s, 3);
	printf("bzero %s\n", s);

	printf("lib version\n");
	bzero(r, 3);
    printf("bzero %s\n", r);

	printf("\nmemcpy\n-------\n");
	printf("my version\n");
	char t[5] = "Hola";
	char u[5] = "Adios";
	printf("memcpy %s\n", t);
	ft_memcpy(t, u, 3);
	printf("memcpy %s\n", t);

	printf("lib version\n");
	char v[5] = "Hola";
	char w[5] = "Adios";
    printf("memcpy %s\n", v);
    memcpy(v, w, 3);
    printf("memcpy %s\n", v);

	printf("\nmemmove\n-------\n");
	printf("my version\n");
	char x[5] = "Hola";
	char y[5] = "Adios";
	printf("memmove %s\n", x);
	ft_memmove(x, y, 3);
	printf("memmove %s\n", x);

	printf("lib version\n");
	char z[5] = "Hola";
	char a[5] = "Adios";
    printf("memmove %s\n", z);
    memmove(z, a, 3);
    printf("memmove %s\n", z);

	
/*	
	char	*src = "Jose Antonio";
	char	dst[12];

	printf("strlcpy %zu \n", ft_strlcpy(dst, src, 4));

	char	dst[50] = "Hola ";
	char	dst2[50] = "Adios ";
	printf("strlcat %zu\n", ft_strlcat(dst, "amigos", 3));
	printf("strlcat %zu\n", ft_strlcat(dst2, "enemigos", 3));

	printf("toupper a %i\n", ft_toupper('a'));
	printf("toupper A %i\n", ft_toupper('A'));
	printf("toupper   %i\n", ft_toupper(' '));
	
	printf("tolower a %i\n", ft_tolower('a'));
	printf("tolower A %i\n", ft_tolower('A'));
	printf("tolower   %i\n", ft_tolower(' '));

	char *h = "hola";
	char *a = "adios";

	printf("strchr hola h %s\n", ft_strchr(h, 'h'));
	printf("strchr hola o %s\n", ft_strchr(h, 'o'));
	printf("strchr hola l %s\n", ft_strchr(h, 'l'));
	printf("strchr hola a %s\n", ft_strchr(h, 'a'));
	printf("strchr hola z %s\n", ft_strchr(h, 'z'));
	printf("strchr adios h %s\n", ft_strchr(a, 'h'));

	char *h = "hola";
	char *a = "adios";
	char *l = "libelula";

	printf("strchr hola h %s\n", ft_strrchr(h, 'h'));
	printf("strchr hola o %s\n", ft_strrchr(h, 'o'));
	printf("strchr hola l %s\n", ft_strrchr(h, 'l'));
	printf("strchr hola a %s\n", ft_strrchr(h, 'a'));
	printf("strchr hola z %s\n", ft_strrchr(h, 'z'));
	printf("strchr libelula l %s\n", ft_strrchr(l, 'l'));
	printf("strchr adios h %s\n", ft_strrchr(a, 'h'));
	
	printf("%i\n", ft_strncmp("ABC", "AB", 3));
	printf("%i\n", ft_strncmp("ABC", "AB", 2));

	char	s1[] = "099990Hola";
	char	s2[] = "";
	char	s3[] = "                \n\t\v\r-46564";
	char	s4[] = "-+-+-+-+-+-+------+++++---123abc";

	printf("%s %i\n", s1, ft_atoi(s1));
	printf("%s %i\n", s2, ft_atoi(s2));
	printf("%s %i\n", s3, ft_atoi(s3));
    printf("%s %i\n", s4, ft_atoi(s4));

	printf("%s\n", ft_strnstr("Hola amigos", "ami", 3));
	printf("%s\n", ft_strnstr("Hola amigos", "ami", 8));
	printf("%s\n", ft_strnstr("Hola amigos", "jose", 10));
	printf("%s\n", ft_strnstr("Hola amigos", "", 3));
*/
}
