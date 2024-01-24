/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlopez <hlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:42:07 by hlopez            #+#    #+#             */
/*   Updated: 2023/11/15 13:33:07 by hlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int				nb[10];
	int				i;
	unsigned int	num;

	i = 0;
	if (n < 0)
	{
		write(fd, "-", 1);
		num = -n;
	}
	else
		num = n;
	while (num / 10 > 0)
	{
		nb[i] = num % 10 + 48;
		num /= 10;
		i++;
	}
	num += 48;
	write(fd, &num, 1);
	while (i-- > 0)
		write(fd, &nb[i], 1);
}
