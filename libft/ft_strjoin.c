/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlopez <hlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:11:38 by hlopez            #+#    #+#             */
/*   Updated: 2023/11/09 18:35:27 by hlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_size;
	int		s2_size;
	char	*dest;
	int		i;
	int		j;

	s1_size = ft_strlen((char *)s1);
	s2_size = ft_strlen((char *)s2);
	dest = (char *)malloc((s1_size + s2_size + 1) * sizeof(char));
	if (!dest)
		return (0);
	i = 0;
	j = 0;
	while (j < s1_size)
		dest[i++] = s1[j++];
	j = 0;
	while (j < s2_size)
		dest[i++] = s2[j++];
	dest[i] = '\0';
	return (dest);
}
