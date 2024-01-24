/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlopez <hlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:39:31 by hlopez            #+#    #+#             */
/*   Updated: 2023/11/17 13:23:18 by hlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t l)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (l < ft_strlen(dest) + 1)
		return (l + ft_strlen(src));
	while (dest[i] && i < l - 1)
		i++;
	while (src[j] && j + i < l - 1)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (i + ft_strlen(src));
}
