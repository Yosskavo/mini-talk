/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:47:43 by yel-mota          #+#    #+#             */
/*   Updated: 2025/02/08 13:43:03 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void ft_send_string(char c, int ser_pid)
{
	int i = 128;
	int j = (int)c;
	while (i != 0)
	{
		if (j >= i)
		{
			j = j - i;
			kill(ser_pid, SIGUSR1);
		}
		else
			kill(ser_pid, SIGUSR2);
		i /= 2;
		usleep(1);
	}
}

int main(int ac, char **av)
{
	int i;
	int	j;
	if (ac != 3)
		return (1);
	j = 0;
	i = ft_atoi(av[1]);
	while (av[2][j] != '\0')
		ft_send_string(av[2][j++], i);
	return (0);
}
