#ifndef MINI_H
# define MINI_H

// client things i think

typedef struct s_client 
{
	int pid_get;
	int base;
	int reseve_signal;
} t_client;

// sever things

typedef struct s_server
{
	int save_char;
	int base;
} t_server; 

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "printf/ft_printf.h"

# endif
