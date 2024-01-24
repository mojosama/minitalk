/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlopez <hlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:20:51 by hlopez            #+#    #+#             */
/*   Updated: 2023/11/17 13:21:58 by hlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	size_t	i;
	char	*t;

	i = 0;
	t = (char *)memoryBlock;
	while (i < size)
	{
		if (t[i] == (char)searchedChar)
			return (&t[i]);
		i++;
	}
	return (0);
}
