#include <stdio.h>
#include <bsd/string.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
#include "libft.h"

/* ========================================================================== */
/*                           TESTS PARTE 1: MEMORIA                           */
/* ========================================================================== */

static void test_bzero(void)
{
	char	b_ft[20];
	char	b_std[20];

	memset(b_ft, 'A', sizeof(b_ft));
	memset(b_std, 'A', sizeof(b_std));
	ft_bzero(b_ft, sizeof(b_ft));
	bzero(b_std, sizeof(b_std));
	if (memcmp(b_ft, b_std, sizeof(b_ft)) == 0)
		printf("[OK] ft_bzero\n");
	else
		printf("[FAIL] ft_bzero\n");
}

static void test_memset(void)
{
	char	b_ft[20];
	char	b_std[20];

	memset(b_ft, 'A', sizeof(b_ft));
	memset(b_std, 'A', sizeof(b_std));
	ft_memset(b_ft, 'X', 10);
	memset(b_std, 'X', 10);
	if (memcmp(b_ft, b_std, sizeof(b_ft)) == 0)
		printf("[OK] ft_memset\n");
	else
		printf("[FAIL] ft_memset\n");
}

static void test_memcpy(void)
{
	char	dest_ft[20];
	char	dest_std[20];
	char	*src = "Hola mundo";
	size_t	size = strlen(src) + 1;
	int		fail = 0;

	memset(dest_ft, 'A', sizeof(dest_ft));
	memset(dest_std, 'B', sizeof(dest_std));
	ft_memcpy(dest_ft, src, size);
	memcpy(dest_std, src, size);
	if (memcmp(dest_ft, dest_std, size) != 0)
		fail++;

	// Edge case: ambos NULL con len > 0
	if (ft_memcpy(NULL, NULL, 5) != NULL)
		fail++;

	if (!fail)
		printf("[OK] ft_memcpy\n");
	else
		printf("[FAIL] ft_memcpy (%i)\n", fail);
}

static void test_memmove(void)
{
	char	str1[] = "Hola, mundo!";
	char	str2[] = "Hola, mundo!";
	char	str3[] = "Hola, mundo!";
	char	str4[] = "Hola, mundo!";
	int		diff = 0;

	ft_memmove(str1 + 2, str1, 10);
	memmove(str2 + 2, str2, 10);
	diff += strcmp(str1, str2);

	ft_memmove(str3, str3 + 5, 6);
	memmove(str4, str4 + 5, 6);
	diff += strcmp(str3, str4);

	// Edge case: ambos NULL
	if (ft_memmove(NULL, NULL, 5) != NULL)
		diff++;

	if (diff == 0)
		printf("[OK] ft_memmove (Overlap & NULL edge cases)\n");
	else
		printf("[FAIL] ft_memmove (%i)\n", diff);
}

static void test_memchr(void)
{
	char			str[] = "Hola mundo\0prueba";
	unsigned char	bytes[] = {0, 10, 128, 250, 255};
	int				fail = 0;

	if (ft_memchr(str, 'm', 10) != memchr(str, 'm', 10))
		fail++;
	if (ft_memchr(str, 'z', 10) != memchr(str, 'z', 10))
		fail++;
	if (ft_memchr(str, '\0', 12) != memchr(str, '\0', 12))
		fail++;

	// Edge case: unsigned char cast test
	if (ft_memchr(bytes, 250, 5) != memchr(bytes, 250, 5))
		fail++;
	if (ft_memchr(bytes, 255, 5) != memchr(bytes, 255, 5))
		fail++;

	if (!fail)
		printf("[OK] ft_memchr\n");
	else
		printf("[FAIL] ft_memchr (%i)\n", fail);
}

static void test_memcmp(void)
{
	char			s1[] = "Hola";
	char			s2[] = "Holb";
	unsigned char	b1[] = {"\xff\xaa\xde\xad"};
	unsigned char	b2[] = {"\xff\xaa\xde\x00"};
	int				diff = 0;

	if ((ft_memcmp(s1, s1, 4) == 0) != (memcmp(s1, s1, 4) == 0))
		diff++;
	if ((ft_memcmp(s1, s2, 4) < 0) != (memcmp(s1, s2, 4) < 0))
		diff++;
	if ((ft_memcmp(s1, s2, 3) == 0) != (memcmp(s1, s2, 3) == 0))
		diff++;

	// Edge case: Comparación unsigned (> 127)
	if ((ft_memcmp(b1, b2, 4) > 0) != (memcmp(b1, b2, 4) > 0))
		diff++;

	if (diff == 0)
		printf("[OK] ft_memcmp\n");
	else
		printf("[FAIL] ft_memcmp (%i)\n", diff);
}

/* ========================================================================== */
/*                        TESTS PARTE 1: CLASIFICACIÓN                        */
/* ========================================================================== */

static void test_is_family(void)
{
	int	chars[] = {'a', 'Z', '0', '9', ' ', 127, -1, 200, '\0'};
	int	len = sizeof(chars) / sizeof(chars[0]);
	int	fail = 0;

	for (int i = 0; i < len; i++)
	{
		int c = chars[i];
		if ((ft_isalpha(c) != 0) != (isalpha(c) != 0))
			fail++;
		if ((ft_isdigit(c) != 0) != (isdigit(c) != 0))
			fail++;
		if ((ft_isalnum(c) != 0) != (isalnum(c) != 0))
			fail++;
		if ((ft_isascii(c) != 0) != (isascii(c) != 0))
			fail++;
		if ((ft_isprint(c) != 0) != (isprint(c) != 0))
			fail++;
	}
	if (!fail)
		printf("[OK] ft_is* (isalpha, isdigit, isalnum, isascii, isprint)\n");
	else
		printf("[FAIL] ft_is* suite (%i)\n", fail);
}

static void test_to_family(void)
{
	if (ft_toupper('a') == toupper('a') && ft_toupper('Z') == toupper('Z') &&
		ft_tolower('A') == tolower('A') && ft_tolower('z') == tolower('z') &&
		ft_toupper(200) == toupper(200) && ft_tolower(200) == tolower(200))
		printf("[OK] ft_toupper / ft_tolower\n");
	else
		printf("[FAIL] ft_toupper / ft_tolower\n");
}

/* ========================================================================== */
/*                          TESTS PARTE 1: STRINGS                            */
/* ========================================================================== */

static void test_strlen(void)
{
	char	*s1 = "";
	char	*s2 = "42 Madrid";
	if (ft_strlen(s1) == strlen(s1) && ft_strlen(s2) == strlen(s2))
		printf("[OK] ft_strlen\n");
	else
		printf("[FAIL] ft_strlen\n");
}

static void test_strchr_strrchr(void)
{
	char	str[] = "Hola mundo, hola!";
	int		fail = 0;

	if (ft_strchr(str, 'm') != strchr(str, 'm'))
		fail++;
	if (ft_strchr(str, 'z') != strchr(str, 'z'))
		fail++;
	if (ft_strchr(str, '\0') != strchr(str, '\0'))
		fail++;

	if (ft_strrchr(str, 'o') != strrchr(str, 'o'))
		fail++;
	if (ft_strrchr(str, 'z') != strrchr(str, 'z'))
		fail++;
	if (ft_strrchr(str, '\0') != strrchr(str, '\0'))
		fail++;

	// Edge case: int c fuera de rango char
	if (ft_strchr(str, 'o' + 256) != strchr(str, 'o' + 256))
		fail++;

	if (!fail)
		printf("[OK] ft_strchr / ft_strrchr\n");
	else
		printf("[FAIL] ft_strchr / ft_strrchr (%i)\n", fail);
}

static void test_strncmp(void)
{
	char	*s1 = "abcdef";
	char	*s2 = "abc\xfd";
	int		diff = 0;

	if ((ft_strncmp("abc", "abc", 3) == 0) != (strncmp("abc", "abc", 3) == 0))
		diff++;
	if ((ft_strncmp("abc", "abd", 2) == 0) != (strncmp("abc", "abd", 2) == 0))
		diff++;
	// Edge case: unsigned char cast con caracteres extendidos
	if ((ft_strncmp(s1, s2, 5) < 0) != (strncmp(s1, s2, 5) < 0))
		diff++;
	// Edge case: n = 0
	if (ft_strncmp("abc", "xyz", 0) != 0)
		diff++;

	if (!diff)
		printf("[OK] ft_strncmp\n");
	else
		printf("[FAIL] ft_strncmp (%i)\n", diff);
}

static void test_strnstr(void)
{
	char	*big = "Aceptamos pulpo como animal";
	int		fail = 0;

	if (ft_strnstr(big, "pulpo", 20) != strnstr(big, "pulpo", 20))
		fail++;
	if (ft_strnstr(big, "pulpo", 5) != strnstr(big, "pulpo", 5))
		fail++;
	// Edge case: needle vacía con cualquier longitud (incluso 0)
	if (ft_strnstr(big, "", 10) != strnstr(big, "", 10))
		fail++;
	if (ft_strnstr(big, "", 0) != strnstr(big, "", 0))
		fail++;
	// Edge case: coincidencia parcial que excede len
	if (ft_strnstr("banana", "nana", 4) != strnstr("banana", "nana", 4))
		fail++;

	if (!fail)
		printf("[OK] ft_strnstr\n");
	else
		printf("[FAIL] ft_strnstr (%i)\n", fail);
}

static void test_strlcpy(void)
{
	char	dst1[20];
	char	dst2[20];
	char	*src = "Hola mundo";
	size_t	r1, r2;
	int		fail = 0;

	r1 = ft_strlcpy(dst1, src, 5);
	r2 = strlcpy(dst2, src, 5);
	if (r1 != r2 || strcmp(dst1, dst2) != 0)
		fail++;

	r1 = ft_strlcpy(dst1, src, 0);
	r2 = strlcpy(dst2, src, 0);
	if (r1 != r2)
		fail++;

	if (!fail)
		printf("[OK] ft_strlcpy\n");
	else
		printf("[FAIL] ft_strlcpy (%i)\n", fail);
}

static void test_strlcat(void)
{
	char	dst1[20] = "Hola ";
	char	dst2[20] = "Hola ";
	char	*src = "Mundo";
	size_t	r1, r2;
	int		fail = 0;

	r1 = ft_strlcat(dst1, src, 20);
	r2 = strlcat(dst2, src, 20);
	if (r1 != r2 || strcmp(dst1, dst2) != 0)
		fail++;

	// Edge case: dstsize < strlen(dst)
	strcpy(dst1, "12345");
	strcpy(dst2, "12345");
	r1 = ft_strlcat(dst1, "abc", 2);
	r2 = strlcat(dst2, "abc", 2);
	if (r1 != r2 || strcmp(dst1, dst2) != 0)
		fail++;

	// Edge case: dstsize == 0
	strcpy(dst1, "12345");
	strcpy(dst2, "12345");
	r1 = ft_strlcat(dst1, "abc", 0);
	r2 = strlcat(dst2, "abc", 0);
	if (r1 != r2 || strcmp(dst1, dst2) != 0)
		fail++;

	if (!fail)
		printf("[OK] ft_strlcat\n");
	else
		printf("[FAIL] ft_strlcat (%i)\n", fail);
}

static void test_atoi(void)
{
	char	*cases[] = {
		"0", "42", "-42", "   +123", "2147483647", "-2147483648",
		"  --12", "++12", "+-12", " -+12",
		"\t\n\v\f\r 123", "123abc45", "abc123"
	};
	int		total = sizeof(cases) / sizeof(cases[0]);
	int		fail = 0;

	for (int i = 0; i < total; i++)
	{
		if (ft_atoi(cases[i]) != atoi(cases[i]))
		{
			printf("   [Error in case: '%s'] (ft: %d | std: %d)\n",
				cases[i], ft_atoi(cases[i]), atoi(cases[i]));
			fail++;
		}
	}
	if (!fail)
		printf("[OK] ft_atoi\n");
	else
		printf("[FAIL] ft_atoi (%i)\n", fail);
}

/* ========================================================================== */
/*                         TESTS PARTE 1: MALLOC                              */
/* ========================================================================== */

static void test_calloc(void)
{
	char	*ptr_ft;
	char	*ptr_std;
	int		fail = 0;

	ptr_ft = (char *)ft_calloc(10, sizeof(char));
	ptr_std = (char *)calloc(10, sizeof(char));
	if (!ptr_ft || !ptr_std || memcmp(ptr_ft, ptr_std, 10) != 0)
		fail++;
	free(ptr_ft);
	free(ptr_std);

	// Edge case: nmemb 0 o size 0 (Subject requirement)
	ptr_ft = (char *)ft_calloc(0, 5);
	if (ptr_ft == NULL)
		fail++;
	free(ptr_ft);

	ptr_ft = (char *)ft_calloc(5, 0);
	if (ptr_ft == NULL)
		fail++;
	free(ptr_ft);

	// Edge case: Integer overflow protection
	ptr_ft = (char *)ft_calloc((size_t)-1, 5);
	if (ptr_ft != NULL)
	{
		fail++;
		free(ptr_ft);
	}

	if (!fail)
		printf("[OK] ft_calloc (Zeros, Size 0, Overflow checks)\n");
	else
		printf("[FAIL] ft_calloc (%i)\n", fail);
}

static void test_strdup(void)
{
	char	*src = "Cadena clonada con exito";
	char	*dup = ft_strdup(src);
	char	*empty_dup = ft_strdup("");
	int		fail = 0;

	if (!dup || strcmp(src, dup) != 0)
		fail++;
	if (!empty_dup || strcmp("", empty_dup) != 0)
		fail++;

	free(dup);
	free(empty_dup);

	if (!fail)
		printf("[OK] ft_strdup\n");
	else
		printf("[FAIL] ft_strdup\n");
}

/* ========================================================================== */
/*                                    MAIN                                    */
/* ========================================================================== */

int main(void)
{
	printf("=========================================\n");
	printf("    LIBFT PARTE 1 - PRUEBAS DE ESTRÉS    \n");
	printf("=========================================\n");

	test_bzero();
	test_memset();
	test_memcpy();
	test_memmove();
	test_memchr();
	test_memcmp();

	test_is_family();
	test_to_family();

	test_strlen();
	test_strchr_strrchr();
	test_strncmp();
	test_strnstr();
	test_strlcpy();
	test_strlcat();
	test_atoi();

	test_calloc();
	test_strdup();

	printf("=========================================\n");
	return (0);
}
