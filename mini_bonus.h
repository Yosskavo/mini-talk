/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:36:37 by yel-mota          #+#    #+#             */
/*   Updated: 2025/02/21 19:12:11 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_BONUS_H
# define MINI_BONUS_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include "printf/ft_printf.h"
# include "libft/ftlibft.h"

// client things i think

typedef struct s_client_bonus
{
	int	pid_get;
	int	base;
	int	reseve_signal;
}	t_client_bonus;

// sever things

typedef struct s_server_bonus
{
	int	save_char;
	int	base;
	int	null_sig;
}	t_server_bonus;

void		send_char_bonus(char c);
void		send_the_string_bonus(char *str);

#endif
