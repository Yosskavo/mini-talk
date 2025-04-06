/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:20:54 by yel-mota          #+#    #+#             */
/*   Updated: 2025/02/26 22:51:58 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_bonus.h"

t_client_bonus	g_yo;

static void	nothing(int i)
{
	g_yo.reseve_signal = 1;
}

static void	last_order(int i)
{
	ft_printf("the message send to the server, yallah ghiyarha\n");
	exit(0);
}

static void	send_signal(int signum)
{
	if (kill(g_yo.pid_get, signum) == -1)
	{
		write(2, "error", 6);
		exit(1);
	}
	while (!g_yo.reseve_signal)
		pause();
	g_yo.reseve_signal = 0;
}

void	send_char_bonus(char c)
{
	int	j;

	while (g_yo.base != 0)
	{
		if (c & g_yo.base)
		{
			c = c - g_yo.base;
			j = SIGUSR1;
		}
		else
			j = SIGUSR2;
		g_yo.base /= 2;
		send_signal(j);
	}
	g_yo.base = 128;
}

int	main(int ac, char **av)
{
	if (ac != 3)
		return (write(2, "worng argument number", 22), 1);
	g_yo.pid_get = ft_atoi(av[1]);
	if (g_yo.pid_get <= 0)
		return (write(2, "invalid pid", 12), 1);
	signal(SIGUSR1, nothing);
	signal (SIGUSR2, last_order);
	g_yo.reseve_signal = 0;
	g_yo.base = 128;
	send_the_string_bonus(av[2]);
	return (0);
}
