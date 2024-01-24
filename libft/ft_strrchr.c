/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlopez <hlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:09:53 by hlopez            #+#    #+#             */
/*   Updated: 2023/11/15 14:21:28 by hlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	if ((char)c == 0)
		return (str + ft_strlen(str));
	while (str[i])
	{
		if (str[i] == (char)c)
			j = i;
		i++;
	}
	if (j == -1)
		return (0);
	return (str + j);
}
