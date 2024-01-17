/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlopez <hlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:55:28 by hlopez            #+#    #+#             */
/*   Updated: 2024/01/17 17:07:37 by hlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal, siginfo_t *info, void *s)
{
	static unsigned char	c = 0;
	static int				bit = -1;

	(void)s;
	if (bit < 0)
		bit = 7;
	if (signal == SIGUSR1)
		c |= 1 << bit;
	else if (signal == SIGUSR2)
		c &= ~(1 << bit);
	if (!bit && c)
		ft_printf("%c", c);
	else if (!bit && !c)
		kill(info->si_pid, SIGUSR2);
	bit--;
	kill(info->si_pid, SIGUSR1);
}

int	main(int ac, char **av)
{
	struct sigaction	sig;
	sigset_t			s;

	(void)av;
	ft_printf("My PID: %d\n", getpid());
	ft_printf("Waiting for message from client ...\n");
	sigemptyset(&s);
	sigaddset(&s, SIGUSR1);
	sigaddset(&s, SIGUSR2);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_mask = s;
	sig.sa_handler = NULL;
	sig.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (ac == 1)
		pause();
	return (0);
}
