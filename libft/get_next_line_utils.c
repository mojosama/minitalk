/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlopez <hlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:44:51 by hlopez            #+#    #+#             */
/*   Updated: 2024/01/22 12:59:33 by hlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin_custom(char *s1, char *s2, size_t n)
{
	char	*dest;
	size_t	size;
	size_t	i;
	size_t	j;

	if (!s1)
		return (free(s1), s1 = NULL, ft_strndup(s2, n));
	size = ft_strlen(s1) + n + 1;
	dest = (char *)ft_calloc(size, sizeof(char));
	if (!dest)
		return (free(s1), s1 = NULL, NULL);
	i = 0;
	while (s1 && s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] && j < n)
	{
		dest[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (s1 = NULL, dest);
}

size_t	ft_strlen(char *s)
{
	size_t	l;

	if (!s)
		return (0);
	l = 0;
	while (s[l])
		l++;
	return (l);
}

char	*ft_substr_custom(char *s, unsigned int start)
{
	unsigned int	i;
	char			*dest;
	size_t			len;

	i = 0;
	if (!s || !*s || start >= ft_strlen(s))
	{
		if (s)
			free(s);
		s = NULL;
		return (NULL);
	}
	len = ft_strlen(s) - start;
	dest = (char *)ft_calloc((len + 1), sizeof(char));
	if (!dest)
		return (free(s), s = NULL, NULL);
	while (i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	free(s);
	return (dest);
}

char	*ft_strndup(char *src, size_t l)
{
	char	*dest;
	size_t	i;

	if (!src)
		return (NULL);
	if (l > ft_strlen(src))
		l = ft_strlen(src);
	dest = (char *)ft_calloc((l + 1), sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] && i < l)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_calloc(size_t elementCount, size_t elementSize)
{
	char	*dest;
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
		dest[i++] = 0;
	return (dest);
}
