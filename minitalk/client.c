/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalqanta <aalqanta@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:17:22 by aalqanta          #+#    #+#             */
/*   Updated: 2025/05/08 16:09:34 by aalqanta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

volatile int	g_val = 0;

void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			write(1, "ERROR:WRONG-PID\n", 17);
			return (-1);
		}
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result);
}

void	handle_ack(int sig)
{
	if (sig == SIGUSR1)
		g_val = 1;
	else if (sig == SIGUSR2)
		exit(0);
}

void	send_signal(int pid, char c)
{
	int	bit;
	int	i;

	i = 0;
	bit = 0;
	while (bit < 8)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (i < 100 && g_val == 0)
			usleep(100);
		g_val = 0;
		bit++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac != 3)
	{
		write(1, "wrong input\n", 12);
		return (1);
	}
	pid = ft_atoi(av[1]);
	write(1, "Sending to PID: ", 17);
	ft_putnbr(pid);
	write(1, "\n", 1);
	signal(SIGUSR1, handle_ack);
	signal(SIGUSR2, handle_ack);
	while (av[2][i])
	{
		send_signal(pid, av[2][i]);
		i++;
	}
	send_signal(pid, '\0');
	return (0);
}
