#include "mini.h"

t_server yo;

void ft_handler(int sig, siginfo_t *info, void *context)
{
	if (sig == SIGUSR1)
	{
		yo.save_char += yo.base & 255;
		yo.base /= 2;
	}
	else
	{
		yo.base /= 2;
	}
	if (yo.base == 0)
	{
		write(1, &(yo.save_char), 1);
		yo.base = 128;
		yo.save_char = 0;
	}
	usleep(500);
	kill (info->si_pid, SIGUSR1);
}

int main (void)
{
	struct sigaction sa;

	sa.sa_sigaction = ft_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	yo.base = 128;
	yo.save_char = 0;
	
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (perror("hadono"), 1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (perror("hello"), 1);
	ft_printf("this is your pid : %d \n", getpid());
	while (1)
		pause();
}
