/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlopez <hlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:08:46 by hlopez            #+#    #+#             */
/*   Updated: 2023/11/15 14:05:34 by hlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_int_size(int n)
{
	int				size;
	unsigned int	num;

	size = 0;
	if (n <= 0)
	{
		size++;
		num = -n;
	}
	else
		num = n;
	while (num >= 1)
	{
		size++;
		num /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char			*res;
	int				size;
	unsigned int	num;

	size = ft_get_int_size(n);
	res = (char *)malloc(sizeof(char) * size + 1);
	if (!res)
		return (0);
	if (n < 0)
	{
		res[0] = '-';
		num = -n;
	}
	else
		num = n;
	res[size] = '\0';
	while (size > 0 && res[size - 1] != '-')
	{
		res[--size] = (num % 10) + '0';
		num /= 10;
	}
	return (res);
}
