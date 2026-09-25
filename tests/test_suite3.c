#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define COLOR_GREEN "\033[0;32m"
#define COLOR_RED   "\033[0;31m"
#define COLOR_BLUE  "\033[0;34m"
#define COLOR_RESET "\033[0m"

static void	del_str(void *content)
{
	free(content);
}

static void	iter_toupper(void *content)
{
	char	*str;
	size_t	i;

	if (!content)
		return ;
	str = (char *)content;
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
}

static void	*map_duplicate_and_invert(void *content)
{
	char	*src;
	char	*copy;
	size_t	len;
	size_t	i;

	if (!content)
		return (NULL);
	src = (char *)content;
	len = strlen(src);
	copy = (char *)malloc(len + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = src[len - 1 - i];
		i++;
	}
	copy[len] = '\0';
	return (copy);
}

static void	test_lstnew_edge_cases(void)
{
	t_list	*node;

	printf(COLOR_BLUE "-> Testing ft_lstnew\n" COLOR_RESET);
	node = ft_lstnew(NULL);
	assert(node != NULL);
	assert(node->content == NULL);
	assert(node->next == NULL);
	free(node);

	char *text = strdup("nodo_prueba");
	node = ft_lstnew(text);
	assert(node != NULL);
	assert(strcmp((char *)node->content, "nodo_prueba") == 0);
	assert(node->next == NULL);
	free(text);
	free(node);
	printf(COLOR_GREEN "[OK] ft_lstnew paso las pruebas de contorno\n" COLOR_RESET);
}

static void	test_null_safeties(void)
{
	t_list			*node;
	unsigned int	sz;

	printf(COLOR_BLUE "-> Testing NULL Protections\n" COLOR_RESET);
	ft_lstadd_front(NULL, NULL);
	node = ft_lstnew(strdup("orphan"));
	ft_lstadd_front(NULL, node);
	free(node->content);
	free(node);

	sz = ft_lstsize(NULL);
	assert(sz == 0);

	assert(ft_lstlast(NULL) == NULL);

	ft_lstadd_back(NULL, NULL);
	node = ft_lstnew(strdup("orphan2"));
	ft_lstadd_back(NULL, node);
	free(node->content);
	free(node);

	ft_lstdelone(NULL, del_str);
	ft_lstclear(NULL, del_str);
	ft_lstiter(NULL, iter_toupper);
	assert(ft_lstmap(NULL, map_duplicate_and_invert, del_str) == NULL);
	assert(ft_lstmap(NULL, NULL, del_str) == NULL);
	assert(ft_lstmap(NULL, map_duplicate_and_invert, NULL) == NULL);

	printf(COLOR_GREEN "[OK] Comportamiento blindado contra NULL verificado\n" COLOR_RESET);
}

static void	test_fifo_lifo_combinations(void)
{
	t_list	*list;
	t_list	*last;

	printf(COLOR_BLUE "-> Testing Stack/Queue ordering\n" COLOR_RESET);
	list = NULL;

	ft_lstadd_front(&list, ft_lstnew(strdup("3")));
	ft_lstadd_front(&list, ft_lstnew(strdup("2")));
	ft_lstadd_front(&list, ft_lstnew(strdup("1")));
	assert(ft_lstsize(list) == 3);
	assert(strcmp((char *)list->content, "1") == 0);

	ft_lstadd_back(&list, ft_lstnew(strdup("4")));
	ft_lstadd_back(&list, ft_lstnew(strdup("5")));
	assert(ft_lstsize(list) == 5);

	last = ft_lstlast(list);
	assert(last != NULL);
	assert(strcmp((char *)last->content, "5") == 0);

	ft_lstclear(&list, del_str);
	assert(list == NULL);
	printf(COLOR_GREEN "[OK] Inserciones front, back y vaciado validados\n" COLOR_RESET);
}

static void	test_iter_and_map(void)
{
	t_list	*list;
	t_list	*mapped;

	printf(COLOR_BLUE "-> Testing ft_lstiter & ft_lstmap\n" COLOR_RESET);
	list = NULL;
	ft_lstadd_back(&list, ft_lstnew(strdup("abc")));
	ft_lstadd_back(&list, ft_lstnew(strdup("def")));
	ft_lstadd_back(&list, ft_lstnew(strdup("ghi")));

	ft_lstiter(list, iter_toupper);
	assert(strcmp((char *)list->content, "ABC") == 0);
	assert(strcmp((char *)list->next->content, "DEF") == 0);
	assert(strcmp((char *)list->next->next->content, "GHI") == 0);

	mapped = ft_lstmap(list, map_duplicate_and_invert, del_str);
	assert(mapped != NULL);
	assert(ft_lstsize(mapped) == 3);

	// Invertidas: "CBA", "FED", "IHG"
	assert(strcmp((char *)mapped->content, "CBA") == 0);
	assert(strcmp((char *)mapped->next->content, "FED") == 0);
	assert(strcmp((char *)mapped->next->next->content, "IHG") == 0);

	// La original no debe alterarse tras el map
	assert(strcmp((char *)list->content, "ABC") == 0);

	ft_lstclear(&list, del_str);
	ft_lstclear(&mapped, del_str);
	assert(list == NULL && mapped == NULL);
	printf(COLOR_GREEN "[OK] Transformacion iterativa y mapeo validados\n" COLOR_RESET);
}

static void	test_stress_10k_nodes(void)
{
	t_list			*list;
	t_list			*mapped;
	unsigned int	i;
	unsigned int	total;

	total = 10000;
	list = NULL;
	printf(COLOR_BLUE "-> Testing Stress: Insercion masiva de %u nodos...\n" COLOR_RESET, total);

	i = 0;
	while (i < total)
	{
		ft_lstadd_front(&list, ft_lstnew(strdup("stress_payload")));
		i++;
	}

	assert(ft_lstsize(list) == total);

	mapped = ft_lstmap(list, map_duplicate_and_invert, del_str);
	assert(mapped != NULL);
	assert(ft_lstsize(mapped) == total);

	ft_lstclear(&list, del_str);
	ft_lstclear(&mapped, del_str);
	assert(list == NULL && mapped == NULL);
	printf(COLOR_GREEN "[OK] Test de estres (10.000 nodos) completado exitosamente\n" COLOR_RESET);
}

int	main(void)
{
	printf("\n========================================\n");
	printf("   SUITE DE PRUEBAS DE LISTAS (LIBFT)   \n");
	printf("========================================\n\n");

	test_lstnew_edge_cases();
	test_null_safeties();
	test_fifo_lifo_combinations();
	test_iter_and_map();
	test_stress_10k_nodes();

	printf("\n" COLOR_GREEN "[RESULTADO] Todos los tests de listas pasaron sin errores.\n" COLOR_RESET);
	return (0);
}
