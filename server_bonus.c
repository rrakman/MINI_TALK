/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 23:16:02 by rrakman           #+#    #+#             */
/*   Updated: 2023/04/22 15:06:37 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned long	power(int i)
{
	unsigned long	p;

	p = 1;
	while (i--)
		p *= 2;
	return (p);
}

unsigned char	bi2ascii(int *binary)
{
	unsigned char	c;
	int				i;

	c = 0;
	i = 0;
	while (i < 8)
	{
		c += binary[i] * power(7 - i);
		i++;
	}
	return (c);
}

void	handler(int signum, siginfo_t *sig_info, void *notused)
{
	static int		i;
	static int		pid;
	static int		binary[8];
	unsigned char	c;

	(void)notused;
	if (!pid)
		pid = sig_info->si_pid;
	if (pid != sig_info->si_pid)
	{
		pid = sig_info->si_pid;
		i = 0;
	}
	if (signum == SIGUSR1)
		binary[i++] = 0;
	if (signum == SIGUSR2)
		binary[i++] = 1;
	if (i == 8)
	{
		c = bi2ascii(binary);
		ft_printf("%c", c);
		i = 0;
		if (c == '\0')
			kill(sig_info->si_pid, SIGUSR1);
	}
}

int	main(int ac, char *av[])
{
	struct sigaction	sa;

	*av = 0;
	if (ac > 1)
	{
		write(2, "Error, you need to run the program without arguments!", 53);
		return (0);
	}
	ft_printf("Server PID = %d\n", getpid());
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
	return (0);
}
