/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlopez <hlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:36:05 by hlopez            #+#    #+#             */
/*   Updated: 2023/11/17 14:41:21 by hlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*dest;
	size_t	i;

	if (!elementSize || !elementCount)
		return (malloc(0));
	if (elementCount > ((size_t)-1) / elementSize)
		return (NULL);
	dest = malloc(elementCount * elementSize);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < elementCount * elementSize)
		((char *)dest)[i++] = 0;
	return (dest);
}
