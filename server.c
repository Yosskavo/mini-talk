/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:12:01 by yel-mota          #+#    #+#             */
/*   Updated: 2025/02/08 13:43:40 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_list *one;

void ft_restart(void)
{
	ft_printf("%c", one->c);
	one->base = 128;
	one->c = 0;
}

void ft_0(int signal)
{
	one->c += one->base * 0;
       if ((one->base /= 2) == 0)
	       ft_restart();  
}

void ft_1 (int signal)
{
	one->c += one->base * 1;
       if ((one->base /= 2) == 0)
       		ft_restart(); 
}

int	main(void)
{
	signal(SIGUSR1, ft_1);
	signal(SIGUSR2, ft_0);
	one = malloc(sizeof(t_list));
	if (!one)
		return (1);
	one->c = 0;
	one->base = 128;
	ft_printf("the PID of the server : %d\n", getpid());
	while (77)
		pause();
	free(one);
	return (0);
}
