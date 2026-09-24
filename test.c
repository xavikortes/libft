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

	printf("\nstrlcpy\n-------\n");
	printf("my version\n");
    char b[15] = "Hola amigos";
    char c[15];
    printf("strlcpy %s\n", b);
    ft_strlcpy(c, b, 7);
    printf("strlcpy %s\n", c);

    printf("lib version\n");
    char d[15] = "Hola amigos";
    char e[15];
    printf("strlcpy %s\n", d);
    strlcpy(e, d, 7);
    printf("strlcpy %s\n", e);

	printf("\nstrlcat\n-------\n");
	printf("my version\n");
    char f[15] = "Hola";
    char g[15] = " amigos";
    printf("strlcat %s\n", f);
    ft_strlcat(f, g, 10);
    printf("strlcat %s\n", f);

    printf("lib version\n");
    char h[15] = "Hola";
    char i[15] = " amigos";
    printf("strlcat %s\n", h);
    strlcat(h, i, 10);
    printf("strlcat %s\n", h);

	printf("\ntoupper\n-------\n");
	printf("a -> %i\n", ft_toupper('a') == toupper('a'));
	printf("A -> %i\n", ft_toupper('A') == toupper('A'));
	printf("  -> %i\n", ft_toupper(' ') == toupper(' '));

	printf("\ntolower\n-------\n");
	printf("a -> %i\n", ft_tolower('a') == tolower('a'));
	printf("A -> %i\n", ft_tolower('A') == tolower('A'));
	printf("  -> %i\n", ft_tolower(' ') == tolower(' '));
	
	printf("\nstrchr\n-------\n");
	char *j = "hola";
	printf("hola o -> %i\n", ft_strchr(j, 'o') == strchr(j, 'o'));
	printf("hola a -> %i\n", ft_strchr(j, 'a') == strchr(j, 'a'));
	printf("hola w -> %i\n", ft_strchr(j, 'w') == strchr(j, 'w'));

	printf("\nstrrchr\n-------\n");
	char *k = "libelula";
	printf("libelula l -> %i\n", ft_strrchr(k, 'l') == strrchr(k, 'l'));
	printf("libelula e -> %i\n", ft_strrchr(k, 'e') == strrchr(k, 'e'));
	printf("libelula w -> %i\n", ft_strrchr(k, 'w') == strrchr(k, 'w'));
	
	printf("\nstrncmp\n-------\n");
	printf("ABC AB 3 -> %i\n", ft_strncmp("ABC", "AB", 3) == strncmp("ABC", "AB", 3));
	printf("ABC AB 2 -> %i\n", ft_strncmp("ABC", "AB", 2) == strncmp("ABC", "AB", 2));
	printf("AB ABC 3 -> %i\n", ft_strncmp("AB", "ABC", 3) == strncmp("AB", "ABC", 3));
	printf("AB AB 3 -> %i\n", ft_strncmp("AB", "AB", 3) == strncmp("AB", "AB", 3));
	
	printf("\nmemchr\n-------\n");
	printf("my version\n");
	printf("hola-amigos g 3 -> %s\n", (char *) ft_memchr("hola-amigos", 'g', 3));
	printf("hola-amigos g 9 -> %s\n", (char *) ft_memchr("hola-amigos", 'g', 9));
	printf("hola-amigos g 6 -> %s\n", (char *) ft_memchr("hola-amigos", 'g', 6));
	printf("- g 0 -> %s\n", (char *) ft_memchr("", 'g', 0));
	printf("hola-amigos x 6 -> %s\n", (char *) ft_memchr("hola-amigos", 'x', 6));

	printf("lib version\n");
	printf("hola-amigos g 3 -> %s\n", (char *) memchr("hola-amigos", 'g', 3));
	printf("hola-amigos g 9 -> %s\n", (char *) memchr("hola-amigos", 'g', 9));
	printf("hola-amigos g 6 -> %s\n", (char *) memchr("hola-amigos", 'g', 6));
	printf("- g 0 -> %s\n", (char *) memchr("", 'g', 0));
	printf("hola-amigos x 6 -> %s\n", (char *) memchr("hola-amigos", 'x', 6));

	printf("\nmemcmp\n-------\n");
	printf("ABC AB 3 -> %i\n", ft_memcmp("ABC", "AB", 3) == memcmp("ABC", "AB", 3));
	printf("ABC AB 2 -> %i\n", ft_memcmp("ABC", "AB", 2) == memcmp("ABC", "AB", 2));
	printf("AB ABC 3 -> %i\n", ft_memcmp("AB", "ABC", 3) == memcmp("AB", "ABC", 3));
	printf("AB AB 3 -> %i\n", ft_memcmp("AB", "AB", 3) == memcmp("AB", "AB", 3));
	
	printf("\nstrnstr\n-------\n");
	printf("my version\n");
	printf("hola-amigos ami 3 -> %s\n", ft_strnstr("hola-amigos", "ami", 3));
	printf("hola-amigos ami 9 -> %s\n", ft_strnstr("hola-amigos", "ami", 9));
	printf("hola-amigos ami 6 -> %s\n", ft_strnstr("hola-amigos", "ami", 6));
	printf("- ami 3 -> %s\n", ft_strnstr("", "ami", 3));
	printf("hola-amigos - 6 -> %s\n", ft_strnstr("hola-amigos", "", 6));

	printf("lib version\n");
	printf("hola-amigos ami 3 -> %s\n", strnstr("hola-amigos", "ami", 3));
	printf("hola-amigos ami 9 -> %s\n", strnstr("hola-amigos", "ami", 9));
	printf("hola-amigos ami 6 -> %s\n", strnstr("hola-amigos", "ami", 6));
	printf("- ami 3 -> %s\n", strnstr("", "ami", 3));
	printf("hola-amigos - 6 -> %s\n", strnstr("hola-amigos", "", 6));

	printf("\natoi\n-------\n");
	char l[] = "099990Hola";
	char m[] = "";
	char n[] = "                \n\t\v\r-46564";
	char o[] = "-+-+-+-+-+-+------+++++---123abc";
	printf("%s %i\n", l, ft_atoi(l) == atoi(l));
	printf("%s %i\n", m, ft_atoi(m) == atoi(m));
	printf("%s %i\n", n, ft_atoi(n) == atoi(n));
	printf("%s %i\n", o, ft_atoi(o) == atoi(o));

	printf("\ncalloc\n-------\n");
	printf("my version\n");
	printf("%p\n", ft_calloc(5, 2));
	printf("%p\n", ft_calloc(INT_MAX, 2));

	printf("lib version\n");
	printf("%p\n", calloc(5, 2));
	printf("%p\n", calloc(INT_MAX, 2));

	printf("\nstrdup\n-------\n");
	printf("my version\n");
	printf("%s\n", ft_strdup("hola amigos"));
	printf("%s\n", ft_strdup(""));

	printf("lib version\n");
	printf("%s\n", strdup("hola amigos"));
	printf("%s\n", strdup(""));

	
}
