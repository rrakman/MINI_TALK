/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 23:15:59 by rrakman           #+#    #+#             */
/*   Updated: 2023/04/22 15:06:46 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	encode_helper(int c, int *binary, int i)
{
	if (c == 0)
		return ;
	if (c % 2 == 0)
		binary[i] = 0;
	else
		binary[i] = 1;
	encode_helper(c / 2, binary, i - 1);
}

int	*encode(int c)
{
	int	*binary;
	int	i;

	i = 0;
	binary = (int *)malloc(sizeof(int) * 8);
	if (!binary)
		return (0);
	while (i < 8)
		binary[i++] = 0;
	encode_helper(c, binary, 7);
	return (binary);
}

void	send_char(pid_t s_pid, unsigned char c)
{
	int	*binary;
	int	i;

	binary = encode(c);
	i = 0;
	while (i < 8)
	{
		if (binary[i] == 0)
			kill(s_pid, SIGUSR1);
		else
			kill(s_pid, SIGUSR2);
		i++;
		usleep(300);
	}
	free(binary);
}

int	main(int ac, char **av)
{
	pid_t	pid;
	int		i;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0 || kill(pid, 0) == -1)
		{
			ft_printf("Error: pid invalid.\n");
			exit (1);
		}
		ft_printf("Client: Message sending is loading...\n");
		i = -1;
		while (av[2][++i])
			send_char(pid, av[2][i]);
		send_char(pid, '\0');
	}
	else
		ft_printf("Usage: %s Server_PID YourMessage\n", av[0]);
	return (0);
}
