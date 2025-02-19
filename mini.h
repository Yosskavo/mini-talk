#ifndef MINI_H
# define MINI_H

typedef struct s_list 
{
// client things i think
	char *str;
	int pid_get;
	int c;
	int reseve_signal;
// sever things
	int base;
	int save_char;
} t_list;

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

# endif
