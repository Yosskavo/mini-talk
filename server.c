/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:38:35 by yel-mota          #+#    #+#             */
/*   Updated: 2025/02/26 22:45:28 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

t_server	g_yo;

static void	ft_handler(int sig, siginfo_t *info, void *context)
{
	static int	old_pid;

	if (old_pid == 0)
		old_pid = info->si_pid;
	if (info->si_pid != old_pid)
	{
		g_yo.save_char = 0;
		g_yo.base = 128;
		old_pid = info->si_pid;
	}
	if (sig == SIGUSR1)
		g_yo.save_char += g_yo.base * 1;
	g_yo.base /= 2;
	if (g_yo.base == 0)
	{
		write(1, &(g_yo.save_char), 1);
		g_yo.base = 128;
		g_yo.save_char = 0;
	}
	usleep (100);
	kill (info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &ft_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	g_yo.base = 128;
	g_yo.save_char = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (perror("error in the server!"), 1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (perror("error in the server!"), 1);
	ft_printf("this is pid of the server : %d \n", getpid());
	while (1)
		pause();
	return (0);
}
