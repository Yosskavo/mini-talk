#include "mini.h"

t_list yo;

void nothing(int i)
{
	yo.reseve_signal = 1;
}

void send_signal()
{
	kill();
}

void ft_ft(int sig)
{
	int j;
	if (yo.c != 0)
	{
		if (yo.c & yo.base)
		{
			yo.c = yo.c - yo.base;
			j = SIGUSR1;
			ft_printf("1");
		}
		else
		{
			j = SIGUSR2;
			ft_printf("0");
		}
		yo.base /= 2;
		if (yo.base == 0)
		{
			yo.c = *++yo.str;
			yo.base = 128;
			kill(yo.pid_get, j);
		}
		else
		{
			kill(yo.pid_get, j);
		}
		if (*yo.str == '\0')
			exit(0);
	}
}

int main(int ac, char **av)
{
	struct sigaction sa;

	yo.pid_get = atoi(av[1]);
	yo.str = av[2];
	yo.c = yo.str[0];
	yo.base = 128;
	yo.reseve_signal = 0;
	signal(SIGUSR1, nothing);
	ft_ft(0);
	while (1)
		pause();
}
