/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlopez <hlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:42:49 by hlopez            #+#    #+#             */
/*   Updated: 2023/11/17 13:25:36 by hlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_includes(char c, char const *s)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*dest;
	size_t		n1;
	size_t		n2;
	int			i;
	size_t		size;

	n1 = 0;
	n2 = 0;
	size = ft_strlen((char *)s1);
	while (ft_includes(s1[n1], set) && size > 0)
		n1++;
	while (ft_includes(s1[size - n2 - 1], set) && size > 0 && n2 < size - n1)
		n2++;
	dest = (char *)malloc((size - (n1 + n2) + 1) * sizeof(char));
	if (!dest)
		return (0);
	i = 0;
	while (n1 < size - n2)
		dest[i++] = s1[n1++];
	dest[i] = '\0';
	return (dest);
}
