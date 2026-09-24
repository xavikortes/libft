#include "project/libft.h"

void content_show(void *content)
{
	printf("%s, ", (char *) content);
}

void *content_scream(void *content)
{
	void	*new;
	size_t	len;

	len = ft_strlen((char *) content) + 2;
	new = malloc(len);
	if (new == NULL)
		return (NULL);
	ft_strlcpy((char *) new, (char *) content, len);
	ft_strlcat((char *) new, "!", len);
	return (new);
}

void lst_show(t_list *lst)
{
	printf("(%i) ", ft_lstsize(lst));
	ft_lstiter(lst, &content_show);
	printf("\n");
}

int	main(void)
{
	t_list	*lst;
	t_list	*lst2;
	t_list	*lst3;

	printf("new (NULL) -> ");
	lst = ft_lstnew(NULL);
	lst_show(lst);

	printf("new hola -> ");
	lst = ft_lstnew(ft_strdup("hola"));
	lst_show(lst);

	printf("addfront adios -> ");
	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("adios")));
	lst_show(lst);

	printf("addfront (NULL) -> ");
	ft_lstadd_front(&lst, NULL);
	lst_show(lst);

	printf("addfront amigos -> ");
	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("amigos")));
	lst_show(lst);

	printf("last -> ");
	lst_show(ft_lstlast(lst));

	printf("last (NULL) -> ");
	lst_show(ft_lstlast(NULL));

	printf("addback gente -> ");
    ft_lstadd_back(&lst, ft_lstnew(ft_strdup("gente")));
    lst_show(lst);

	printf("addback (NULL) -> ");
    ft_lstadd_back(&lst, NULL);
    lst_show(lst);

    printf("last -> ");
    lst_show(ft_lstlast(lst));

	printf("addfront juan -> ");
    ft_lstadd_front(&lst, ft_lstnew(ft_strdup("juan")));
    lst_show(lst);

	printf("map (NULL) f -> ");
	lst2 = ft_lstmap(NULL, &content_scream, &free);
	lst_show(lst2);

	printf("map lst (NULL) -> ");
	lst2 = ft_lstmap(lst, NULL, &free);
	lst_show(lst2);

	printf("map lst content_scream -> ");
	lst2 = ft_lstmap(lst, &content_scream, &free);
	lst_show(lst2);

	printf("clear -> ");
	ft_lstclear(&lst, &free);
	lst_show(lst);

	printf("lst3 -> ");
	lst3 = ft_lstnew(ft_strdup("xx"));
	ft_lstadd_front(&lst3, ft_lstnew(ft_strdup("yy")));
	ft_lstadd_front(&lst3, ft_lstnew(ft_strdup("zz")));
	lst_show(lst3);

	t_list *to_delete = lst3->next;
	lst3->next = to_delete->next;

	printf("lst3 delone -> ");
	ft_lstdelone(to_delete, &free);
	lst_show(lst3);
}
