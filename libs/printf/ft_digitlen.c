/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:10:42 by lfrank            #+#    #+#             */
/*   Updated: 2022/11/10 19:54:23 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_return_diu(int number, int len)
{
	while (number)
	{
		number /= 10;
		len++;
	}
	return (len);
}

static int	ft_return_xp(int number, int len)
{
	while (number)
	{
		number /= 16;
		len++;
	}
	return (len);
}

int	ft_digitlen(int nb, char c)
{
	int	len;
	int	number;
	int	neg;

	len = 0;
	if (!nb)
		return (1);
	if (nb < 0)
	{
		neg = 1;
		number = -nb;
	}
	else
	{
		neg = 0;
		number = nb;
	}
	if (c == 'd' || c == 'i' || c == 'u')
		return (ft_return_diu(number, len) + neg);
	if (c == 'x' || c == 'p')
		return (ft_return_xp(number, len));
	return (0);
}
