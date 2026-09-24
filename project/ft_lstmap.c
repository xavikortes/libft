#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*content;
	t_list	*new;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	content = (*f)(lst->content);
	new = ft_lstnew(content);
	if (new == NULL)
	{
		(*del)(content);
		return (NULL);
	}
	new->next = ft_lstmap(lst->next, f, del);
	if (lst->next != NULL && new->next == NULL)
	{
		ft_lstclear(&new, del);
		return (NULL);	
	}
	return (new);
}
