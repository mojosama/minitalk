/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlopez <hlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:48:19 by hlopez            #+#    #+#             */
/*   Updated: 2024/01/19 18:17:42 by hlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_check;

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

static void	get_answer(int signal)
{
	if (signal == SIGUSR2)
		ft_printf("Message received by server.\n");
	else if (signal == SIGUSR1)
		g_check = 1;
}

static void	send_char(pid_t pid, unsigned char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		g_check = 0;
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
		while (!g_check)
			usleep(100);
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;
	size_t	i;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		i = 0;
		signal(SIGUSR1, get_answer);
		signal(SIGUSR2, get_answer);
		while (av[2][i])
			send_char(pid, av[2][i++]);
		send_char(pid, '\n');
		send_char(pid, 0);
	}
	else
	{
		ft_printf("Incorrect parameters, you need to pass 2 arguments:\n");
		ft_printf("- The server PID\n- The string to send\n");
	}
	return (0);
}
