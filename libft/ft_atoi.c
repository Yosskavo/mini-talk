/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 23:49:48 by yel-mota          #+#    #+#             */
/*   Updated: 2025/02/20 21:50:17 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlibft.h"

int	ft_atoi(char *ptr)
{
	int (sins), (res);
	if (!ptr)
		return (0);
	while (' ' == *ptr || (*ptr >= 9 && *ptr <= 13))
		ptr++;
	sins = 1;
	if (*ptr == '+' || *ptr == '-')
		if (*ptr++ == '-')
			sins = -1;
	res = 0;
	while (('0' <= *ptr && *ptr <= '9') && *ptr != '\0')
	{
		res = res * 10 + *ptr - '0';
		ptr++;
	}
	return (res * sins);
}
