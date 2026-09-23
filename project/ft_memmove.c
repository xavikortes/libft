/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcortes <jcortes@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 13:12:54 by jcortes           #+#    #+#             */
/*   Updated: 2026/09/23 13:25:28 by jcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	tmp[ft_strlen(src)];

	i = 0;
	while (i < n)
	{
		((char *) tmp)[i] = ((char *) src)[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		((char *) dst)[i] = ((char *) tmp)[i];
		i++;
	}
	return (dst);
}
