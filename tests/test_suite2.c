#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

/* ========================================================================== */
/*                             HELPERS PARA TESTS                             */
/* ========================================================================== */

static char	mapi_toupper(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

static void	iteri_toupper(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

static void	free_split_array(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

/* Captura la salida escrita en un fd para validarla con un string esperado */
static int	capture_fd_output(void (*f_call)(int), const char *expected)
{
	int		pipefd[2];
	char	buf[128];
	ssize_t	bytes_read;

	if (pipe(pipefd) == -1)
		return (0);
	f_call(pipefd[1]);
	close(pipefd[1]);
	memset(buf, 0, sizeof(buf));
	bytes_read = read(pipefd[0], buf, sizeof(buf) - 1);
	close(pipefd[0]);
	if (bytes_read < 0)
		return (0);
	buf[bytes_read] = '\0';
	return (strcmp(buf, expected) == 0);
}

/* ========================================================================== */
/*                                   TESTS                                    */
/* ========================================================================== */

static void	test_substr(void)
{
	int		fail = 0;
	char	*res;

	res = ft_substr("holamundo", 4, 5);
	if (!res || strcmp(res, "mundo") != 0)
		fail++;
	free(res);

	// Edge case: start > strlen(s)
	res = ft_substr("hola", 10, 5);
	if (!res || strcmp(res, "") != 0)
		fail++;
	free(res);

	// Edge case: len excede el final
	res = ft_substr("hola", 2, 100);
	if (!res || strcmp(res, "la") != 0)
		fail++;
	free(res);

	// Edge case: len = 0
	res = ft_substr("hola", 0, 0);
	if (!res || strcmp(res, "") != 0)
		fail++;
	free(res);

	if (!fail)
		printf("[OK] ft_substr\n");
	else
		printf("[FAIL] ft_substr (%i)\n", fail);
}

static void	test_strjoin(void)
{
	int		fail = 0;
	char	*res;

	res = ft_strjoin("42", "Madrid");
	if (!res || strcmp(res, "42Madrid") != 0)
		fail++;
	free(res);

	res = ft_strjoin("", "Madrid");
	if (!res || strcmp(res, "Madrid") != 0)
		fail++;
	free(res);

	res = ft_strjoin("42", "");
	if (!res || strcmp(res, "42") != 0)
		fail++;
	free(res);

	res = ft_strjoin("", "");
	if (!res || strcmp(res, "") != 0)
		fail++;
	free(res);

	if (!fail)
		printf("[OK] ft_strjoin\n");
	else
		printf("[FAIL] ft_strjoin (%i)\n", fail);
}

static void	test_strtrim(void)
{
	int		fail = 0;
	char	*res;

	res = ft_strtrim("   hola mundo   ", " ");
	if (!res || strcmp(res, "hola mundo") != 0)
		fail++;
	free(res);

	res = ft_strtrim("...---xxx42xxx---...", ".-x");
	if (!res || strcmp(res, "42") != 0)
		fail++;
	free(res);

	// Edge case: Recorte total
	res = ft_strtrim("aaaaaa", "a");
	if (!res || strcmp(res, "") != 0)
		fail++;
	free(res);

	// Edge case: Cadena vacía
	res = ft_strtrim("", "abc");
	if (!res || strcmp(res, "") != 0)
		fail++;
	free(res);

	// Edge case: Set vacío
	res = ft_strtrim("hola", "");
	if (!res || strcmp(res, "hola") != 0)
		fail++;
	free(res);

	if (!fail)
		printf("[OK] ft_strtrim\n");
	else
		printf("[FAIL] ft_strtrim (%i)\n", fail);
}

static void	test_split(void)
{
	int		fail = 0;
	char	**tab;

	// Básico con delimitadores repetidos
	tab = ft_split("   hola   mundo   42   ", ' ');
	if (!tab || !tab[0] || strcmp(tab[0], "hola") != 0
		|| !tab[1] || strcmp(tab[1], "mundo") != 0
		|| !tab[2] || strcmp(tab[2], "42") != 0
		|| tab[3] != NULL)
		fail++;
	free_split_array(tab);

	// Cadena vacía
	tab = ft_split("", 'z');
	if (!tab || tab[0] != NULL)
		fail++;
	free_split_array(tab);

	// Todo delimitadores
	tab = ft_split("xxxxxx", 'x');
	if (!tab || tab[0] != NULL)
		fail++;
	free_split_array(tab);

	// Sin delimitadores presentes
	tab = ft_split("sin_delimitadores", ' ');
	if (!tab || !tab[0] || strcmp(tab[0], "sin_delimitadores") != 0 || tab[1] != NULL)
		fail++;
	free_split_array(tab);

	if (!fail)
		printf("[OK] ft_split\n");
	else
		printf("[FAIL] ft_split (%i)\n", fail);
}

static void	test_itoa(void)
{
	int		fail = 0;
	char	*res;

	res = ft_itoa(0);
	if (!res || strcmp(res, "0") != 0)
		fail++;
	free(res);

	res = ft_itoa(42);
	if (!res || strcmp(res, "42") != 0)
		fail++;
	free(res);

	res = ft_itoa(-42);
	if (!res || strcmp(res, "-42") != 0)
		fail++;
	free(res);

	res = ft_itoa(2147483647);
	if (!res || strcmp(res, "2147483647") != 0)
		fail++;
	free(res);

	res = ft_itoa(-2147483648);
	if (!res || strcmp(res, "-2147483648") != 0)
		fail++;
	free(res);

	if (!fail)
		printf("[OK] ft_itoa (0, INT_MAX, INT_MIN)\n");
	else
		printf("[FAIL] ft_itoa (%i)\n", fail);
}

static void	test_strmapi(void)
{
	char	*res;

	res = ft_strmapi("42madrid", mapi_toupper);
	if (res && strcmp(res, "42MADRID") == 0)
		printf("[OK] ft_strmapi\n");
	else
		printf("[FAIL] ft_strmapi\n");
	free(res);
}

static void	test_striteri(void)
{
	char	str[] = "42madrid";

	ft_striteri(str, iteri_toupper);
	if (strcmp(str, "42MADRID") == 0)
		printf("[OK] ft_striteri\n");
	else
		printf("[FAIL] ft_striteri\n");
}

/* Callbacks para prueba de descriptores */
static void	write_char_action(int fd) { ft_putchar_fd('Z', fd); }
static void	write_str_action(int fd)  { ft_putstr_fd("42Madrid", fd); }
static void	write_endl_action(int fd) { ft_putendl_fd("Linea", fd); }
static void	write_nbr_action(int fd)  { ft_putnbr_fd(-2147483648, fd); }

static void	test_fd_family(void)
{
	int	fail = 0;

	if (!capture_fd_output(write_char_action, "Z"))
		fail++;
	if (!capture_fd_output(write_str_action, "42Madrid"))
		fail++;
	if (!capture_fd_output(write_endl_action, "Linea\n"))
		fail++;
	if (!capture_fd_output(write_nbr_action, "-2147483648"))
		fail++;

	if (!fail)
		printf("[OK] ft_*_fd (putchar, putstr, putendl, putnbr via pipes)\n");
	else
		printf("[FAIL] ft_*_fd suite (%i)\n", fail);
}

/* ========================================================================== */
/*                                    MAIN                                    */
/* ========================================================================== */

int	main(void)
{
	printf("=========================================\n");
	printf("    LIBFT PARTE 2 - PRUEBAS DE ESTRÉS    \n");
	printf("=========================================\n");

	test_substr();
	test_strjoin();
	test_strtrim();
	test_split();
	test_itoa();
	test_strmapi();
	test_striteri();
	test_fd_family();

	printf("=========================================\n");
	return (0);
}
