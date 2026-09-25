/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcortes <jcortes@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 12:23:10 by jcortes           #+#    #+#             */
/*   Updated: 2026/09/25 13:06:22 by jcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calculate_len(char *s, char c)
{
	char	*ptr;

	ptr = ft_strchr(s, c);
	if (ptr == NULL)
		return (1);
	return (1 + calculate_len(++ptr, c));
}

static char	*set_str_item(char **dst, char *s, char c)
{
	int		size;
	char	*ptr;

	ptr = ft_strchr(s, c);
	if (ptr == NULL)
		size = ft_strlen(s);
	else
		size = ptr - s;
	*dst = ft_calloc(size + 1, sizeof(char));
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(*dst, s, size + 1);
	return (++ptr);
}

static char	**free_arr(char **arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
		free(arr[i]);
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		len;
	char	**arr;
	char	*ptr;

	if (s == NULL)
		return (NULL);
	i = 0;
	ptr = (char *) s;
	len = calculate_len(ptr, c);
	arr = ft_calloc(len + 1, sizeof(char *));
	if (arr == NULL)
		return (NULL);
	while (i < len)
	{
		ptr = set_str_item(&arr[i], ptr, c);
		if (arr[i] == NULL)
			return (free_arr(arr, len));
		i++;
	}
	arr[len] = NULL;
	return (arr);
}
