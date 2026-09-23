/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcortes <jcortes@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:37:25 by jcortes           #+#    #+#             */
/*   Updated: 2026/09/23 12:39:48 by jcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	len = ft_strlen(to_find);
	while (str[i] != '\0' && i < size)
	{
		if (str[i] == *to_find)
		{
			if (!ft_strncmp(str + i, to_find, len))
				return ((char *)str + i);
		}
		i++;
	}
	return (NULL);
}
