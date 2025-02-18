#include "mini.h"

t_list yo;

void ft_ft(int sig)
{
	while (yo.c != 0)
	{
		if (yo.c & yo.base)
		{
			yo.c = yo.c - yo.base;
			kill(yo.pid_get, SIGUSR1);
			ft_printf("1");
		}
		else
		{
			kill(yo.pid_get, SIGUSR2);
			ft_printf("0");
		}
		yo.base /= 2;
		if (yo.base == 0)
		{
			yo.c = *++yo.str;
			yo.base = 128;
		}
		while (1)
			usleep(500);
	}
}

int main(int ac, char **av)
{
	struct sigaction sa;

	sa.sa_flags = 0;
	sa.sa_handler = ft_ft;
	sigemptyset(&sa.sa_mask);
	yo.pid_get = atoi(av[1]);
	yo.str = av[2];
	yo.c = yo.str[0];
	yo.base = 128;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		perror("yeap");
	ft_ft(0);
}
