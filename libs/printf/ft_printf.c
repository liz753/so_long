/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:08:49 by lfrank            #+#    #+#             */
/*   Updated: 2022/11/10 19:28:45 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_search_arg(va_list ap, const char format)
{
	if (format == 'c')
		return (ft_printchar(va_arg(ap, int)));
	if (format == 's')
		return (ft_printstr(va_arg(ap, char *)));
	if (format == 'i' || format == 'd')
		return (ft_printnbr(va_arg(ap, int)));
	if (format == 'u')
		return (ft_printnbr_u(va_arg(ap, unsigned int)));
	if (format == 'x')
		return (ft_printhex(va_arg(ap, unsigned int), 0));
	if (format == 'X')
		return (ft_printhex(va_arg(ap, unsigned int), 1));
	if (format == 'p')
		return (ft_printpointer(va_arg(ap, uintptr_t)));
	if (format == '%')
		return (ft_printchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		totallen;

	i = 0;
	totallen = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			totallen += ft_search_arg(ap, format[i + 1]);
			i++;
		}
		else
			totallen += ft_printchar(format[i]);
		i++;
	}
	va_end(ap);
	return (totallen);
}
