/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlopez <hlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:23:03 by hlopez            #+#    #+#             */
/*   Updated: 2023/11/15 15:11:07 by hlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	n;
	int	check;

	n = 0;
	check = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (check == 0)
				n++;
			check = 1;
		}
		else
			check = 0;
		s++;
	}
	return (n);
}

static char	*ft_create_sub_string(char const *s, char c, int *j)
{
	char	*res;
	int		k;

	k = 0;
	while (s[*j] == c)
		(*j)++;
	while (s[*j + k] != c && s[*j + k])
		k++;
	res = ft_substr(s, *j, k);
	*j += k;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		n;
	int		i;
	int		j;

	n = ft_count_words(s, c);
	dest = (char **)malloc((n + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (i < n)
	{
		dest[i] = ft_create_sub_string(s, c, &j);
		if (!dest[i])
		{
			while (i >= 0)
				free(dest[i--]);
			free(dest);
			return (NULL);
		}
		i++;
	}
	dest[n] = 0;
	return (dest);
}
