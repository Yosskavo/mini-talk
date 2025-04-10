/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:36:37 by yel-mota          #+#    #+#             */
/*   Updated: 2025/02/21 17:35:31 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include "printf/ft_printf.h"
# include "libft/ftlibft.h"

// client things i think

typedef struct s_client
{
	int	pid_get;
	int	base;
	int	reseve_signal;
}	t_client;

// sever things

typedef struct s_server
{
	int	save_char;
	int	base;
}	t_server;

#endif
