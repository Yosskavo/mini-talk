#include "mini.h"

t_client yo;

void nothing(int i)
{
	yo.reseve_signal = 1;
}

void send_signal(int signum)
{
	kill(yo.pid_get, signum);
	while (!yo.reseve_signal)
		pause();
	yo.reseve_signal = 0;
}

void send_char(char c)
{
	int j;

	while (c != 0)
	{
		if (c & yo.base)
		{
			c = c - yo.base;
			j = SIGUSR1;
			ft_printf("1");
		}
		else
		{
			j = SIGUSR2;
			ft_printf("0");
		}
		yo.base /= 2;
		send_signal(j);
	}
}

void send_the_string(char *str)
{
	while (*str != '\0')
	{
		yo.base = 128;
		send_char(*str++);
	}
	send_char('\0');
}

int main(int ac, char **av)
{
	struct sigaction sa;

	yo.pid_get = atoi(av[1]);
	signal(SIGUSR1, nothing);
	yo.reseve_signal = 0;
	send_the_string(av[2]);
}
