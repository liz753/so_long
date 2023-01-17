/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:00:11 by lfrank            #+#    #+#             */
/*   Updated: 2022/11/10 19:31:51 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr_u(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb > 9)
	{
		len += ft_printnbr_u(nb / 10);
		len += ft_printnbr_u(nb % 10);
	}
	else
		len += ft_printchar(nb + 48);
	return (len);
}
