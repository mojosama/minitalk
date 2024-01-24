/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlopez <hlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:40:58 by hlopez            #+#    #+#             */
/*   Updated: 2023/11/17 13:24:39 by hlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	c;

	i = 0;
	if (*to_find == '\0')
		return ((char *)str);
	while (str[i] && i < n)
	{
		c = 0;
		if (str[i] == to_find[c])
		{
			while (str[i + c] == to_find[c] && i + c < n)
			{
				if (to_find[c + 1] == '\0')
					return ((char *)str + i);
				c++;
			}
		}
		i++;
	}
	return (0);
}
