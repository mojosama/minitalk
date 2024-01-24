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

static int	check_pid(char *pid)
{
	size_t	i;

	i = 0;
	while (pid[i])
	{
		if (!ft_isdigit(pid[i++]))
			return (0);
	}
	return (ft_atoi(pid));
}

int	main(int ac, char **av)
{
	pid_t	pid;
	size_t	i;

	if (ac == 3)
	{
		pid = check_pid(av[1]);
		if (!pid)
		{
			ft_printf("Please enter a valid PID.\n");
			return (1);
		}
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
