/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:41:15 by lfrank            #+#    #+#             */
/*   Updated: 2022/11/24 10:51:54 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned long nb, int b_is_X)
{
	int		result[100];
	int		i;
	int		len;
	char	*hex;

	i = 0;
	len = 0;
	hex = B_16MAJ;
	if (b_is_X == 0)
		hex = B_16MIN;
	while (nb >= 16)
	{
		result[i] = hex[nb % 16];
		nb = nb / 16;
		i++;
	}
	result[i] = hex[nb];
	while (i >= 0)
	{
		len += ft_printchar(result[i]);
		i--;
	}
	return (len);
}
