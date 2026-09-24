#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = ft_calloc(1, sizeof(t_list));
	if (lst == NULL)
		return (lst);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}
