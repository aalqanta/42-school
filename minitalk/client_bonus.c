/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalqanta <aalqanta@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 03:46:38 by aalqanta          #+#    #+#             */
/*   Updated: 2025/05/12 20:45:17 by aalqanta         ###   ########.fr       */
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

int	ft_atoi(const char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			write(1, "ERROR: WRONG PID\n", 18);
			return (-1);
		}
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

void	handle_ack(int sig)
{
	if (sig == SIGUSR1)
		g_val = 1;
	else if (sig == SIGUSR2)
	{
		write(1, "✅ Message delivered!\n", 23);
		exit(0);
	}
}

void	send_signal(int pid, char c)
{
	int	bit;
	int	i;

	bit = 0;
	i = 0;
	while (bit < 8)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i = 0;
		while (++i < 100 && g_val == 0)
			usleep(100);
		if (i == 100)
		{
			write(1, "make sure everything correct!", 21);
			exit(1);
		}
		else
			g_val = 0;
		bit++;
	}
}

int	main(int ac, char **av)
{
	unsigned char	*msg;
	int				pid;

	msg = (unsigned char *)av[2];
	if (ac != 3)
	{
		write(1, "Please input: PID+String \n", 27);
		return (1);
	}
	signal(SIGUSR1, handle_ack);
	signal(SIGUSR2, handle_ack);
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		write(1, "Invalid PID\n", 12);
		return (1);
	}
	while (*msg)
	{
		send_signal(pid, *msg);
		msg++;
	}
	send_signal(pid, '\0');
	while (1)
		pause();
}
