/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:45:26 by yel-mota          #+#    #+#             */
/*   Updated: 2025/02/18 10:52:04 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int	ft_strlen(const char *str);
int	ft_unint(unsigned int n);
int	ft_putstr(char *s);
int	ft_putone(va_list one, const char str);
int	ft_putnbr_base(unsigned int nbr, char *base);
int	ft_putchar(const char c);
int	ft_putaddress(void *p);
int	ft_printf(const char *str, ...);
int	ft_nbr(int n);
int	ft_countnbr(unsigned int n);

# endif
