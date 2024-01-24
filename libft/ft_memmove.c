/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlopez <hlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:56:34 by hlopez            #+#    #+#             */
/*   Updated: 2023/11/15 13:52:33 by hlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		while (size-- > 0)
		{
			((char *)dest)[size] = ((char *)src)[size];
		}
	}
	else
		ft_memcpy(dest, src, size);
	return (dest);
}
