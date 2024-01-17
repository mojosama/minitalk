/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlopez <hlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:59:56 by hlopez            #+#    #+#             */
/*   Updated: 2024/01/17 17:07:53 by hlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int				minus_nbr;
	size_t			i;
	long long int	res;

	minus_nbr = 1;
	i = 0;
	res = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus_nbr = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res != ((res * 10 + (str[i] - '0')) / 10))
			return ((int)((minus_nbr + 1) / 2 / -1));
		res = 10 * res + (str[i] - '0');
		i++;
	}
	res *= minus_nbr;
	return ((int)res);
}
