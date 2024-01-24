/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlopez <hlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:29:05 by hlopez            #+#    #+#             */
/*   Updated: 2023/11/17 13:22:12 by hlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *pointer1, const void *pointer2, size_t size)
{
	size_t	i;
	int		a;

	i = 0;
	a = 0;
	while (i < size && a == 0)
	{
		a = ((unsigned char *)pointer1)[i] - ((unsigned char *)pointer2)[i];
		i++;
	}
	return (a);
}
