#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return;
	f(lst->content);
	if (lst->next != NULL)
		ft_lstiter(lst->next, f);
}
